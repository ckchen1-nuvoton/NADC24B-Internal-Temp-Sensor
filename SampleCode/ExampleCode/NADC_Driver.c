/******************************************************************************
 * @file     NADC_Driver.c
 * @version  V1.00
 * @brief    To drive the NADC24B analog-to-digital converter by using SPI interface.
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2023 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NuMicro.h"
#include "NADC_Driver.h"

/*---------------------------------------------------------------------------------------------------------*/
/* Functions                                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
/* Delay for 10us */
void delay_10us(uint32_t nDelay)
{
    uint32_t nIndex;

    for (nIndex = 0; nIndex < nDelay; nIndex++)
    {
        CLK_SysTickDelay(10);
    }
}

/* Delay for 1ms */
void delay_1ms(uint32_t nDelay)
{
    uint32_t nIndex;

    for (nIndex = 0; nIndex < nDelay; nIndex++)
    {
        CLK_SysTickDelay(1000);
    }
}

uint8_t SPI_WriteReg_Bank1_Until_Success(uint8_t u8RegAddr, uint8_t u8WriteData)
{
    /* Keep writing until readback matches target data */
    while (SPI_ReadReg_Bank1(u8RegAddr) != u8WriteData)
    {
        SPI_WriteReg_Bank1(u8RegAddr, u8WriteData);
    }
		
    return 0;
}

uint8_t Reset_NADC24B(void)
{
    uint8_t u8RegVal;

    /* Unlock registers and power up required blocks */
    SPI_WriteReg_Bank2(REG_ADDR_PROTECT_KEY, 0x53);
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_PWD_CTRL2, 0x00);
	
    /* Verify Chip ID (Expect 0xDB) */
    if ((u8RegVal = SPI_ReadReg_Bank1(REG_ADDR_ADC_VER_ID)) != 0xDB)
    {
        printf("ID Mismatch: 0x%X\n", u8RegVal);
        return -1;
    }

    /* Execute Software Reset */
    SPI_Send_ADC_Commnad(ADC_RESET_CMD);
		delay_1ms(10);
		SPI_Send_ADC_Commnad(ADC_WAKE_UP_CMD);
		delay_1ms(10);
		
    /* Post-reset: Re-unlock and power up blocks */
    SPI_WriteReg_Bank2(REG_ADDR_PROTECT_KEY, 0x53);
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_PWD_CTRL2, 0x00);

    /* Enable Chopping */
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_CHOP_CTRL, 0x04);

    /* Lock registers */
    SPI_WriteReg_Bank2(REG_ADDR_PROTECT_KEY, 0xCA);
		
    return 0;
}

uint8_t NADC24B_Cali_and_Initial(void)
{
    int32_t i;
    volatile uint8_t u8RegVal;
    int32_t s32AdcDataSum, s32CalibData;
    uint32_t u32AdcData;

		// =============================================================================
		//  Initial Register
		// =============================================================================
	
		/* Unlock register protection */
    SPI_WriteReg_Bank2(REG_ADDR_PROTECT_KEY, 0x53);	

    /* Power down DAC and DAC buffer */
    u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_PWD_CTRL1) & ~(PWD_CTRL1_PWD_DAC_Msk | PWD_CTRL1_PWD_DACBUF_Msk)) |
               (PWD_CTRL1_PWD_DAC_POWER_DOWN | PWD_CTRL1_PWD_DACBUF_POWER_DOWN);
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_PWD_CTRL1, u8RegVal);

    /* Power down PGA buffer and Modulator REFP buffer */
    //u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_PWD_CTRL2) & ~(PWD_CTRL2_PWD_MOD_REFP_Msk | PWD_CTRL2_PWD_PGA_BUFF_Msk)) |
    //           (PWD_CTRL2_PWD_MOD_REFP_POWER_DOWN | PWD_CTRL2_PWD_PGA_BUFF_POWER_DOWN);
    //SPI_WriteReg_Bank1_Until_Success(REG_ADDR_PWD_CTRL2, u8RegVal);
		
		/* Configure DF1 : OSR=65536, Bypass IIR, Gain=1X */
    u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_DF_CTRL1) & ~(DF_CTRL1_OSR_SEL_Msk | DF_CTRL1_BYPASS_IIR_Msk | DF_CTRL1_DF_GAIN_Msk)) |
               (DF_CTRL1_OSR_65536 | DF_CTRL1_BYPASS_IIR_ON | DF_CTRL1_DF_GAIN_1X);
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_DF_CTRL1, u8RegVal);
		
		/* Disable Average Filter (1/8) and Adaptive mode */
    u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_DF_CTRL2) & ~(DF_CTRL2_AVG_ADAP_EN_Msk | DF_CTRL2_AVG_FILT_EN_Msk | DF_CTRL2_AVG_FILT_SET_Msk | DF_CTRL2_LOW_LAT_EN_Msk)) |
               (DF_CTRL2_AVG_ADAP_DIS | DF_CTRL2_AVG_FILT_DIS | DF_CTRL2_AVG_FILT_1_32 | DF_CTRL2_LOW_LAT_DIS );
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_DF_CTRL2, u8RegVal);
		
		/* Set ADC CLK to 1.024MHz and Settling Time to 0 */
    u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_ADC_CTRL) & ~(ADC_CTRL_ADC_CLK_SET_Msk | ADC_CTRL_SETLSEL_Msk)) |
               (ADC_CTRL_ADC_CLK_1_024M | ADC_CTRL_SETLSEL_VALID);
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_ADC_CTRL, u8RegVal);
		
		/* Set PGA Bias to 1X */
    u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_BIAS_CTRL1) & ~BIAS_CTRL1_PGA_BIAS_SET_Msk) | (BIAS_CTRL1_PGA_BIAS_SET_1X);
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_BIAS_CTRL1, u8RegVal);
		
		/* Set ADC OP and Circuit Bias to 1X */
    u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_BIAS_CTRL2) & ~(BIAS_CTRL2_ADC_OP2_BIAS_SET_Msk | BIAS_CTRL2_ADC_OP1_BIAS_SET_Msk | BIAS_CTRL2_ADC_BIAS_SET_Msk)) |
               (BIAS_CTRL2_ADC_OP2_BIAS_SET_1X) | (BIAS_CTRL2_ADC_OP1_BIAS_SET_1X) | (BIAS_CTRL2_ADC_BIAS_SET_1X);
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_BIAS_CTRL2, u8RegVal);	
		
		/* Disable Chip and Modulator Ref PN Chop */
		u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_CHOP_CTRL) & ~(CHOP_CTRL_DIS_CHIP_CHOP_Msk | CHOP_CTRL_DIS_MOD_REFPN_CHOP_Msk)) |
               (CHOP_CTRL_DIS_CHIP_CHOP_DISABLE | CHOP_CTRL_DIS_MOD_REFPN_CHOP_DISABLE);
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_CHOP_CTRL, u8RegVal);
		
    /* Set Internal OSC to 8.192MHz */
    u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_OSC_CTRL2) & ~(OSC_CTRL2_SEL_INT_OSC_Msk | OSC_CTRL2_OSC_BIAS_Msk | OSC_CTRL2_SEL_INT_OSC_F_Msk)) |
               (OSC_CTRL2_SEL_INT_OSC_INTERNAL | OSC_CTRL2_OSC_BIAS_1X | OSC_CTRL2_SEL_INT_OSC_F_8_192MHz);
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_OSC_CTRL2, u8RegVal);
		
		/* Set Internal VREF to 2.4V with Med-High drive */
    u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_REF_CTRL) & ~(VREF_CTRL_SEL_24V_INT_REF_Msk | VREF_CTRL_SEL_INT_REF_DRV_Msk)) |
               (VREF_CTRL_SEL_24V_INT_REF_2_4V | VREF_CTRL_SEL_INT_REF_DRV_MED_HIGH);
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_REF_CTRL, u8RegVal);
				
		/* Set PGA Gain 1X, Buffer 1X, and disable offset calib during measurement */
		u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_PGA_CTRL3) & ~(PGA_CTRL3_PGA_GAIN_Msk | PGA_CTRL3_PGA_BUF_GAIN_Msk | PGA_CTRL3_PGA_BUF_BYPASS_Msk | PGA_CTRL3_PGA_BUF_AUTO_EN_Msk | PGA_CTRL3_OFFSETDIS_Msk)) |
							 (PGA_CTRL3_PGA_GAIN_1X | PGA_CTRL3_PGA_BUF_GAIN_1X | PGA_CTRL3_PGA_BUF_USE | PGA_CTRL3_PGA_BUF_AUTO | PGA_CTRL3_OFFSET_CAL_DIS);
		SPI_WriteReg_Bank1_Until_Success(REG_ADDR_PGA_CTRL3, u8RegVal);
	
		/* Disable PGA chop mux and set buffer bias current to maximum (8x) */
		u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_PGA_CTRL5) & ~(PGA_CTRL5_PGA_BUFF_BIAS_SET_Msk | PGA_CTRL5_DIS_PGA_CHOP_MUX_Msk)) |
               (PGA_CTRL5_PGA_BUFF_BIAS_SET_8X | PGA_CTRL5_DIS_PGA_CHOP_MUX_DISABLE);
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_PGA_CTRL5, u8RegVal);

		/* Select internal Table 2 as the chopping clock source */
    u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_PGA_CTRL6) & ~(PGA_CTRL6_CHOP_CLK_CTRL_Msk )) | (PGA_CTRL6_CHOP_CLK_CTRL_TABLE2 );
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_PGA_CTRL6, u8RegVal);

		/* Lock register protection */
    SPI_WriteReg_Bank2(REG_ADDR_PROTECT_KEY, 0xCA);
		
		delay_1ms(10);
			
	
		// =============================================================================
		//  Calibration Mode
		// =============================================================================
		
		/* Short inputs to VCM for offset measurement */
		u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_PGA_CTRL1) & ~(PGA_CTRL1_SEL_PGA_INP_Msk | PGA_CTRL1_SEL_PGA_INN_Msk)) |
							 (PGA_CTRL1_SEL_PGA_INP_VCM | PGA_CTRL1_SEL_PGA_INN_VCM);
		SPI_WriteReg_Bank1_Until_Success(REG_ADDR_PGA_CTRL1, u8RegVal);

		/* Average 8 samples for pre-calibration check */
		SPI_Send_ADC_Commnad(ADC_START_CONVERSION_CMD);
		
		s32AdcDataSum = 0;
		for (i = 0; i < 8; i++)
		{
				while (nDRDY == 1);
				u32AdcData = SPI_ReadADCDataWithReadCMD();

				/* Sign extend 24-bit to 32-bit */
				if (u32AdcData & 0x800000)
						u32AdcData += 0xFF000000;

				s32AdcDataSum += (int32_t)u32AdcData;
		}
		s32CalibData = s32AdcDataSum / 8;
		if(DEBUG_ENABLE) printf("     Before Calibration : %d\n", s32CalibData);
		
		SPI_Send_ADC_Commnad(ADC_STOP_CONVERSION_CMD);

		/* Apply offset compensation to registers (Byte 0-2) */		
		SPI_WriteReg_Bank1_Until_Success(REG_ADDR_ADC_OFFSET_CAL1, (uint8_t)(s32CalibData >> 0));
		SPI_WriteReg_Bank1_Until_Success(REG_ADDR_ADC_OFFSET_CAL2, (uint8_t)(s32CalibData >> 8));
		SPI_WriteReg_Bank1_Until_Success(REG_ADDR_ADC_OFFSET_CAL3, (uint8_t)(s32CalibData >> 16));
		
		/* Enable offset calibration */
		u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_PGA_CTRL3) & ~PGA_CTRL3_OFFSETDIS_Msk) | (PGA_CTRL3_OFFSET_CAL_EN);
    SPI_WriteReg_Bank1_Until_Success(REG_ADDR_PGA_CTRL3, u8RegVal);

		/* Average 8 samples for post-calibration verification */
		SPI_Send_ADC_Commnad(ADC_START_CONVERSION_CMD);
		
		s32AdcDataSum = 0;
		for (i = 0; i < 8; i++)
		{
				while (nDRDY == 1);
				u32AdcData = SPI_ReadADCDataWithReadCMD();

				if (u32AdcData & 0x800000)
						u32AdcData += 0xFF000000;

				s32AdcDataSum += (int32_t)u32AdcData;
		}
		s32CalibData = s32AdcDataSum / 8;
		if(DEBUG_ENABLE) printf("      After Calibration : %d\n", s32CalibData);
		
		SPI_Send_ADC_Commnad(ADC_STOP_CONVERSION_CMD);


		// =============================================================================
		//  Normal Initialization Mode
		// =============================================================================
		
		/* Select Input: CH1 (P) and CH0 (N) */
		u8RegVal = (SPI_ReadReg_Bank1(REG_ADDR_PGA_CTRL1) & ~(PGA_CTRL1_SEL_PGA_INP_Msk | PGA_CTRL1_SEL_PGA_INN_Msk)) |
							 (PGA_CTRL1_SEL_PGA_INP_ADC_CH1 | PGA_CTRL1_SEL_PGA_INN_ADC_CH0);
		SPI_WriteReg_Bank1_Until_Success(REG_ADDR_PGA_CTRL1, u8RegVal);
		
		return 0;
}


uint8_t SPI_TransferByte(uint8_t u8data)
{
    while (SPI_GET_TX_FIFO_FULL_FLAG(SPI_PORT));
    SPI_WRITE_TX(SPI_PORT, u8data);

    while (SPI_IS_BUSY(SPI_PORT));
    return SPI_READ_RX(SPI_PORT);
}

void SPI_WriteReg_Bank1(uint8_t u8RegAddr, uint8_t u8WriteData)
{
    uint8_t u8AdcCmd = ((u8RegAddr & 0x1F) | 0x60);

    SPI_SET_SS_LOW(SPI_PORT);

    SPI_TransferByte(u8AdcCmd);
    SPI_TransferByte(0x00);	// Write Num Reg (1-1=0)
    SPI_TransferByte(u8WriteData);

    SPI_SET_SS_HIGH(SPI_PORT);
}

void SPI_WriteReg_Bank2(uint8_t u8RegAddr, uint8_t u8WriteData)
{
    uint8_t u8AdcCmd = ((u8RegAddr & 0x1F) | 0xE0);

    SPI_SET_SS_LOW(SPI_PORT);

    SPI_TransferByte(u8AdcCmd);
    SPI_TransferByte(0x00);	// Write Num Reg (1-1=0)
    SPI_TransferByte(u8WriteData);

    SPI_SET_SS_HIGH(SPI_PORT);
}

uint8_t SPI_ReadReg_Bank1(uint8_t u8RegAddr)
{
    uint8_t u8ReadValue = 0;
    uint8_t u8AdcCmd = ((u8RegAddr & 0x1F) | 0x40);

    SPI_SET_SS_LOW(SPI_PORT);

    SPI_TransferByte(u8AdcCmd);
    SPI_TransferByte(0x00);	// Write Num Reg (1-1=0)
    u8ReadValue = SPI_TransferByte(0x0);

    SPI_SET_SS_HIGH(SPI_PORT);

    return (u8ReadValue & 0xFF);
}

uint8_t SPI_ReadReg_Bank2(uint8_t u8RegAddr)
{
    uint8_t u8ReadValue = 0;
    uint8_t u8AdcCmd = ((u8RegAddr & 0x1F) | 0xC0);

    SPI_SET_SS_LOW(SPI_PORT);

    SPI_TransferByte(u8AdcCmd);
    SPI_TransferByte(0x00);	// Write Num Reg (1-1=0)
    u8ReadValue = SPI_TransferByte(0x0);

    SPI_SET_SS_HIGH(SPI_PORT);

    return (u8ReadValue & 0xFF);
}

uint32_t SPI_ReadADCDataWithReadCMD(void)
{
    uint32_t u32AdcValue = 0;

    SPI_SET_SS_LOW(SPI_PORT);

    SPI_TransferByte(ADC_READ_DATA_CMD);

    SPI_PORT->CTL &= (~SPI_CTL_DWIDTH_Msk);
    SPI_PORT->CTL |= (24 << SPI_CTL_DWIDTH_Pos);

    /* receive 24-bit */
    SPI_WRITE_TX(SPI_PORT, (uint32_t)0x00000000);

    while (SPI_IS_BUSY(SPI_PORT));

    u32AdcValue = SPI_READ_RX(SPI_PORT);

    SPI_SET_SS_HIGH(SPI_PORT);

    SPI_PORT->CTL &= (~SPI_CTL_DWIDTH_Msk);
    SPI_PORT->CTL |= (8 << SPI_CTL_DWIDTH_Pos);

    return u32AdcValue;
}

uint32_t SPI_SetChannel_and_ReadADCData(uint8_t u8Channel)
{
    uint32_t u32AdcValue = 0;

    SPI_SET_SS_LOW(SPI_PORT);

    SPI_TransferByte(REG_ADDR_PGA_CTRL1 | 0x60);
    SPI_TransferByte(0x00);	// Write Num Reg (1-1=0)
    SPI_TransferByte(u8Channel);

    SPI_TransferByte(ADC_START_CONVERSION_CMD);

    /* Read */
    SPI_PORT->CTL &= (~SPI_CTL_DWIDTH_Msk);
    SPI_PORT->CTL |= (24 << SPI_CTL_DWIDTH_Pos);

    /* receive 24-bit */
    SPI_WRITE_TX(SPI_PORT, (uint32_t)0x00000000);

    while (SPI_IS_BUSY(SPI_PORT));

    u32AdcValue = SPI_READ_RX(SPI_PORT);

    SPI_SET_SS_HIGH(SPI_PORT);

    SPI_PORT->CTL &= (~SPI_CTL_DWIDTH_Msk);
    SPI_PORT->CTL |= (8 << SPI_CTL_DWIDTH_Pos);

    return u32AdcValue;
}

void SPI_Send_ADC_Commnad(uint32_t u32Cmd)
{
    SPI_SET_SS_LOW(SPI_PORT);

    SPI_TransferByte((uint8_t)(u32Cmd & 0xFF));

    SPI_SET_SS_HIGH(SPI_PORT);
}

/*** (C) COPYRIGHT 2023 Nuvoton Technology Corp. ***/