/*(C) Copyright 2016
 * Richtek <www.richtek.com>
 *
 * RT3000 driver for MT6795
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef RT3000_H
#define RT3000_H

#include <linux/ioctl.h>

#define RT3000_I2C_SLAVE_WRITE_ADDR		0x19

#define ENABLE_RESERVE_REGISTER



#define RT3000_CTRL_REG1_ODR_POWER_DOWN 0x00
#define RT3000_CTRL_REG1_ODR_1HZ 0x10
#define RT3000_CTRL_REG1_ODR_10HZ 0x20
#define RT3000_CTRL_REG1_ODR_25HZ 0x30
#define RT3000_CTRL_REG1_ODR_50HZ 0x40
#define RT3000_CTRL_REG1_ODR_100HZ 0x50
#define RT3000_CTRL_REG1_ODR_200HZ 0x60
#define RT3000_CTRL_REG1_ODR_400HZ 0x70
#define RT3000_CTRL_REG1_ODR_800HZ 0x80
#define RT3000_CTRL_REG1_ODR_4000HZ 0x90
#define RT3000_CTRL_REG1_XYZ_ENABLE 0x07
#define RT3000_CTRL_REG1_ODR_MASK 0xF0

#define RT3000_CTRL_REG3_AOI_INT 0x40

#define RT3000_CTRL_REG4_RANGE_2G 0x00
#define RT3000_CTRL_REG4_RANGE_4G 0x10
#define RT3000_CTRL_REG4_RANGE_8G 0x20
#define RT3000_CTRL_REG4_RANGE_MASK 0x30
#define RT3000_SUCCESS						0
#define RT3000_ERR_I2C						-1
#define RT3000_ERR_STATUS					-3
#define RT3000_ERR_SETUP_FAILURE			-4
#define RT3000_ERR_GETGSENSORDATA			-5
#define RT3000_ERR_IDENTIFICATION			-6



#define RT3000_BUFSIZE				256

#define RT3000_AXES_NUM        3

/*----------------------------------------------------------------------------*/
typedef enum {
	RT3000_CUST_ACTION_SET_CUST = 1,
	RT3000_CUST_ACTION_SET_CALI,
	RT3000_CUST_ACTION_RESET_CALI
} CUST_ACTION;
/*----------------------------------------------------------------------------*/
typedef struct {
	uint16_t action;
} RT3000_CUST;
/*----------------------------------------------------------------------------*/
typedef struct {
	uint16_t action;
	uint16_t part;
	int32_t data[0];
} RT3000_SET_CUST;
/*----------------------------------------------------------------------------*/
typedef struct {
	uint16_t action;
	int32_t data[RT3000_AXES_NUM];
} RT3000_SET_CALI;
/*----------------------------------------------------------------------------*/
typedef RT3000_CUST RT3000_RESET_CALI;
/*----------------------------------------------------------------------------*/
typedef union {
	uint32_t data[10];
	RT3000_CUST cust;
	RT3000_SET_CUST setCust;
	RT3000_SET_CALI setCali;
	RT3000_RESET_CALI resetCali;
} RT3000_CUST_DATA;
/*----------------------------------------------------------------------------*/
enum {
	RT3000_REG_ADDR_DOFS_XY,
	RT3000_REG_ADDR_DOFS_Z,
	RT3000_REG_ADDR_MTP_DATA_L,
	RT3000_REG_ADDR_MTP_DATA_H,
	RT3000_REG_ADDR_MTP_ADR_REG,
	RT3000_REG_ADDR_MTP_CTRL_REG,
	RT3000_REG_ADDR_UNLOCK,
	RT3000_REG_ADDR_STS_REG_AUX,
	RT3000_REG_ADDR_WHO_AM_I = 0x0F,
	RT3000_REG_ADDR_OFS_X,
	RT3000_REG_ADDR_GS1_X,
	RT3000_REG_ADDR_GS2_X,
	RT3000_REG_ADDR_OFS_Y,
	RT3000_REG_ADDR_GS1_Y,
	RT3000_REG_ADDR_GS2_Y,
	RT3000_REG_ADDR_OFS_Z,
	RT3000_REG_ADDR_GS1_Z,
	RT3000_REG_ADDR_GS2_Z,
	RT3000_REG_ADDR_NON_0X19,
	RT3000_REG_ADDR_TEMP_CFG = 0x1F,
	RT3000_REG_ADDR_CTRL_REG1 = 0x20,
	RT3000_REG_ADDR_CTRL_REG2,
	RT3000_REG_ADDR_CTRL_REG3,
	RT3000_REG_ADDR_CTRL_REG4,
	RT3000_REG_ADDR_CTRL_REG5,
	RT3000_REG_ADDR_CTRL_REG6,
	RT3000_REG_ADDR_STS_REG = 0x27,
	RT3000_REG_ADDR_OUT_X_L,
	RT3000_REG_ADDR_OUT_X_H,
	RT3000_REG_ADDR_OUT_Y_L,
	RT3000_REG_ADDR_OUT_Y_H,
	RT3000_REG_ADDR_OUT_Z_L,
	RT3000_REG_ADDR_OUT_Z_H,
	RT3000_REG_ADDR_OUT_FIFO_CFG,
	RT3000_REG_ADDR_OUT_FIFO_SRC,
	RT3000_REG_ADDR_OUT_INT1_CFG,
	RT3000_REG_ADDR_OUT_INT1_SRC,
	RT3000_REG_ADDR_OUT_INT1_THS,
	RT3000_REG_ADDR_OUT_INT1_DURATION,
	RT3000_REG_ADDR_OUT_CLICK_CFG = 0x38,
	RT3000_REG_ADDR_OUT_CLICK_SRC,
	RT3000_REG_ADDR_OUT_CLICK_THS,
	RT3000_REG_ADDR_OUT_TIME_LIMIT,
	RT3000_REG_ADDR_OUT_TIME_LATENCY,
	RT3000_REG_ADDR_OUT_TIME_WINDOW,
	RT3000_REG_ADDR_OUT_ACT_THS,
	RT3000_REG_ADDR_OUT_ACT_DUR,
	RT3000_REG_ADDR_HW_CFG0 = 0x40,
	RT3000_REG_ADDR_HW_CFG1,
	RT3000_REG_ADDR_HW_CFG2,
	RT3000_REG_ADDR_SLEEP_OSC_TRIM,
	RT3000_REG_ADDR_OSC_TRIM,
	RT3000_REG_ADDR_LDO_TRIM,
	RT3000_REG_ADDR_TMOD_CFG0,
	RT3000_REG_ADDR_TMOD_CFG1,
	RT3000_REG_ADDR_DREG_DATA,
	RT3000_REG_ADDR_DLDO_TRIM,
	RT3000_REG_ADDR_HW_STS,
	RT3000_REG_ADDR_ASIC_VID = 0x4F,
	RT3000_REG_ADDR_CVS_CSEL_X,
	RT3000_REG_ADDR_CVS_CSEL_Y,
	RT3000_REG_ADDR_CVS_CSEL_Z,
	RT3000_REG_ADDR_CVS_VS_X,
	RT3000_REG_ADDR_CVS_VS_Y,
	RT3000_REG_ADDR_CVS_VS_Z,
};
enum {
	RT3000_MTP_ADDR_MAGIC_WD,
	RT3000_MTP_ADDR_HW_CFG0,
	RT3000_MTP_ADDR_HW_CFG1,
	RT3000_MTP_ADDR_HW_CFG2,
	RT3000_MTP_ADDR_OSR_CFG,
	RT3000_MTP_ADDR_SLEEP_OSC_TRIM,
	RT3000_MTP_ADDR_TEMP_CAL_P0_L,
	RT3000_MTP_ADDR_TEMP_CAL_H,
	RT3000_MTP_ADDR_TEMP_CAL_P1_L,
	RT3000_MTP_ADDR_TEMP_CFG,
	RT3000_MTP_ADDR_OFS_X_2G,
	RT3000_MTP_ADDR_GS2_X_2G,
	RT3000_MTP_ADDR_OFS_Y_2G,
	RT3000_MTP_ADDR_GS2_Y_2G,
	RT3000_MTP_ADDR_OFS_Z_2G,
	RT3000_MTP_ADDR_GS2_Z_2G,
	RT3000_MTP_ADDR_OFS_X_4G,
	RT3000_MTP_ADDR_GS2_X_4G,
	RT3000_MTP_ADDR_OFS_Y_4G,
	RT3000_MTP_ADDR_GS2_Y_4G,
	RT3000_MTP_ADDR_OFS_Z_4G,
	RT3000_MTP_ADDR_GS2_Z_4G,
	RT3000_MTP_ADDR_OFS_X_8G,
	RT3000_MTP_ADDR_GS2_X_8G,
	RT3000_MTP_ADDR_OFS_Y_8G,
	RT3000_MTP_ADDR_GS2_Y_8G,
	RT3000_MTP_ADDR_OFS_Z_8G,
	RT3000_MTP_ADDR_GS2_Z_8G,
	RT3000_MTP_ADDR_OFS_X_16G,
	RT3000_MTP_ADDR_GS2_X_16G,
	RT3000_MTP_ADDR_OFS_Y_16G,
	RT3000_MTP_ADDR_GS2_Y_16G,
	RT3000_MTP_ADDR_OFS_Z_16G,
	RT3000_MTP_ADDR_GS2_Z_16G,
	RT3000_MTP_ADDR_GS1_X_24G,
	RT3000_MTP_ADDR_GS1_X_86G,
	RT3000_MTP_ADDR_GS1_Y_24G,
	RT3000_MTP_ADDR_GS1_Y_86G,
	RT3000_MTP_ADDR_GS1_Z_24G,
	RT3000_MTP_ADDR_GS1_Z_86G,
	RT3000_MTP_ADDR_CVS_CSEL_X,
	RT3000_MTP_ADDR_CVS_CSEL_Y,
	RT3000_MTP_ADDR_CVS_CSEL_Z,
	RT3000_MTP_ADDR_VS_X,
	RT3000_MTP_ADDR_VS_Y,
	RT3000_MTP_ADDR_VS_Z,
	RT3000_MTP_ADDR_OSC_TRIM,
	RT3000_MTP_ADDR_LDO_TRIM,
	RT3000_MTP_ADDR_WHO_AM_I,
	RT3000_MTP_ADDR_DLDO_TRIM,
	RT3000_MTP_ADDR_DOFS_24G_X,
	RT3000_MTP_ADDR_DOFS_86G_X,
	RT3000_MTP_ADDR_DOFS_24G_Y,
	RT3000_MTP_ADDR_DOFS_86G_Y,
	RT3000_MTP_ADDR_DOFS_24G_Z,
	RT3000_MTP_ADDR_DOFS_86G_Z,
	RT3000_MTP_ADDR_MEMS_ID1 = 0x3C,
	RT3000_MTP_ADDR_MEMS_ID2,
	RT3000_MTP_ADDR_MEMS_ID3,
	RT3000_MTP_ADDR_MEMS_ID4,
};

#endif
