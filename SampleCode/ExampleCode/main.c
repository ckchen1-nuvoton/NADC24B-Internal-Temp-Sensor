/******************************************************************************
 * @file     main.c
 * @version  V1.00
 * @brief    This sample code is used to read the NADC28B's internal temperature
 * 					 sensor. It allows certain applications to do temperature compensation 
 *					 or display the ambient temperature.
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2023 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "NuMicro.h"
#include "NADC24B_Driver.h"
#include "arm_math.h"

/*---------------------------------------------------------------------------------------------------------*/
/* Define                                                                                                  */
/*---------------------------------------------------------------------------------------------------------*/
#define TEMP_CH     							0x90
#define PGA_GAIN									0x01

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
static uint32_t u32AdcData = 0;
static int32_t  s32AdcData = 0;

typedef struct 
{		 
		uint8_t   Tmep_CD1;
		uint8_t   Tmep_CD2;
		uint8_t   Tmep_CD3;
		uint32_t  Temp_DTB;
}TEMP_STRUCT;

TEMP_STRUCT TEMP_S    = {0};

/*---------------------------------------------------------------------------------------------------------*/
/* Functions                                                                                               */
/*---------------------------------------------------------------------------------------------------------*/

/* Read Temperature Data from Flash */
void Read_Temp_Data(void)
{
		/* Temperature Data*/
		TEMP_S.Tmep_CD1 = SPI_ReadReg_Bank1(REG_ADDR_ADC_TEMP_SENSOR_CAL1);
		TEMP_S.Tmep_CD2 = SPI_ReadReg_Bank1(REG_ADDR_ADC_TEMP_SENSOR_CAL2);
		TEMP_S.Tmep_CD3 = SPI_ReadReg_Bank1(REG_ADDR_ADC_TEMP_SENSOR_CAL3);		
		TEMP_S.Temp_DTB = (TEMP_S.Tmep_CD3 << 16) | (TEMP_S.Tmep_CD2 << 8) | TEMP_S.Tmep_CD1;
		//printf("\tTemperature_DTB = %d\n", TEMP_S.Temp_DTB);
}

/* Temperature Calculation */
float32_t Temp_Calc_Form(int32_t Temp_Data, int32_t PGA_gain)
{
		float32_t Temp_f32;
		int32_t Temp_Diff_s32;

		Temp_Diff_s32 = (Temp_Data / PGA_gain) - TEMP_S.Temp_DTB;
		//Temp_f32 = (float32_t)Temp_Diff_s32 / ((float32_t)TEMP_S.Temp_DTB / (float32_t)(273+25)) + (float32_t)25.0;		
		Temp_f32 = (float32_t)Temp_Diff_s32 / 604.0 + 25.0;
	
		return Temp_f32;
}

void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Enable HIRC clock */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Waiting for HIRC clock ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);

    /* Select HCLK clock source as HIRC and and HCLK clock divider as 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));

    /* Set both PCLK0 and PCLK1 as HCLK */
    CLK->PCLKDIV = CLK_PCLKDIV_APB0DIV_DIV1 | CLK_PCLKDIV_APB1DIV_DIV1;

    /* Select UART module clock source as HIRC and UART module clock divider as 1 */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART0SEL_HIRC, CLK_CLKDIV0_UART0(1));

    /* Select PCLK0 as the clock source of SPI0 */
    CLK_SetModuleClock(SPI0_MODULE, CLK_CLKSEL2_SPI0SEL_PCLK1, MODULE_NoMsk);

    /* Enable UART peripheral clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Enable SPI0 peripheral clock */
    CLK_EnableModuleClock(SPI0_MODULE);
		
		/* Enable PA peripheral clock */
		CLK_EnableModuleClock(GPA_MODULE);

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Set GPA multi-function pins for UART0 RXD and TXD */
    SYS->GPB_MFPH = (SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB12MFP_Msk) | SYS_GPB_MFPH_PB12MFP_UART0_RXD;
    SYS->GPB_MFPH = (SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB13MFP_Msk) | SYS_GPB_MFPH_PB13MFP_UART0_TXD;

    /* Setup SPI0 multi-function pins */
    SYS->GPA_MFPL &= ~(SYS_GPA_MFPL_PA0MFP_Msk | SYS_GPA_MFPL_PA1MFP_Msk | SYS_GPA_MFPL_PA2MFP_Msk | SYS_GPA_MFPL_PA3MFP_Msk);
    SYS->GPA_MFPL |= SYS_GPA_MFPL_PA0MFP_SPI0_MOSI | SYS_GPA_MFPL_PA1MFP_SPI0_MISO | SYS_GPA_MFPL_PA2MFP_SPI0_CLK | SYS_GPA_MFPL_PA3MFP_SPI0_SS ;
		
    /* NADC24 Ready Pin  */
    GPIO_SetMode(PA, BIT4, GPIO_MODE_INPUT);

    /* Enable SPI0 clock pin (PA2) schmitt trigger */
    PA->SMTEN |= GPIO_SMTEN_SMTEN2_Msk;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock and CyclesPerUs automatically. */
    SystemCoreClockUpdate();
}

void SPI_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init SPI                                                                                                */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Configure as a master, clock idle low, 8-bit transaction, drive output on falling clock edge and latch input on rising edge. */
    /* Set IP clock divider. SPI clock rate = 10MHz */
    SPI_Open(SPI0, SPI_MASTER, SPI_MODE_0, 8, 10000000);
}

void GPA_IRQHandler(void)
{
    uint32_t i;
		float f32_volt;
		float f32_temp;
	
    /* To check if PA.4 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PA, BIT4))
    {
        GPIO_CLR_INT_FLAG(PA, BIT4);
						
        /* Read Current value */
        u32AdcData = SPI_SetChannel_and_ReadADCData(TEMP_CH);
        if (u32AdcData & 0x800000)
            u32AdcData += 0xFF000000;
        s32AdcData = (int32_t)u32AdcData;
				f32_temp = Temp_Calc_Form(s32AdcData, PGA_GAIN);
				printf("Temp (degC) : %.2f\n", f32_temp);				
    }
}

/*---------------------------------------------------------------------------------------------------------*/
/* Main function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int main(void)
{
	
		uint8_t i, u8RegVal;
	
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Init System, IP clock and multi-function I/O. */
    SYS_Init();

    /* Configure UART0: 115200, 8-bit word, no parity bit, 1 stop bit. */
    UART_Open(UART0, 115200);

    /* Init SPI */
    SPI_Init();

    /* Initial NADC24B */
		Reset_NADC24B();
    NADC24B_Cali_and_Initial();

		/* Temperature */
		Read_Temp_Data();
		
    /* IO Interrupt */
    GPIO_EnableInt(PA, 4, GPIO_INT_FALLING);
    NVIC_EnableIRQ(GPA_IRQn);

    /* Print */
    printf("This example for NK-NADC24B.\n");
    printf("CPU @ %d Hz\n\n", SystemCoreClock);
		
    while (1)
    {
        
    }
}

/*** (C) COPYRIGHT 2023 Nuvoton Technology Corp. ***/

