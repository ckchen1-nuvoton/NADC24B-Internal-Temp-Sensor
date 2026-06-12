/**************************************************************************//**
 * @file     NADC_Driver.h
 * @version  V1.00
 * @brief    NADC24B register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2023 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

#ifndef _ADC_REG_TABLE_H_
#define _ADC_REG_TABLE_H_

//------------------------------------------------------------------------------
#include <stdio.h>
#include <stdint.h>

//------------------------------------------------------------------------------
// Use SPIx Port
//------------------------------------------------------------------------------
#define SPI_PORT                                SPI0
#define nDRDY                                   PA4

#define ADOUT_DIG18_2                           PH3
#define ADOUT_DIG18_1                           PH4
#define ADOUT_DIG18_0                           PH5

//------------------------------------------------------------------------------
// ADC Commands
//------------------------------------------------------------------------------
#define ADC_NOP_CMD                             0x00 /* No operation */
#define ADC_WAKE_UP_CMD                         0x02 /* Wake-up from Power-down mode */
#define ADC_POWER_DOWN_CMD                      0x04 /* Enter Power-down mode */
#define ADC_RESET_CMD                           0x06 /* RESET */
#define ADC_START_CONVERSION_CMD                0x08 /* Start ADC conversion */
#define ADC_STOP_CONVERSION_CMD                 0x0A /* Stop  ADC conversion */
#define ADC_SYNC_CONVERSION_CMD                 0x0C /* Sync  ADC conversion */

/* CALIBRATION COMMAND */
#define ADC_SYSOC_CMD                           0x10 /* System offset error calibration */

/* DATA READ COMMAND */
#define ADC_READ_DATA_CMD                       0x20 /* Read ADC data */

/* BANK1 COMMAND  */
#define ADC_BANK1_READ_REG_ADDR_CMD             0x40 /* Read  b000nnnnn registers from address b010aaaaa */
#define ADC_BANK1_READ_REG_LEN_CMD              0x1F /* Read  b000nnnnn registers from address b010aaaaa */
#define ADC_BANK1_WRITE_REG_ADDR_CMD            0x60 /* Write b000nnnnn registers from address b011aaaaa */
#define ADC_BANK1_WRITE_REG_LEN_CMD             0x1F /* Write b000nnnnn registers from address b011aaaaa */

/* BANK2 COMMAND  */
#define ADC_BANK2_READ_REG_ADDR_CMD             0xC0 /* Read  b000nnnnn registers from address b110aaaaa */
#define ADC_BANK2_READ_REG_LEN_CMD              0x1F /* Read  b000nnnnn registers from address b110aaaaa */
#define ADC_BANK2_WRITE_REG_ADDR_CMD            0xE0 /* Write b000nnnnn registers from address b111aaaaa */
#define ADC_BANK2_WRITE_REG_LEN_CMD             0x1F /* Write b000nnnnn registers from address b111aaaaa */

/* IIR COEFFICIENT COMMAND  */
#define ADC_IIR_COEFFICIENT_READ_REG_ADDR_CMD   0x80 /* Read  b000nnnnn registers from address b100aaaaa */
#define ADC_IIR_COEFFICIENT_WRITE_REG_ADDR_CMD  0xA0 /* Write b000nnnnn registers from address b101aaaaa */


//------------------------------------------------------------------------------
// ADC register
//------------------------------------------------------------------------------
/* BANK1 REGISTER  */
#define REG_ADDR_PWD_CTRL1                      0x00 /* Power Down Control 1 */
#define REG_ADDR_PWD_CTRL2                      0x01 /* Power Down Control 2 */
#define REG_ADDR_PWD_CTRL3                      0x02 /* Power Down Control 3 */
#define REG_ADDR_DF_CTRL1                       0x03 /* Digital Filter Control 1 */
#define REG_ADDR_DF_CTRL2                       0x04 /* Digital Filter Control 2 */
#define REG_ADDR_DF_CTRL3                       0x05 /* Digital Filter Control 3 */
#define REG_ADDR_DF_CTRL4                       0x06 /* Digital Filter Control 4 */
#define REG_ADDR_ADC_CTRL                       0x07 /* ADC Control Register */
#define REG_ADDR_BIAS_CTRL1                     0x08 /* Bias Control 1 Register */
#define REG_ADDR_BIAS_CTRL2                     0x09 /* Bias Control 2 Register */
#define REG_ADDR_CHOP_CTRL                      0x0A /* Chop Control Register */
#define REG_ADDR_BG_CTRL1                       0x0B /* Band-gap Control 1 */
#define REG_ADDR_BG_CTRL2                       0x0C /* Band-gap Control 2 */
#define REG_ADDR_OSC_CTRL1                      0x0D /* Internal Oscillator Control Register 1 */
#define REG_ADDR_OSC_CTRL2                      0x0E /* Internal Oscillator Control Register 2 */
#define REG_ADDR_OSC_CTRL3                    	0x0F /* Internal Oscillator Control Register 3 */
#define REG_ADDR_REF_CTRL                       0x10 /* Reference Voltage Control Register */
#define REG_ADDR_PGA_CTRL1                      0x11 /* PGA Control Register 1 */
#define REG_ADDR_PGA_CTRL2                      0x12 /* PGA Control Register 2 */
#define REG_ADDR_PGA_CTRL3                      0x13 /* PGA Control Register 1 */
#define REG_ADDR_PGA_CTRL4                      0x14 /* PGA Control Register 2 */
#define REG_ADDR_PGA_CTRL5                      0x15 /* PGA Control Register 1 */
#define REG_ADDR_PGA_CTRL6                      0x16 /* PGA Control Register 2 */
#define REG_ADDR_ADC_OFFSET_CAL1                0x17 /* ADC Offset Calibration Data Register 1 */
#define REG_ADDR_ADC_OFFSET_CAL2                0x18 /* ADC Offset Calibration Data Register 2 */
#define REG_ADDR_ADC_OFFSET_CAL3                0x19 /* ADC Offset Calibration Data Register 3 */
#define REG_ADDR_ADC_TEMP_SENSOR_CAL1           0x1A /* Temperature Sensor Calibration Data Register 1 */
#define REG_ADDR_ADC_TEMP_SENSOR_CAL2           0x1B /* Temperature Sensor Calibration Data Register 2 */
#define REG_ADDR_ADC_TEMP_SENSOR_CAL3           0x1C /* Temperature Sensor Calibration Data Register 3 */
#define REG_ADDR_ADC_STATUS                     0x1D /* Status Register */
#define REG_ADDR_MISC_CTRL                      0x1E /* OTP Data Input Register */
#define REG_ADDR_ADC_VER_ID                     0x1F /* Device ID Register */

/* BANK2 REGISTER  */
#define REG_ADDR_DAC_DATA1                      0x00 /* DAC Data Register 1 */
#define REG_ADDR_DAC_DATA2                      0x01 /* DAC Data Register 2 */
#define REG_ADDR_DAC_CTRL                       0x02 /* DAC Control Register */
#define REG_ADDR_ADC_GAIN_CAL_CTRL              0x03 /* ADC Gain Calibration Control Register */
#define REG_ADDR_ADC_GAIN_CAL1              		0x04 /* ADC Gain Calibration 1 LSB data bits[7:0] Register */
#define REG_ADDR_ADC_GAIN_CAL2              		0x05 /* ADC Gain Calibration 2 LSB data bits[7:0] Register */
#define REG_ADDR_ADC_GAIN_CAL3              		0x06 /* ADC Gain Calibration 1/2 MSB data bits Register */
#define REG_ADDR_SYS_CTRL                  			0x07 /* System Control Register */
#define REG_ADDR_CHIP_CHOP_CTRL            			0x08 /* Chip Chop Control Register */

#define REG_ADDR_ADC_OTP_DOUT0                  0x15 /* OTP Data Output Register 0 */
#define REG_ADDR_ADC_OTP_DOUT1                  0x16 /* OTP Data Output Register 1 */
#define REG_ADDR_ADC_OTP_DOUT2                  0x17 /* OTP Data Output Register 2 */
#define REG_ADDR_ADC_OTP_DOUT3                  0x18 /* OTP Data Output Register 3 */
#define REG_ADDR_ADC_OTP_CTRL                   0x19 /* OTP Control Register */
#define REG_ADDR_ADC_OTP_DIN                    0x1A /* OTP Data Input Register */

#define REG_ADDR_PROTECT_KEY                    0x1C /* Protect Key Register */
#define REG_ADDR_STATUS2                    		0x1D /* Status 2 Register    */


// =============================================================================
// PWD_CTRL 1 - Address: 0x00
// =============================================================================

// --- Bit 7: Power Down DAC Buffer Block ---
#define PWD_CTRL1_PWD_DACBUF_Pos            		(7)
#define PWD_CTRL1_PWD_DACBUF_Msk            		(1 << PWD_CTRL1_PWD_DACBUF_Pos)
#define PWD_CTRL1_PWD_DACBUF_POWER_UP       		(0 << PWD_CTRL1_PWD_DACBUF_Pos)
#define PWD_CTRL1_PWD_DACBUF_POWER_DOWN     		(1 << PWD_CTRL1_PWD_DACBUF_Pos)

// --- Bit 6: Power Down DAC Block ---
#define PWD_CTRL1_PWD_DAC_Pos               		(6)
#define PWD_CTRL1_PWD_DAC_Msk               		(1 << PWD_CTRL1_PWD_DAC_Pos)
#define PWD_CTRL1_PWD_DAC_POWER_UP          		(0 << PWD_CTRL1_PWD_DAC_Pos)
#define PWD_CTRL1_PWD_DAC_POWER_DOWN        		(1 << PWD_CTRL1_PWD_DAC_Pos)

// --- Bit 5: Power Down Internal Oscillation Block ---
#define PWD_CTRL1_PWD_OSC_Pos               		(5)
#define PWD_CTRL1_PWD_OSC_Msk               		(1 << PWD_CTRL1_PWD_OSC_Pos)
#define PWD_CTRL1_PWD_OSC_POWER_UP          		(0 << PWD_CTRL1_PWD_OSC_Pos)
#define PWD_CTRL1_PWD_OSC_POWER_DOWN        		(1 << PWD_CTRL1_PWD_OSC_Pos)

// --- Bit 4: Power Down VCM Block ---
#define PWD_CTRL1_PWD_VCMGEN_Pos            		(4)
#define PWD_CTRL1_PWD_VCMGEN_Msk            		(1 << PWD_CTRL1_PWD_VCMGEN_Pos)
#define PWD_CTRL1_PWD_VCMGEN_POWER_UP       		(0 << PWD_CTRL1_PWD_VCMGEN_Pos)
#define PWD_CTRL1_PWD_VCMGEN_POWER_DOWN     		(1 << PWD_CTRL1_PWD_VCMGEN_Pos)

// --- Bit 3: Power Down Temperature Sensor Block ---
#define PWD_CTRL1_PWD_TEMPSENSOR_Pos        		(3)
#define PWD_CTRL1_PWD_TEMPSENSOR_Msk        		(1 << PWD_CTRL1_PWD_TEMPSENSOR_Pos)
#define PWD_CTRL1_PWD_TEMPSENSOR_POWER_UP   		(0 << PWD_CTRL1_PWD_TEMPSENSOR_Pos)
#define PWD_CTRL1_PWD_TEMPSENSOR_POWER_DOWN 		(1 << PWD_CTRL1_PWD_TEMPSENSOR_Pos)

// --- Bit 2: Power down Internal Reference Voltage block ---
#define PWD_CTRL1_PWD_ADC_INT_REF_Pos       		(2)
#define PWD_CTRL1_PWD_ADC_INT_REF_Msk       		(1 << PWD_CTRL1_PWD_ADC_INT_REF_Pos)
#define PWD_CTRL1_PWD_ADC_INT_REF_POWER_UP  		(0 << PWD_CTRL1_PWD_ADC_INT_REF_Pos)
#define PWD_CTRL1_PWD_ADC_INT_REF_POWER_DOWN 		(1 << PWD_CTRL1_PWD_ADC_INT_REF_Pos)

// --- Bit 1: Power Down POR18 Block ---
#define PWD_CTRL1_PWD_POR18_Pos             		(1)
#define PWD_CTRL1_PWD_POR18_Msk             		(1 << PWD_CTRL1_PWD_POR18_Pos)
#define PWD_CTRL1_PWD_POR18_POWER_UP        		(0 << PWD_CTRL1_PWD_POR18_Pos)
#define PWD_CTRL1_PWD_POR18_POWER_DOWN      		(1 << PWD_CTRL1_PWD_POR18_Pos)

// --- Bit 0: Power Down POR33 Block ---
#define PWD_CTRL1_PWD_POR33_Pos             		(0)
#define PWD_CTRL1_PWD_POR33_Msk             		(1 << PWD_CTRL1_PWD_POR33_Pos)
#define PWD_CTRL1_PWD_POR33_POWER_UP        		(0 << PWD_CTRL1_PWD_POR33_Pos)
#define PWD_CTRL1_PWD_POR33_POWER_DOWN      		(1 << PWD_CTRL1_PWD_POR33_Pos)

// =============================================================================
// PWD_CTRL 2 - Address: 0x01
// =============================================================================

// --- Bit 7: Whole Chip Power Down ---
#define PWD_CTRL2_PWD_CHIP_Pos              		(7)
#define PWD_CTRL2_PWD_CHIP_Msk              		(1 << PWD_CTRL2_PWD_CHIP_Pos)
#define PWD_CTRL2_PWD_CHIP_POWER_UP         		(0 << PWD_CTRL2_PWD_CHIP_Pos)
#define PWD_CTRL2_PWD_CHIP_POWER_DOWN       		(1 << PWD_CTRL2_PWD_CHIP_Pos)

// --- Bit 6: Power Down Band-Gap Block ---
#define PWD_CTRL2_PWD_BG_Pos                		(6)
#define PWD_CTRL2_PWD_BG_Msk                		(1 << PWD_CTRL2_PWD_BG_Pos)
#define PWD_CTRL2_PWD_BG_POWER_UP           		(0 << PWD_CTRL2_PWD_BG_Pos)
#define PWD_CTRL2_PWD_BG_POWER_DOWN         		(1 << PWD_CTRL2_PWD_BG_Pos)

// --- Bit 5: Power Down LDO18 Block ---
#define PWD_CTRL2_PWD_LDO18_Pos             		(5)
#define PWD_CTRL2_PWD_LDO18_Msk             		(1 << PWD_CTRL2_PWD_LDO18_Pos)
#define PWD_CTRL2_PWD_LDO18_POWER_UP        		(0 << PWD_CTRL2_PWD_LDO18_Pos)
#define PWD_CTRL2_PWD_LDO18_POWER_DOWN      		(1 << PWD_CTRL2_PWD_LDO18_Pos)

// --- Bit 4: Power down Modulator block ---
#define PWD_CTRL2_PWD_MOD_Pos               		(4)
#define PWD_CTRL2_PWD_MOD_Msk               		(1 << PWD_CTRL2_PWD_MOD_Pos)
#define PWD_CTRL2_PWD_MOD_POWER_UP          		(0 << PWD_CTRL2_PWD_MOD_Pos)
#define PWD_CTRL2_PWD_MOD_POWER_DOWN        		(1 << PWD_CTRL2_PWD_MOD_Pos)

// --- Bit 3: Power Down PGA Block ---
#define PWD_CTRL2_PWD_PGA_Pos               		(3)
#define PWD_CTRL2_PWD_PGA_Msk               		(1 << PWD_CTRL2_PWD_PGA_Pos)
#define PWD_CTRL2_PWD_PGA_POWER_UP          		(0 << PWD_CTRL2_PWD_PGA_Pos)
#define PWD_CTRL2_PWD_PGA_POWER_DOWN        		(1 << PWD_CTRL2_PWD_PGA_Pos)

// --- Bit 2: Power Down PGA Bandwidth Buffer Block ---
#define PWD_CTRL2_PWD_PGA_BUFF_Pos          		(2)
#define PWD_CTRL2_PWD_PGA_BUFF_Msk          		(1 << PWD_CTRL2_PWD_PGA_BUFF_Pos)
#define PWD_CTRL2_PWD_PGA_BUFF_POWER_UP     		(0 << PWD_CTRL2_PWD_PGA_BUFF_Pos)
#define PWD_CTRL2_PWD_PGA_BUFF_POWER_DOWN   		(1 << PWD_CTRL2_PWD_PGA_BUFF_Pos)

// --- Bit 1: Power Down Modulator REFP Buffer Block ---
#define PWD_CTRL2_PWD_MOD_REFP_Pos          		(1)
#define PWD_CTRL2_PWD_MOD_REFP_Msk          		(1 << PWD_CTRL2_PWD_MOD_REFP_Pos)
#define PWD_CTRL2_PWD_MOD_REFP_POWER_UP     		(0 << PWD_CTRL2_PWD_MOD_REFP_Pos)
#define PWD_CTRL2_PWD_MOD_REFP_POWER_DOWN   		(1 << PWD_CTRL2_PWD_MOD_REFP_Pos)

// --- Bit 0: Power Down Modulator REFN Buffer Block ---
#define PWD_CTRL2_PWD_MOD_REFN_Pos          		(0)
#define PWD_CTRL2_PWD_MOD_REFN_Msk          		(1 << PWD_CTRL2_PWD_MOD_REFN_Pos)
#define PWD_CTRL2_PWD_MOD_REFN_POWER_UP     		(0 << PWD_CTRL2_PWD_MOD_REFN_Pos)
#define PWD_CTRL2_PWD_MOD_REFN_POWER_DOWN   		(1 << PWD_CTRL2_PWD_MOD_REFN_Pos)

// =============================================================================
// DF_CTRL 1 - Address: 0x03
// =============================================================================

// Bit 7:6: Digital Filter Gain Control
#define DF_CTRL1_DF_GAIN_Pos                		(6)
#define DF_CTRL1_DF_GAIN_Msk                		(3 << DF_CTRL1_DF_GAIN_Pos)
#define DF_CTRL1_DF_GAIN_1X                 		(0 << DF_CTRL1_DF_GAIN_Pos) 
#define DF_CTRL1_DF_GAIN_2X                 		(1 << DF_CTRL1_DF_GAIN_Pos)
#define DF_CTRL1_DF_GAIN_4X                 		(2 << DF_CTRL1_DF_GAIN_Pos)
#define DF_CTRL1_DF_GAIN_8X                 		(3 << DF_CTRL1_DF_GAIN_Pos)

// Bit 5: IIR Coefficient Select
#define DF_CTRL1_IIRCOEFS_Pos               		(5)
#define DF_CTRL1_IIRCOEFS_Msk               		(1 << DF_CTRL1_IIRCOEFS_Pos)
#define DF_CTRL1_IIRCOEFS_FIXED             		(0 << DF_CTRL1_IIRCOEFS_Pos)
#define DF_CTRL1_IIRCOEFS_USER              		(1 << DF_CTRL1_IIRCOEFS_Pos)

// Bit 4: Bypass IIR Filter Control
#define DF_CTRL1_BYPASS_IIR_Pos             		(4)
#define DF_CTRL1_BYPASS_IIR_Msk             		(1 << DF_CTRL1_BYPASS_IIR_Pos)
#define DF_CTRL1_BYPASS_IIR_OFF             		(0 << DF_CTRL1_BYPASS_IIR_Pos)
#define DF_CTRL1_BYPASS_IIR_ON              		(1 << DF_CTRL1_BYPASS_IIR_Pos)

// Bit 3:0: Select ADC Filter Oversampling Rate (OSR)
#define DF_CTRL1_OSR_SEL_Pos                		(0)
#define DF_CTRL1_OSR_SEL_Msk                		(0xF << DF_CTRL1_OSR_SEL_Pos)
#define DF_CTRL1_OSR_64                     		(0x0 << DF_CTRL1_OSR_SEL_Pos)
#define DF_CTRL1_OSR_128                    		(0x1 << DF_CTRL1_OSR_SEL_Pos)
#define DF_CTRL1_OSR_256                    		(0x2 << DF_CTRL1_OSR_SEL_Pos)
#define DF_CTRL1_OSR_512                    		(0x3 << DF_CTRL1_OSR_SEL_Pos)
#define DF_CTRL1_OSR_1024                   		(0x4 << DF_CTRL1_OSR_SEL_Pos)
#define DF_CTRL1_OSR_2048                   		(0x5 << DF_CTRL1_OSR_SEL_Pos)
#define DF_CTRL1_OSR_4096                   		(0x6 << DF_CTRL1_OSR_SEL_Pos)
#define DF_CTRL1_OSR_8192                  		 	(0x7 << DF_CTRL1_OSR_SEL_Pos)
#define DF_CTRL1_OSR_16384                 		 	(0x8 << DF_CTRL1_OSR_SEL_Pos)
#define DF_CTRL1_OSR_32768                  		(0x9 << DF_CTRL1_OSR_SEL_Pos)
#define DF_CTRL1_OSR_65536                  		(0xA << DF_CTRL1_OSR_SEL_Pos)
#define DF_CTRL1_OSR_131072                 		(0xB << DF_CTRL1_OSR_SEL_Pos)

// =============================================================================
// DF_CTRL 2 - Address: 0x04
// =============================================================================

// Bit 7:6: Digital Filter Low Latency Time Enable
#define DF_CTRL2_LOW_LAT_EN_Pos             		(6)
#define DF_CTRL2_LOW_LAT_EN_Msk             		(3 << DF_CTRL2_LOW_LAT_EN_Pos)
#define DF_CTRL2_LOW_LAT_DIS                		(0 << DF_CTRL2_LOW_LAT_EN_Pos) 
#define DF_CTRL2_LOW_LAT_MODE1              		(1 << DF_CTRL2_LOW_LAT_EN_Pos)
#define DF_CTRL2_LOW_LAT_MODE2              		(2 << DF_CTRL2_LOW_LAT_EN_Pos)

// Bit 5:4: Extra Average Filter Setting for Low Frequency Signal
#define DF_CTRL2_AVG_FILT_SET_Pos           		(4)
#define DF_CTRL2_AVG_FILT_SET_Msk           		(3 << DF_CTRL2_AVG_FILT_SET_Pos)
#define DF_CTRL2_AVG_FILT_BYPASS            		(0 << DF_CTRL2_AVG_FILT_SET_Pos)
#define DF_CTRL2_AVG_FILT_1_8               		(1 << DF_CTRL2_AVG_FILT_SET_Pos)
#define DF_CTRL2_AVG_FILT_1_32              		(2 << DF_CTRL2_AVG_FILT_SET_Pos) 
#define DF_CTRL2_AVG_FILT_1_128             		(3 << DF_CTRL2_AVG_FILT_SET_Pos)

// Bit 3: Enable Extra Average Filter for Low Frequency Signal
#define DF_CTRL2_AVG_FILT_EN_Pos            		(3)
#define DF_CTRL2_AVG_FILT_EN_Msk            		(1 << DF_CTRL2_AVG_FILT_EN_Pos)
#define DF_CTRL2_AVG_FILT_DIS               		(0 << DF_CTRL2_AVG_FILT_EN_Pos) 
#define DF_CTRL2_AVG_FILT_EN                		(1 << DF_CTRL2_AVG_FILT_EN_Pos)

// Bit 2: Enable of Adaptive Bandwidth Control for the Average Filter
#define DF_CTRL2_AVG_ADAP_EN_Pos            		(2)
#define DF_CTRL2_AVG_ADAP_EN_Msk            		(1 << DF_CTRL2_AVG_ADAP_EN_Pos)
#define DF_CTRL2_AVG_ADAP_DIS               		(0 << DF_CTRL2_AVG_ADAP_EN_Pos) 
#define DF_CTRL2_AVG_ADAP_EN                		(1 << DF_CTRL2_AVG_ADAP_EN_Pos)

// Bit 1:0: Strength of Adaptive Bandwidth Control for the Average Filter
#define DF_CTRL2_AVG_ADAP_SET_Pos           		(0)
#define DF_CTRL2_AVG_ADAP_SET_Msk           		(3 << DF_CTRL2_AVG_ADAP_SET_Pos)
#define DF_CTRL2_AVG_ADAP_STRENGTH_WEAKEST  		(0 << DF_CTRL2_AVG_ADAP_SET_Pos)
#define DF_CTRL2_AVG_ADAP_STRENGTH_LOW      		(1 << DF_CTRL2_AVG_ADAP_SET_Pos)
#define DF_CTRL2_AVG_ADAP_STRENGTH_MEDIUM   		(2 << DF_CTRL2_AVG_ADAP_SET_Pos) 
#define DF_CTRL2_AVG_ADAP_STRENGTH_HIGH     		(3 << DF_CTRL2_AVG_ADAP_SET_Pos)

// =============================================================================
// ADC_CTRL 2 - Address: 0x07
// =============================================================================

// Bit 7:5: ADC Output Sample Settling Time Selection
#define ADC_CTRL_SETLSEL_Pos                		(5)
#define ADC_CTRL_SETLSEL_Msk                		(7 << ADC_CTRL_SETLSEL_Pos)
#define ADC_CTRL_SETLSEL_VALID              		(0 << ADC_CTRL_SETLSEL_Pos) 
#define ADC_CTRL_SETLSEL_WAIVE_1            		(1 << ADC_CTRL_SETLSEL_Pos)
#define ADC_CTRL_SETLSEL_WAIVE_3            		(2 << ADC_CTRL_SETLSEL_Pos) 
#define ADC_CTRL_SETLSEL_WAIVE_5            		(3 << ADC_CTRL_SETLSEL_Pos) 
#define ADC_CTRL_SETLSEL_WAIVE_6            		(4 << ADC_CTRL_SETLSEL_Pos)
#define ADC_CTRL_SETLSEL_WAIVE_7            		(5 << ADC_CTRL_SETLSEL_Pos)
#define ADC_CTRL_SETLSEL_WAIVE_8            		(6 << ADC_CTRL_SETLSEL_Pos)
#define ADC_CTRL_SETLSEL_WAIVE_9            		(7 << ADC_CTRL_SETLSEL_Pos)

// Bit 4:2: Select ADC Modulator Clock (Frequency = 8.192 MHz)
#define ADC_CTRL_ADC_CLK_SET_Pos            		(2)
#define ADC_CTRL_ADC_CLK_SET_Msk            		(7 << ADC_CTRL_ADC_CLK_SET_Pos)
#define ADC_CTRL_ADC_CLK_40_96K             		(0 << ADC_CTRL_ADC_CLK_SET_Pos)
#define ADC_CTRL_ADC_CLK_163_84K            		(1 << ADC_CTRL_ADC_CLK_SET_Pos)
#define ADC_CTRL_ADC_CLK_512K               		(2 << ADC_CTRL_ADC_CLK_SET_Pos)
#define ADC_CTRL_ADC_CLK_1_024M             		(3 << ADC_CTRL_ADC_CLK_SET_Pos) 
#define ADC_CTRL_ADC_CLK_1_365M             		(4 << ADC_CTRL_ADC_CLK_SET_Pos)
#define ADC_CTRL_ADC_CLK_1_638M             		(5 << ADC_CTRL_ADC_CLK_SET_Pos)
#define ADC_CTRL_ADC_CLK_2_048M             		(6 << ADC_CTRL_ADC_CLK_SET_Pos)

// Bit 1:0: Select Modulator Reference P/N Gain Setting
#define ADC_CTRL_MOD_REFPN_GAIN_Pos         		(0)
#define ADC_CTRL_MOD_REFPN_GAIN_Msk         		(3 << ADC_CTRL_MOD_REFPN_GAIN_Pos)
#define ADC_CTRL_MOD_REFPN_GAIN_0_25X       		(0 << ADC_CTRL_MOD_REFPN_GAIN_Pos)
#define ADC_CTRL_MOD_REFPN_GAIN_0_5X        		(1 << ADC_CTRL_MOD_REFPN_GAIN_Pos)
#define ADC_CTRL_MOD_REFPN_GAIN_1X          		(2 << ADC_CTRL_MOD_REFPN_GAIN_Pos) 

// =============================================================================
// BIAS_CTRL 1 - Address: 0x08
// =============================================================================

// Bit 7: Set 1.8V LDO Bias Current
#define BIAS_CTRL1_LDO_BIAS_SET_Pos         		(7)
#define BIAS_CTRL1_LDO_BIAS_SET_Msk         		(1 << BIAS_CTRL1_LDO_BIAS_SET_Pos)
#define BIAS_CTRL1_LDO_BIAS_SET_0_5X        		(0 << BIAS_CTRL1_LDO_BIAS_SET_Pos)
#define BIAS_CTRL1_LDO_BIAS_SET_1X          		(1 << BIAS_CTRL1_LDO_BIAS_SET_Pos) 

// Bit 6: Set VCM Block Bias Current
#define BIAS_CTRL1_VCM_BIAS_SET_Pos         		(6)
#define BIAS_CTRL1_VCM_BIAS_SET_Msk         		(1 << BIAS_CTRL1_VCM_BIAS_SET_Pos)
#define BIAS_CTRL1_VCM_BIAS_SET_0_5X        		(0 << BIAS_CTRL1_VCM_BIAS_SET_Pos)
#define BIAS_CTRL1_VCM_BIAS_SET_1X          		(1 << BIAS_CTRL1_VCM_BIAS_SET_Pos) 

// Bit 5: Set Modulator Reference P Block Bias Current
#define BIAS_CTRL1_MOD_REFP_BIAS_SET_Pos    		(5)
#define BIAS_CTRL1_MOD_REFP_BIAS_SET_Msk    		(1 << BIAS_CTRL1_MOD_REFP_BIAS_SET_Pos)
#define BIAS_CTRL1_MOD_REFP_BIAS_SET_0_5X   		(0 << BIAS_CTRL1_MOD_REFP_BIAS_SET_Pos)
#define BIAS_CTRL1_MOD_REFP_BIAS_SET_1X     		(1 << BIAS_CTRL1_MOD_REFP_BIAS_SET_Pos) 

// Bit 4: Set Modulator Reference N Block Bias Current
#define BIAS_CTRL1_MOD_REFN_BIAS_SET_Pos    		(4)
#define BIAS_CTRL1_MOD_REFN_BIAS_SET_Msk    		(1 << BIAS_CTRL1_MOD_REFN_BIAS_SET_Pos)
#define BIAS_CTRL1_MOD_REFN_BIAS_SET_0_5X   		(0 << BIAS_CTRL1_MOD_REFN_BIAS_SET_Pos)
#define BIAS_CTRL1_MOD_REFN_BIAS_SET_1X     		(1 << BIAS_CTRL1_MOD_REFN_BIAS_SET_Pos) 

// Bit 3: Set DAC Reference Buffer Block Bias Current
#define BIAS_CTRL1_DAC_REF_BIAS_SET_Pos     		(3)
#define BIAS_CTRL1_DAC_REF_BIAS_SET_Msk     		(1 << BIAS_CTRL1_DAC_REF_BIAS_SET_Pos)
#define BIAS_CTRL1_DAC_REF_BIAS_SET_0_5X    		(0 << BIAS_CTRL1_DAC_REF_BIAS_SET_Pos)
#define BIAS_CTRL1_DAC_REF_BIAS_SET_1X      		(1 << BIAS_CTRL1_DAC_REF_BIAS_SET_Pos) 

// Bit 2: Set 1.2V/2.4V Reference Buffer Block Bias Current
#define BIAS_CTRL1_REF_BIAS_SET_Pos         		(2)
#define BIAS_CTRL1_REF_BIAS_SET_Msk         		(1 << BIAS_CTRL1_REF_BIAS_SET_Pos)
#define BIAS_CTRL1_REF_BIAS_SET_0_5X        		(0 << BIAS_CTRL1_REF_BIAS_SET_Pos)
#define BIAS_CTRL1_REF_BIAS_SET_1X          		(1 << BIAS_CTRL1_REF_BIAS_SET_Pos) 

// Bit 1:0: Set PGA Bias Current
#define BIAS_CTRL1_PGA_BIAS_SET_Pos         		(0)
#define BIAS_CTRL1_PGA_BIAS_SET_Msk         		(3 << BIAS_CTRL1_PGA_BIAS_SET_Pos)
#define BIAS_CTRL1_PGA_BIAS_SET_0_5X        		(0 << BIAS_CTRL1_PGA_BIAS_SET_Pos)
#define BIAS_CTRL1_PGA_BIAS_SET_1X          		(1 << BIAS_CTRL1_PGA_BIAS_SET_Pos) 
#define BIAS_CTRL1_PGA_BIAS_SET_2X          		(2 << BIAS_CTRL1_PGA_BIAS_SET_Pos)
#define BIAS_CTRL1_PGA_BIAS_SET_3X          		(3 << BIAS_CTRL1_PGA_BIAS_SET_Pos)

// =============================================================================
// BIAS_CTRL 2 - Address: 0x09
// =============================================================================

// Bit 5:4: Set ADC Modulator Whole Bias Current
#define BIAS_CTRL2_ADC_BIAS_SET_Pos         		(4)
#define BIAS_CTRL2_ADC_BIAS_SET_Msk         		(3 << BIAS_CTRL2_ADC_BIAS_SET_Pos)
#define BIAS_CTRL2_ADC_BIAS_SET_0_5X        		(0 << BIAS_CTRL2_ADC_BIAS_SET_Pos)
#define BIAS_CTRL2_ADC_BIAS_SET_1X          		(1 << BIAS_CTRL2_ADC_BIAS_SET_Pos) 
#define BIAS_CTRL2_ADC_BIAS_SET_2X          		(2 << BIAS_CTRL2_ADC_BIAS_SET_Pos)
#define BIAS_CTRL2_ADC_BIAS_SET_3X          		(3 << BIAS_CTRL2_ADC_BIAS_SET_Pos)

// Bit 3:2: Set ADC Modulator Op-Amp 1 Bias Current
#define BIAS_CTRL2_ADC_OP1_BIAS_SET_Pos     		(2)
#define BIAS_CTRL2_ADC_OP1_BIAS_SET_Msk     		(3 << BIAS_CTRL2_ADC_OP1_BIAS_SET_Pos)
#define BIAS_CTRL2_ADC_OP1_BIAS_SET_0_5X    		(0 << BIAS_CTRL2_ADC_OP1_BIAS_SET_Pos)
#define BIAS_CTRL2_ADC_OP1_BIAS_SET_1X      		(1 << BIAS_CTRL2_ADC_OP1_BIAS_SET_Pos) 
#define BIAS_CTRL2_ADC_OP1_BIAS_SET_2X      		(2 << BIAS_CTRL2_ADC_OP1_BIAS_SET_Pos)
#define BIAS_CTRL2_ADC_OP1_BIAS_SET_3X      		(3 << BIAS_CTRL2_ADC_OP1_BIAS_SET_Pos)

// Bit 1:0: Set ADC Modulator Op-Amp 2 Bias Current
#define BIAS_CTRL2_ADC_OP2_BIAS_SET_Pos     		(0)
#define BIAS_CTRL2_ADC_OP2_BIAS_SET_Msk     		(3 << BIAS_CTRL2_ADC_OP2_BIAS_SET_Pos)
#define BIAS_CTRL2_ADC_OP2_BIAS_SET_0_5X    		(0 << BIAS_CTRL2_ADC_OP2_BIAS_SET_Pos)
#define BIAS_CTRL2_ADC_OP2_BIAS_SET_1X      		(1 << BIAS_CTRL2_ADC_OP2_BIAS_SET_Pos) 
#define BIAS_CTRL2_ADC_OP2_BIAS_SET_2X      		(2 << BIAS_CTRL2_ADC_OP2_BIAS_SET_Pos)
#define BIAS_CTRL2_ADC_OP2_BIAS_SET_3X      		(3 << BIAS_CTRL2_ADC_OP2_BIAS_SET_Pos)

// =============================================================================
// CHOP_CTRL - Address: 0x0A
// =============================================================================

// Bit 7: DAC Buffer Chopper
#define CHOP_CTRL_DIS_DAC_BUF_CHOP_Pos      		(7)
#define CHOP_CTRL_DIS_DAC_BUF_CHOP_Msk      		(1 << CHOP_CTRL_DIS_DAC_BUF_CHOP_Pos)
#define CHOP_CTRL_DIS_DAC_BUF_CHOP_ENABLE   		(0 << CHOP_CTRL_DIS_DAC_BUF_CHOP_Pos)
#define CHOP_CTRL_DIS_DAC_BUF_CHOP_DISABLE  		(1 << CHOP_CTRL_DIS_DAC_BUF_CHOP_Pos)

// Bit 6: ADC Modulator Reference P/N Buffer Chopper
#define CHOP_CTRL_DIS_MOD_REFPN_CHOP_Pos    		(6)
#define CHOP_CTRL_DIS_MOD_REFPN_CHOP_Msk    		(1 << CHOP_CTRL_DIS_MOD_REFPN_CHOP_Pos)
#define CHOP_CTRL_DIS_MOD_REFPN_CHOP_ENABLE 		(0 << CHOP_CTRL_DIS_MOD_REFPN_CHOP_Pos)
#define CHOP_CTRL_DIS_MOD_REFPN_CHOP_DISABLE 		(1 << CHOP_CTRL_DIS_MOD_REFPN_CHOP_Pos)

// Bit 5: PGA Bandwidth Buffer Chopper
#define CHOP_CTRL_DIS_PGA_BUFF_CHOP_Pos     		(5)
#define CHOP_CTRL_DIS_PGA_BUFF_CHOP_Msk     		(1 << CHOP_CTRL_DIS_PGA_BUFF_CHOP_Pos)
#define CHOP_CTRL_DIS_PGA_BUFF_CHOP_ENABLE  		(0 << CHOP_CTRL_DIS_PGA_BUFF_CHOP_Pos)
#define CHOP_CTRL_DIS_PGA_BUFF_CHOP_DISABLE 		(1 << CHOP_CTRL_DIS_PGA_BUFF_CHOP_Pos)

// Bit 4: PGA Chopper Mode
#define CHOP_CTRL_DIS_PGA_CHOP_Pos          		(4)
#define CHOP_CTRL_DIS_PGA_CHOP_Msk          		(1 << CHOP_CTRL_DIS_PGA_CHOP_Pos)
#define CHOP_CTRL_DIS_PGA_CHOP_ENABLE       		(0 << CHOP_CTRL_DIS_PGA_CHOP_Pos)
#define CHOP_CTRL_DIS_PGA_CHOP_DISABLE      		(1 << CHOP_CTRL_DIS_PGA_CHOP_Pos)

// Bit 3: Modulator Chopper Mode
#define CHOP_CTRL_DIS_MOD_CHOP_Pos          		(3)
#define CHOP_CTRL_DIS_MOD_CHOP_Msk          		(1 << CHOP_CTRL_DIS_MOD_CHOP_Pos)
#define CHOP_CTRL_DIS_MOD_CHOP_ENABLE       		(0 << CHOP_CTRL_DIS_MOD_CHOP_Pos)
#define CHOP_CTRL_DIS_MOD_CHOP_DISABLE      		(1 << CHOP_CTRL_DIS_MOD_CHOP_Pos)

// Bit 2: Chip Level Chopper Mode
#define CHOP_CTRL_DIS_CHIP_CHOP_Pos         		(2)
#define CHOP_CTRL_DIS_CHIP_CHOP_Msk         		(1 << CHOP_CTRL_DIS_CHIP_CHOP_Pos)
#define CHOP_CTRL_DIS_CHIP_CHOP_ENABLE      		(0 << CHOP_CTRL_DIS_CHIP_CHOP_Pos)
#define CHOP_CTRL_DIS_CHIP_CHOP_DISABLE     		(1 << CHOP_CTRL_DIS_CHIP_CHOP_Pos)

// Bit 1: Internal Reference Voltage Chopper Mode
#define CHOP_CTRL_DIS_INT_REF_CHOP_Pos      		(1)
#define CHOP_CTRL_DIS_INT_REF_CHOP_Msk      		(1 << CHOP_CTRL_DIS_INT_REF_CHOP_Pos)
#define CHOP_CTRL_DIS_INT_REF_CHOP_ENABLE   		(0 << CHOP_CTRL_DIS_INT_REF_CHOP_Pos)
#define CHOP_CTRL_DIS_INT_REF_CHOP_DISABLE  		(1 << CHOP_CTRL_DIS_INT_REF_CHOP_Pos)

// Bit 0: Band-Gap Chopper Mode
#define CHOP_CTRL_DIS_BG_CHOP_Pos           		(0)
#define CHOP_CTRL_DIS_BG_CHOP_Msk          		 	(1 << CHOP_CTRL_DIS_BG_CHOP_Pos)
#define CHOP_CTRL_DIS_BG_CHOP_ENABLE        		(0 << CHOP_CTRL_DIS_BG_CHOP_Pos)
#define CHOP_CTRL_DIS_BG_CHOP_DISABLE       		(1 << CHOP_CTRL_DIS_BG_CHOP_Pos)

// =============================================================================
// BG_CTRL 2 - Address: 0x0C
// =============================================================================

// Bit [7:2]: Banggap Output Trim Bits [5:0] (Default value from OTP)
#define BG_CTRL2_BG_TRIM_Pos                		(2)
#define BG_CTRL2_BG_TRIM_Msk                		(0x3F << BG_CTRL2_BG_TRIM_Pos)

// Bit 0: Banggap test mode output enable
// Note: This bit is write-protected. Need to unlock Protect KEY register first.
#define BG_CTRL2_BG_OUT_EN_Pos              		(0)
#define BG_CTRL2_BG_OUT_EN_Msk              		(1 << BG_CTRL2_BG_OUT_EN_Pos)
#define BG_CTRL2_BG_OUT_DIS                 		(0 << BG_CTRL2_BG_OUT_EN_Pos)
#define BG_CTRL2_BG_OUT_EN                  		(1 << BG_CTRL2_BG_OUT_EN_Pos)

// =============================================================================
// OSC_CTRL_2 - Address: 0x0E
// =============================================================================

// Bit 7: Select Internal Oscillator Clock
#define OSC_CTRL2_SEL_INT_OSC_Pos           		(7)
#define OSC_CTRL2_SEL_INT_OSC_Msk           		(1 << OSC_CTRL2_SEL_INT_OSC_Pos)
#define OSC_CTRL2_SEL_INT_OSC_EXTERNAL      		(0 << OSC_CTRL2_SEL_INT_OSC_Pos)
#define OSC_CTRL2_SEL_INT_OSC_INTERNAL      		(1 << OSC_CTRL2_SEL_INT_OSC_Pos)

// Bit 5:4: Select Internal Oscillator Clock Frequency
#define OSC_CTRL2_SEL_INT_OSC_F_Pos         		(4)
#define OSC_CTRL2_SEL_INT_OSC_F_Msk         		(3 << OSC_CTRL2_SEL_INT_OSC_F_Pos)
#define OSC_CTRL2_SEL_INT_OSC_F_8_192MHz    		(0 << OSC_CTRL2_SEL_INT_OSC_F_Pos)
#define OSC_CTRL2_SEL_INT_OSC_F_16_384MHz   		(1 << OSC_CTRL2_SEL_INT_OSC_F_Pos)
#define OSC_CTRL2_SEL_INT_OSC_F_24_576MHz   		(2 << OSC_CTRL2_SEL_INT_OSC_F_Pos)
#define OSC_CTRL2_SEL_INT_OSC_F_49_152MHz   		(3 << OSC_CTRL2_SEL_INT_OSC_F_Pos)

// Bit 3:2: Set Internal Oscillator Bias Current
#define OSC_CTRL2_OSC_BIAS_Pos             	 		(2)
#define OSC_CTRL2_OSC_BIAS_Msk              		(3 << OSC_CTRL2_OSC_BIAS_Pos)
#define OSC_CTRL2_OSC_BIAS_0_5X             		(0 << OSC_CTRL2_OSC_BIAS_Pos)
#define OSC_CTRL2_OSC_BIAS_1X               		(1 << OSC_CTRL2_OSC_BIAS_Pos)
#define OSC_CTRL2_OSC_BIAS_2X               		(2 << OSC_CTRL2_OSC_BIAS_Pos)
#define OSC_CTRL2_OSC_BIAS_3X               		(3 << OSC_CTRL2_OSC_BIAS_Pos)

// Bit 1:0: Internal Oscillator Frequency Trim Bits [9:8]
#define OSC_CTRL2_OSC_TRIM_9_8_Pos          		(0)
#define OSC_CTRL2_OSC_TRIM_9_8_Msk          		(3 << OSC_CTRL2_OSC_TRIM_9_8_Pos)

// =============================================================================
// VREF_CTRL - Address: 0x10
// =============================================================================

// Bit 7:6: Select Internal Reference Voltage Driving Strength
#define VREF_CTRL_SEL_INT_REF_DRV_Pos       		(6)
#define VREF_CTRL_SEL_INT_REF_DRV_Msk       		(3 << VREF_CTRL_SEL_INT_REF_DRV_Pos)
#define VREF_CTRL_SEL_INT_REF_DRV_LOWEST    		(0 << VREF_CTRL_SEL_INT_REF_DRV_Pos)
#define VREF_CTRL_SEL_INT_REF_DRV_MED_LOW   		(1 << VREF_CTRL_SEL_INT_REF_DRV_Pos)
#define VREF_CTRL_SEL_INT_REF_DRV_MED_HIGH  		(2 << VREF_CTRL_SEL_INT_REF_DRV_Pos) 
#define VREF_CTRL_SEL_INT_REF_DRV_HIGHEST   		(3 << VREF_CTRL_SEL_INT_REF_DRV_Pos)

// Bit 5:2: Select Internal VREF=2.4 Trim Value (Default from OTP)
#define VREF_CTRL_SEL_INT_REF_Pos           		(2)
#define VREF_CTRL_SEL_INT_REF_Msk           		(0xF << VREF_CTRL_SEL_INT_REF_Pos)

// Bit 1: Enable 1.8V LDO as Capless
#define VREF_CTRL_EN_CAPLESS_Pos            		(1)
#define VREF_CTRL_EN_CAPLESS_Msk            		(1 << VREF_CTRL_EN_CAPLESS_Pos)
#define VREF_CTRL_EN_CAPLESS_EXT_CAP        		(0 << VREF_CTRL_EN_CAPLESS_Pos)
#define VREF_CTRL_EN_CAPLESS_CAPLESS        		(1 << VREF_CTRL_EN_CAPLESS_Pos)

// Bit 0: Voltage Reference Level Control
#define VREF_CTRL_SEL_24V_INT_REF_Pos       		(0)
#define VREF_CTRL_SEL_24V_INT_REF_Msk       		(1 << VREF_CTRL_SEL_24V_INT_REF_Pos)
#define VREF_CTRL_SEL_24V_INT_REF_1_2V      		(0 << VREF_CTRL_SEL_24V_INT_REF_Pos)
#define VREF_CTRL_SEL_24V_INT_REF_2_4V      		(1 << VREF_CTRL_SEL_24V_INT_REF_Pos)


// =============================================================================
// PGA_CTRL 1 - Address: 0x11
// =============================================================================

// Bit 7:5: PGA Input Negative MUX Select Control Bits [2:0]
#define PGA_CTRL1_SEL_PGA_INN_Pos           		(5)
#define PGA_CTRL1_SEL_PGA_INN_Msk           		(7 << PGA_CTRL1_SEL_PGA_INN_Pos)
#define PGA_CTRL1_SEL_PGA_INN_ADC_CH0       		(0 << PGA_CTRL1_SEL_PGA_INN_Pos) 
#define PGA_CTRL1_SEL_PGA_INN_ADC_CH2       		(1 << PGA_CTRL1_SEL_PGA_INN_Pos)
#define PGA_CTRL1_SEL_PGA_INN_ADC_CH4       		(2 << PGA_CTRL1_SEL_PGA_INN_Pos)
#define PGA_CTRL1_SEL_PGA_INN_ADC_CH6       		(3 << PGA_CTRL1_SEL_PGA_INN_Pos)
#define PGA_CTRL1_SEL_PGA_INN_TP_NEG        		(4 << PGA_CTRL1_SEL_PGA_INN_Pos)
#define PGA_CTRL1_SEL_PGA_INN_VBG           		(5 << PGA_CTRL1_SEL_PGA_INN_Pos)
#define PGA_CTRL1_SEL_PGA_INN_AIN_COM       		(6 << PGA_CTRL1_SEL_PGA_INN_Pos)
#define PGA_CTRL1_SEL_PGA_INN_VCM           		(7 << PGA_CTRL1_SEL_PGA_INN_Pos)

// Bit 4:2: PGA Input Positive MUX Select Control Bits [2:0]
#define PGA_CTRL1_SEL_PGA_INP_Pos           		(2)
#define PGA_CTRL1_SEL_PGA_INP_Msk           		(7 << PGA_CTRL1_SEL_PGA_INP_Pos)
#define PGA_CTRL1_SEL_PGA_INP_ADC_CH1       		(0 << PGA_CTRL1_SEL_PGA_INP_Pos) 
#define PGA_CTRL1_SEL_PGA_INP_ADC_CH3       		(1 << PGA_CTRL1_SEL_PGA_INP_Pos)
#define PGA_CTRL1_SEL_PGA_INP_ADC_CH5       		(2 << PGA_CTRL1_SEL_PGA_INP_Pos)
#define PGA_CTRL1_SEL_PGA_INP_ADC_CH7       		(3 << PGA_CTRL1_SEL_PGA_INP_Pos)
#define PGA_CTRL1_SEL_PGA_INP_TP_POS        		(4 << PGA_CTRL1_SEL_PGA_INP_Pos)
#define PGA_CTRL1_SEL_PGA_INP_DAC           		(5 << PGA_CTRL1_SEL_PGA_INP_Pos)
#define PGA_CTRL1_SEL_PGA_INP_AIN_COM       		(6 << PGA_CTRL1_SEL_PGA_INP_Pos)
#define PGA_CTRL1_SEL_PGA_INP_VCM           		(7 << PGA_CTRL1_SEL_PGA_INP_Pos)

// Bit 1: PGA Input Mux Control
#define PGA_CTRL1_DIS_INMUX_DIG_Pos         		(1)
#define PGA_CTRL1_DIS_INMUX_DIG_Msk         		(1 << PGA_CTRL1_DIS_INMUX_DIG_Pos)
#define PGA_CTRL1_INMUX_ENABLE              		(0 << PGA_CTRL1_DIS_INMUX_DIG_Pos) 
#define PGA_CTRL1_INMUX_CLOSE_ALL           		(1 << PGA_CTRL1_DIS_INMUX_DIG_Pos)

// Bit 0: Bypass PGA Control
#define PGA_CTRL1_PGA_BYPASS_Pos            		(0)
#define PGA_CTRL1_PGA_BYPASS_Msk           		  (1 << PGA_CTRL1_PGA_BYPASS_Pos)
#define PGA_CTRL1_PGA_USE                   		(0 << PGA_CTRL1_PGA_BYPASS_Pos) 
#define PGA_CTRL1_PGA_BYPASSED              		(1 << PGA_CTRL1_PGA_BYPASS_Pos)

// =============================================================================
// PGA_CTRL 3 - Address: 0x13
// =============================================================================

// Bit 7: ADC Offset Calibration Control
#define PGA_CTRL3_OFFSETDIS_Pos             		(7)
#define PGA_CTRL3_OFFSETDIS_Msk             		(1 << PGA_CTRL3_OFFSETDIS_Pos)
#define PGA_CTRL3_OFFSET_CAL_EN             		(0 << PGA_CTRL3_OFFSETDIS_Pos)
#define PGA_CTRL3_OFFSET_CAL_DIS            		(1 << PGA_CTRL3_OFFSETDIS_Pos) 

// Bit 6: Auto Enable PGA Bandwidth Buffer
#define PGA_CTRL3_PGA_BUF_AUTO_EN_Pos       		(6)
#define PGA_CTRL3_PGA_BUF_AUTO_EN_Msk       		(1 << PGA_CTRL3_PGA_BUF_AUTO_EN_Pos)
#define PGA_CTRL3_PGA_BUF_MANUAL            		(0 << PGA_CTRL3_PGA_BUF_AUTO_EN_Pos)
#define PGA_CTRL3_PGA_BUF_AUTO              		(1 << PGA_CTRL3_PGA_BUF_AUTO_EN_Pos) 

// Bit 5: Bypass PGA Bandwidth Buffer Control
#define PGA_CTRL3_PGA_BUF_BYPASS_Pos        		(5)
#define PGA_CTRL3_PGA_BUF_BYPASS_Msk        		(1 << PGA_CTRL3_PGA_BUF_BYPASS_Pos)
#define PGA_CTRL3_PGA_BUF_USE               		(0 << PGA_CTRL3_PGA_BUF_BYPASS_Pos) 
#define PGA_CTRL3_PGA_BUF_BYPASSED          		(1 << PGA_CTRL3_PGA_BUF_BYPASS_Pos)

// Bit 4: PGA Bandwidth Buffer Gain Control
#define PGA_CTRL3_PGA_BUF_GAIN_Pos          		(4)
#define PGA_CTRL3_PGA_BUF_GAIN_Msk          		(1 << PGA_CTRL3_PGA_BUF_GAIN_Pos)
#define PGA_CTRL3_PGA_BUF_GAIN_1X           		(0 << PGA_CTRL3_PGA_BUF_GAIN_Pos) 
#define PGA_CTRL3_PGA_BUF_GAIN_2X           		(1 << PGA_CTRL3_PGA_BUF_GAIN_Pos)

// Bit 3:1: Analog PGA Gain Control Bits [2:0]
#define PGA_CTRL3_PGA_GAIN_Pos              		(1)
#define PGA_CTRL3_PGA_GAIN_Msk              		(7 << PGA_CTRL3_PGA_GAIN_Pos)
#define PGA_CTRL3_PGA_GAIN_1X               		(0 << PGA_CTRL3_PGA_GAIN_Pos)
#define PGA_CTRL3_PGA_GAIN_2X               		(1 << PGA_CTRL3_PGA_GAIN_Pos)
#define PGA_CTRL3_PGA_GAIN_4X               		(2 << PGA_CTRL3_PGA_GAIN_Pos)
#define PGA_CTRL3_PGA_GAIN_8X               		(3 << PGA_CTRL3_PGA_GAIN_Pos)
#define PGA_CTRL3_PGA_GAIN_16X              		(4 << PGA_CTRL3_PGA_GAIN_Pos)
#define PGA_CTRL3_PGA_GAIN_32X              		(5 << PGA_CTRL3_PGA_GAIN_Pos)
#define PGA_CTRL3_PGA_GAIN_64X              		(6 << PGA_CTRL3_PGA_GAIN_Pos)
#define PGA_CTRL3_PGA_GAIN_128X             		(7 << PGA_CTRL3_PGA_GAIN_Pos)

// Bit 0: DWA (Data Weighted Averaging) Control
#define PGA_CTRL3_DIS_DWA_Pos               		(0)
#define PGA_CTRL3_DIS_DWA_Msk               		(1 << PGA_CTRL3_DIS_DWA_Pos)
#define PGA_CTRL3_DWA_EN                    		(0 << PGA_CTRL3_DIS_DWA_Pos)
#define PGA_CTRL3_DWA_DIS                   		(1 << PGA_CTRL3_DIS_DWA_Pos)

// =============================================================================
// PGA_CTRL_5 - Address: 0x15
// =============================================================================

// Bit 7: PGA CHOP MUX Mode
#define PGA_CTRL5_DIS_PGA_CHOP_MUX_Pos        	(7)
#define PGA_CTRL5_DIS_PGA_CHOP_MUX_Msk        	(1 << PGA_CTRL5_DIS_PGA_CHOP_MUX_Pos)
#define PGA_CTRL5_DIS_PGA_CHOP_MUX_ENABLE     	(0 << PGA_CTRL5_DIS_PGA_CHOP_MUX_Pos)
#define PGA_CTRL5_DIS_PGA_CHOP_MUX_DISABLE    	(1 << PGA_CTRL5_DIS_PGA_CHOP_MUX_Pos)

// Bit 6:4: Set PGA Buffer Bias Current
#define PGA_CTRL5_PGA_BUFF_BIAS_SET_Pos       	(4)
#define PGA_CTRL5_PGA_BUFF_BIAS_SET_Msk       	(7 << PGA_CTRL5_PGA_BUFF_BIAS_SET_Pos)
#define PGA_CTRL5_PGA_BUFF_BIAS_SET_0_5X      	(0 << PGA_CTRL5_PGA_BUFF_BIAS_SET_Pos)
#define PGA_CTRL5_PGA_BUFF_BIAS_SET_1X        	(1 << PGA_CTRL5_PGA_BUFF_BIAS_SET_Pos)
#define PGA_CTRL5_PGA_BUFF_BIAS_SET_2X        	(2 << PGA_CTRL5_PGA_BUFF_BIAS_SET_Pos)
#define PGA_CTRL5_PGA_BUFF_BIAS_SET_3X        	(3 << PGA_CTRL5_PGA_BUFF_BIAS_SET_Pos)
#define PGA_CTRL5_PGA_BUFF_BIAS_SET_4X        	(4 << PGA_CTRL5_PGA_BUFF_BIAS_SET_Pos)
#define PGA_CTRL5_PGA_BUFF_BIAS_SET_6X        	(5 << PGA_CTRL5_PGA_BUFF_BIAS_SET_Pos)
#define PGA_CTRL5_PGA_BUFF_BIAS_SET_8X        	(6 << PGA_CTRL5_PGA_BUFF_BIAS_SET_Pos)

// Bit 3: Interleaving CH4 PGA Bandwidth Buffer Gain Control
#define PGA_CTRL5_CH4_PGA_BUF_GAIN_Pos        	(3)
#define PGA_CTRL5_CH4_PGA_BUF_GAIN_Msk        	(1 << PGA_CTRL5_CH4_PGA_BUF_GAIN_Pos)
#define PGA_CTRL5_CH4_PGA_BUF_GAIN_1X         	(0 << PGA_CTRL5_CH4_PGA_BUF_GAIN_Pos)
#define PGA_CTRL5_CH4_PGA_BUF_GAIN_2X         	(1 << PGA_CTRL5_CH4_PGA_BUF_GAIN_Pos)

// Bit 2:0: Interleaving CH4 Analog PGA Gain Control Bits
#define PGA_CTRL5_CH4_PGA_GAIN_Pos            	(0)
#define PGA_CTRL5_CH4_PGA_GAIN_Msk            	(7 << PGA_CTRL5_CH4_PGA_GAIN_Pos)
#define PGA_CTRL5_CH4_PGA_GAIN_1X             	(0 << PGA_CTRL5_CH4_PGA_GAIN_Pos)
#define PGA_CTRL5_CH4_PGA_GAIN_2X             	(1 << PGA_CTRL5_CH4_PGA_GAIN_Pos)
#define PGA_CTRL5_CH4_PGA_GAIN_4X             	(2 << PGA_CTRL5_CH4_PGA_GAIN_Pos)
#define PGA_CTRL5_CH4_PGA_GAIN_8X             	(3 << PGA_CTRL5_CH4_PGA_GAIN_Pos)
#define PGA_CTRL5_CH4_PGA_GAIN_16X            	(4 << PGA_CTRL5_CH4_PGA_GAIN_Pos)
#define PGA_CTRL5_CH4_PGA_GAIN_32X            	(5 << PGA_CTRL5_CH4_PGA_GAIN_Pos)
#define PGA_CTRL5_CH4_PGA_GAIN_64X            	(6 << PGA_CTRL5_CH4_PGA_GAIN_Pos)
#define PGA_CTRL5_CH4_PGA_GAIN_128X           	(7 << PGA_CTRL5_CH4_PGA_GAIN_Pos)

// =============================================================================
// PGA_CTRL_6 - Address: 0x16
// =============================================================================

// Bit 7:5: Chop clock 2 mux control
#define PGA_CTRL6_CHOP_MUX_CLK_SET_Pos        	(5)
#define PGA_CTRL6_CHOP_MUX_CLK_SET_Msk        	(7 << PGA_CTRL6_CHOP_MUX_CLK_SET_Pos)

// Bit 4:2: Chop clock mux control
#define PGA_CTRL6_CHOP_CLK_SET_Pos            	(2)
#define PGA_CTRL6_CHOP_CLK_SET_Msk            	(7 << PGA_CTRL6_CHOP_CLK_SET_Pos)

// Bit 1:0: Chop clock source control selection
#define PGA_CTRL6_CHOP_CLK_CTRL_Pos           	(0)
#define PGA_CTRL6_CHOP_CLK_CTRL_Msk           	(3 << PGA_CTRL6_CHOP_CLK_CTRL_Pos)
#define PGA_CTRL6_CHOP_CLK_CTRL_REG           	(0 << PGA_CTRL6_CHOP_CLK_CTRL_Pos)
#define PGA_CTRL6_CHOP_CLK_CTRL_TABLE1        	(1 << PGA_CTRL6_CHOP_CLK_CTRL_Pos)
#define PGA_CTRL6_CHOP_CLK_CTRL_TABLE2        	(2 << PGA_CTRL6_CHOP_CLK_CTRL_Pos)
#define PGA_CTRL6_CHOP_CLK_CTRL_TABLE3        	(3 << PGA_CTRL6_CHOP_CLK_CTRL_Pos)

// =============================================================================
// Status Register (STATUS) - Address: 0x1D
// =============================================================================

// Bit 5:4: Data Ready Interleaving Channel
#define STATUS_DRDY_CH_Pos                  		(4)
#define STATUS_DRDY_CH_Msk                  		(3 << STATUS_DRDY_CH_Pos)
#define STATUS_DRDY_CH_INTERLEAVING_CH1     		(0 << STATUS_DRDY_CH_Pos) 
#define STATUS_DRDY_CH_INTERLEAVING_CH2     		(1 << STATUS_DRDY_CH_Pos)
#define STATUS_DRDY_CH_INTERLEAVING_CH3     		(2 << STATUS_DRDY_CH_Pos) 
#define STATUS_DRDY_CH_INTERLEAVING_CH4     		(3 << STATUS_DRDY_CH_Pos) 

// Bit 3: Software Reset Flag
#define STATUS_SWRST_Pos                    		(3)
#define STATUS_SWRST_Msk                    		(1 << STATUS_SWRST_Pos)
#define STATUS_SWRST_OCCURRED               		(1 << STATUS_SWRST_Pos)
#define STATUS_SWRST_NONE                   		(0 << STATUS_SWRST_Pos) 

// Bit 2: POR33 Reset Flag
#define STATUS_POR33_Pos                    		(2)
#define STATUS_POR33_Msk                    		(1 << STATUS_POR33_Pos)
#define STATUS_POR33_OCCURRED               		(1 << STATUS_POR33_Pos) 
#define STATUS_POR33_NONE                   		(0 << STATUS_POR33_Pos) 

// Bit 1: POR18 Reset Flag
#define STATUS_POR18_Pos                    		(1)
#define STATUS_POR18_Msk                    		(1 << STATUS_POR18_Pos)
#define STATUS_POR18_OCCURRED               		(1 << STATUS_POR18_Pos) 
#define STATUS_POR18_NONE                   		(0 << STATUS_POR18_Pos) 

// Bit 0: Data Ready Flag
#define STATUS_DRDY_Pos                     		(0)
#define STATUS_DRDY_Msk                     		(1 << STATUS_DRDY_Pos)
#define STATUS_DRDY_READY                   		(1 << STATUS_DRDY_Pos) 
#define STATUS_DRDY_INVALID                 		(0 << STATUS_DRDY_Pos) 

// =============================================================================
// MISC 1 - Address: 0x1E
// =============================================================================

// Bit 7: LDO Test Mode Enable Bit
#define MISC_LDOTEN_Pos                     		(7)
#define MISC_LDOTEN_Msk                     		(1 << MISC_LDOTEN_Pos)
#define MISC_LDOTEN_DIS                     		(0 << MISC_LDOTEN_Pos) 
#define MISC_LDOTEN_EN                      		(1 << MISC_LDOTEN_Pos)

// Bit 6: HIRC Test Mode Enable Bit
#define MISC_HIRCTEN_Pos                    		(6)
#define MISC_HIRCTEN_Msk                    		(1 << MISC_HIRCTEN_Pos)
#define MISC_HIRCTEN_DIS                    		(0 << MISC_HIRCTEN_Pos)
#define MISC_HIRCTEN_EN                     		(1 << MISC_HIRCTEN_Pos)

// Bit 5: Digital Filter BIST Enable Bit
#define MISC_DF_BISTEN_Pos                  		(5)
#define MISC_DF_BISTEN_Msk                  		(1 << MISC_DF_BISTEN_Pos)
#define MISC_DF_BISTEN_DIS                  		(0 << MISC_DF_BISTEN_Pos) 
#define MISC_DF_BISTEN_EN                   		(1 << MISC_DF_BISTEN_Pos)

// Bit 4: SRAM BIST Enable Bit
#define MISC_SRAM_BISTEN_Pos                		(4)
#define MISC_SRAM_BISTEN_Msk                		(1 << MISC_SRAM_BISTEN_Pos)
#define MISC_SRAM_BISTEN_DIS                		(0 << MISC_SRAM_BISTEN_Pos)
#define MISC_SRAM_BISTEN_EN                 		(1 << MISC_SRAM_BISTEN_Pos)

// Bit 3: Bypass ADC Modulator Output Data to IO
#define MISC_BYPASSALL_Pos                  		(3)
#define MISC_BYPASSALL_Msk                  		(1 << MISC_BYPASSALL_Pos)
#define MISC_BYPASSALL_DIS                  		(0 << MISC_BYPASSALL_Pos) 
#define MISC_BYPASSALL_EN                   		(1 << MISC_BYPASSALL_Pos)

// Bit 2:0: SPI_CLK Clock Filter Selection
#define MISC_CKFSEL_Pos                     		(0)
#define MISC_CKFSEL_Msk                     		(7 << MISC_CKFSEL_Pos)
#define MISC_CKFSEL_4_STAGE                 		(0 << MISC_CKFSEL_Pos)
#define MISC_CKFSEL_5_STAGE                 		(1 << MISC_CKFSEL_Pos)
#define MISC_CKFSEL_6_STAGE                 		(2 << MISC_CKFSEL_Pos)
#define MISC_CKFSEL_7_STAGE                 		(3 << MISC_CKFSEL_Pos)
#define MISC_CKFSEL_8_STAGE                 		(4 << MISC_CKFSEL_Pos)
#define MISC_CKFSEL_9_STAGE                 		(5 << MISC_CKFSEL_Pos)
#define MISC_CKFSEL_10_STAGE               		 	(6 << MISC_CKFSEL_Pos)
#define MISC_CKFSEL_11_STAGE               			(7 << MISC_CKFSEL_Pos)


//------------------------------------------------------------------------------
// ADC OTP operation register address
//------------------------------------------------------------------------------
#define WRITE_OTP1_DOUT0_CMD                    0x10 /* Write the OTP1 DOUT0 Register OTP_CS:00b PRD:0b PPROG:1b PTM:00b PA:00b  */
#define WRITE_OTP1_DOUT1_CMD                    0x11 /* Write the OTP1 DOUT1 Register OTP_CS:00b PRD:0b PPROG:1b PTM:00b PA:01b  */
#define WRITE_OTP1_DOUT2_CMD                    0x12 /* Write the OTP1 DOUT2 Register OTP_CS:00b PRD:0b PPROG:1b PTM:00b PA:10b  */
#define WRITE_OTP1_DOUT3_CMD                    0x13 /* Write the OTP1 DOUT3 Register OTP_CS:00b PRD:0b PPROG:1b PTM:00b PA:11b  */
#define READ_OTP1_DOUT_REG_CMD                  0x20 /* Read the OTP1 DOUT0-DOUT3 Register OTP_CS:00b PRD:1b PPROG:0b PTM:00b PA:00b*/

#define WRITE_OTP2_DOUT0_CMD                    0x50 /* Write the OTP2 DOUT0 Register OTP_CS:01b PRD:0b PPROG:1b PTM:00b PA:00b  */
#define WRITE_OTP2_DOUT1_CMD                    0x51 /* Write the OTP2 DOUT1 Register OTP_CS:01b PRD:0b PPROG:1b PTM:00b PA:01b  */
#define WRITE_OTP2_DOUT2_CMD                    0x52 /* Write the OTP2 DOUT2 Register OTP_CS:01b PRD:0b PPROG:1b PTM:00b PA:10b  */
#define WRITE_OTP2_DOUT3_CMD                    0x53 /* Write the OTP2 DOUT3 Register OTP_CS:01b PRD:0b PPROG:1b PTM:00b PA:11b  */
#define READ_OTP2_DOUT_REG_CMD                  0x60 /* Read the OTP2 DOUT0-DOUT3 Register OTP_CS:01b PRD:1b PPROG:0b PTM:00b PA:00b*/

#define WRITE_OTP3_DOUT0_CMD                    0x90 /* Write the OTP3 DOUT0 Register OTP_CS:10b PRD:0b PPROG:1b PTM:00b PA:00b  */
#define WRITE_OTP3_DOUT1_CMD                    0x91 /* Write the OTP3 DOUT1 Register OTP_CS:10b PRD:0b PPROG:1b PTM:00b PA:01b  */
#define WRITE_OTP3_DOUT2_CMD                    0x92 /* Write the OTP3 DOUT2 Register OTP_CS:10b PRD:0b PPROG:1b PTM:00b PA:10b  */
#define WRITE_OTP3_DOUT3_CMD                    0x93 /* Write the OTP3 DOUT3 Register OTP_CS:10b PRD:0b PPROG:1b PTM:00b PA:11b  */
#define READ_OTP3_DOUT_REG_CMD                  0xA0 /* Read the OTP3 DOUT0-DOUT3 Register OTP_CS:10b PRD:1b PPROG:0b PTM:00b PA:00b*/

#define CLEAR_OTP1_DOUT0_WRITE_CMD              0x00 /* Clear the write command for OTP1 DOUT0 Register OTP_CS:00b PRD:0b PPROG:0b PTM:00b PA:00b  */
#define CLEAR_OTP1_DOUT1_WRITE_CMD              0x01 /* Clear the write command for OTP1 DOUT1 Register OTP_CS:00b PRD:0b PPROG:0b PTM:00b PA:01b  */
#define CLEAR_OTP1_DOUT2_WRITE_CMD              0x02 /* Clear the write command for OTP1 DOUT2 Register OTP_CS:00b PRD:0b PPROG:0b PTM:00b PA:10b  */
#define CLEAR_OTP1_DOUT3_WRITE_CMD              0x03 /* Clear the write command for OTP1 DOUT3 Register OTP_CS:00b PRD:0b PPROG:0b PTM:00b PA:11b  */
#define CLEAR_OTP1_DOUT_READ_CMD                0x00 /* Clear the read command for OTP1 DOUT0-DOUT3 Register OTP_CS:00b PRD:0b PPROG:0b PTM:00b PA:00b*/

#define CLEAR_OTP2_DOUT0_WRITE_CMD              0x40 /* Clear the write command for OTP2 DOUT0 Register OTP_CS:01b PRD:0b PPROG:0b PTM:00b PA:00b  */
#define CLEAR_OTP2_DOUT1_WRITE_CMD              0x41 /* Clear the write command for OTP2 DOUT1 Register OTP_CS:01b PRD:0b PPROG:0b PTM:00b PA:01b  */
#define CLEAR_OTP2_DOUT2_WRITE_CMD              0x42 /* Clear the write command for OTP2 DOUT2 Register OTP_CS:01b PRD:0b PPROG:0b PTM:00b PA:10b  */
#define CLEAR_OTP2_DOUT3_WRITE_CMD              0x43 /* Clear the write command for OTP2 DOUT3 Register OTP_CS:01b PRD:0b PPROG:0b PTM:00b PA:11b  */
#define CLEAR_OTP2_DOUT_READ_CMD                0x40 /* Clear the read command for OTP2 DOUT0-DOUT3 Register OTP_CS:01b PRD:0b PPROG:0b PTM:00b PA:00b*/

#define CLEAR_OTP3_DOUT0_WRITE_CMD              0x80 /* Clear the write command for OTP3 DOUT0 Register OTP_CS:10b PRD:0b PPROG:0b PTM:00b PA:00b  */
#define CLEAR_OTP3_DOUT1_WRITE_CMD              0x81 /* Clear the write command for OTP3 DOUT1 Register OTP_CS:10b PRD:0b PPROG:0b PTM:00b PA:01b  */
#define CLEAR_OTP3_DOUT2_WRITE_CMD              0x82 /* Clear the write command for OTP3 DOUT2 Register OTP_CS:10b PRD:0b PPROG:0b PTM:00b PA:10b  */
#define CLEAR_OTP3_DOUT3_WRITE_CMD              0x83 /* Clear the write command for OTP3 DOUT3 Register OTP_CS:10b PRD:0b PPROG:0b PTM:00b PA:11b  */
#define CLEAR_OTP3_DOUT_READ_CMD                0x40 /* Clear the read command for OTP3 DOUT0-DOUT3 Register OTP_CS:10b PRD:0b PPROG:0b PTM:00b PA:00b*/

//------------------------------------------------------------------------------
// ADC register
//------------------------------------------------------------------------------
void SPI_WriteReg_Bank1(uint8_t u8RegAddr, uint8_t u8WriteData);
void SPI_WriteReg_Bank2(uint8_t u8RegAddr, uint8_t u8WriteData);
uint8_t SPI_ReadReg_Bank1(uint8_t u8RegAddr);
uint8_t SPI_ReadReg_Bank2(uint8_t u8RegAddr);

//------------------------------------------------------------------------------
// ADC Commands
//------------------------------------------------------------------------------
void SPI_Send_ADC_Commnad(uint32_t u32Cmd);
uint32_t SPI_ReadADCData(void);
uint32_t SPI_ReadADCDataWithReadCMD(void);
uint32_t SPI_SetChannel_and_ReadADCData(uint8_t u8Channel);

//------------------------------------------------------------------------------
// Read ADC Data
//------------------------------------------------------------------------------
void delay_10us(uint32_t nDelay);
void delay_1ms(uint32_t nDelay);
uint8_t Reset_NADC24B(void);
uint8_t NADC24B_Cali_and_Initial(void);

#endif /* _ADC_REG_TABLE_H_ */
/*** (C) COPYRIGHT 2023 Nuvoton Technology Corp. ***/
