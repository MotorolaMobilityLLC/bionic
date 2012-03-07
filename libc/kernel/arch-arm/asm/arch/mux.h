/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __ASM_ARCH_MUX_H
#define __ASM_ARCH_MUX_H
#define PU_PD_SEL_NA 0  
#define PULL_DWN_CTRL_NA 0  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define MUX_REG(reg, mode_offset, mode) .mux_reg = FUNC_MUX_CTRL_##reg,   .mask_offset = mode_offset,   .mask = mode,
#define PULL_REG(reg, bit, status) .pull_reg = PULL_DWN_CTRL_##reg,   .pull_bit = bit,   .pull_val = status,
#define PU_PD_REG(reg, status) .pu_pd_reg = PU_PD_SEL_##reg,   .pu_pd_val = status,
#define MUX_REG_730(reg, mode_offset, mode)   .mux_reg = OMAP730_IO_CONF_##reg,   .mask_offset = mode_offset,   .mask = mode,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define PULL_REG_730(reg, bit, status) .pull_reg = OMAP730_IO_CONF_##reg,   .pull_bit = bit,   .pull_val = status,
#define MUX_CFG(desc, mux_reg, mode_offset, mode,   pull_reg, pull_bit, pull_status,   pu_pd_reg, pu_pd_status, debug_status)  {   .name = desc,   .debug = debug_status,   MUX_REG(mux_reg, mode_offset, mode)   PULL_REG(pull_reg, pull_bit, !pull_status)   PU_PD_REG(pu_pd_reg, pu_pd_status)  },
#define MUX_CFG_730(desc, mux_reg, mode_offset, mode,   pull_bit, pull_status, debug_status) {   .name = desc,   .debug = debug_status,   MUX_REG_730(mux_reg, mode_offset, mode)   PULL_REG_730(mux_reg, pull_bit, pull_status)   PU_PD_REG(NA, 0)  },
#define MUX_CFG_24XX(desc, reg_offset, mode,   pull_en, pull_mode, dbg)  {   .name = desc,   .debug = dbg,   .mux_reg = reg_offset,   .mask = mode,   .pull_val = pull_en,   .pu_pd_val = pull_mode,  },
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define PULL_DISABLED 0
#define PULL_ENABLED 1
#define PULL_DOWN 0
#define PULL_UP 1
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct pin_config {
 char *name;
 unsigned char busy;
 unsigned char debug;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 const char *mux_reg_name;
 const unsigned int mux_reg;
 const unsigned char mask_offset;
 const unsigned char mask;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 const char *pull_name;
 const unsigned int pull_reg;
 const unsigned char pull_val;
 const unsigned char pull_bit;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 const char *pu_pd_name;
 const unsigned int pu_pd_reg;
 const unsigned char pu_pd_val;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum omap730_index {
 E2_730_KBR0,
 J7_730_KBR1,
 E1_730_KBR2,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 F3_730_KBR3,
 D2_730_KBR4,
 AA20_730_KBR5,
 V17_730_KBR6,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 C2_730_KBC0,
 D3_730_KBC1,
 E4_730_KBC2,
 F4_730_KBC3,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 E3_730_KBC4,
 AA17_730_USB_DM,
 W16_730_USB_PU_EN,
 W17_730_USB_VBUSI,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V19_730_GPIO_15,
 M19_730_GPIO_77,
 C21_730_GPIO_121_122,
 K19_730_GPIO_126,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 K15_730_GPIO_127,
 P15_730_GPIO_16_17,
 M15_730_GPIO_83,
 N20_730_GPIO_82,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 N18_730_GPIO_81,
 N19_730_GPIO_80,
 L15_730_GPIO_76,
 UART1_CTS_RTS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_730_GPIOS_42_43,
 UART1_TX_RX,
 OMAP_730_GPIOS_40_41,
 UART1_USB_RX_TX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 UART1_USB_RTS,
 UART1_USB_CTS
};
enum omap1xxx_index {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 UART1_TX = 0,
 UART1_RTS,
 UART2_TX,
 UART2_RX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 UART2_CTS,
 UART2_RTS,
 UART3_TX,
 UART3_RX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 UART3_CTS,
 UART3_RTS,
 UART3_CLKREQ,
 UART3_BCLK,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 Y15_1610_UART3_RTS,
 PWT,
 PWL,
 R18_USB_VBUS,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 R18_1510_USB_GPIO0,
 W4_USB_PUEN,
 W4_USB_CLKO,
 W4_USB_HIGHZ,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 W4_GPIO58,
 USB1_SUSP,
 USB1_SEO,
 W13_1610_USB1_SE0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 USB1_TXEN,
 USB1_TXD,
 USB1_VP,
 USB1_VM,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 USB1_RCV,
 USB1_SPEED,
 R13_1610_USB1_SPEED,
 R13_1710_USB1_SE0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 USB2_SUSP,
 USB2_VP,
 USB2_TXEN,
 USB2_VM,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 USB2_RCV,
 USB2_SEO,
 USB2_TXD,
 R18_1510_GPIO0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 R19_1510_GPIO1,
 M14_1510_GPIO2,
 P18_1610_GPIO3,
 Y15_1610_GPIO17,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 R18_1710_GPIO0,
 V2_1710_GPIO10,
 N21_1710_GPIO14,
 W15_1710_GPIO40,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 MPUIO2,
 N15_1610_MPUIO2,
 MPUIO4,
 MPUIO5,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 T20_1610_MPUIO5,
 W11_1610_MPUIO6,
 V10_1610_MPUIO7,
 W11_1610_MPUIO9,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V10_1610_MPUIO10,
 W10_1610_MPUIO11,
 E20_1610_MPUIO13,
 U20_1610_MPUIO14,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 E19_1610_MPUIO15,
 MCBSP2_CLKR,
 MCBSP2_CLKX,
 MCBSP2_DR,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 MCBSP2_DX,
 MCBSP2_FSR,
 MCBSP2_FSX,
 MCBSP3_CLKX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 BALLOUT_V8_ARMIO3,
 N20_HDQ,
 W8_1610_MMC2_DAT0,
 V8_1610_MMC2_DAT1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 W15_1610_MMC2_DAT2,
 R10_1610_MMC2_DAT3,
 Y10_1610_MMC2_CLK,
 Y8_1610_MMC2_CMD,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V9_1610_MMC2_CMDDIR,
 V5_1610_MMC2_DATDIR0,
 W19_1610_MMC2_DATDIR1,
 R18_1610_MMC2_CLKIN,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 M19_1610_ETM_PSTAT0,
 L15_1610_ETM_PSTAT1,
 L18_1610_ETM_PSTAT2,
 L19_1610_ETM_D0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 J19_1610_ETM_D6,
 J18_1610_ETM_D7,
 P20_1610_GPIO4,
 V9_1610_GPIO7,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 W8_1610_GPIO9,
 N20_1610_GPIO11,
 N19_1610_GPIO13,
 P10_1610_GPIO22,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V5_1610_GPIO24,
 AA20_1610_GPIO_41,
 W19_1610_GPIO48,
 M7_1610_GPIO62,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V14_16XX_GPIO37,
 R9_16XX_GPIO18,
 L14_16XX_GPIO49,
 V19_1610_UWIRE_SCLK,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 U18_1610_UWIRE_SDI,
 W21_1610_UWIRE_SDO,
 N14_1610_UWIRE_CS0,
 P15_1610_UWIRE_CS3,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 N15_1610_UWIRE_CS1,
 U19_1610_SPIF_SCK,
 U18_1610_SPIF_DIN,
 P20_1610_SPIF_DIN,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 W21_1610_SPIF_DOUT,
 R18_1610_SPIF_DOUT,
 N14_1610_SPIF_CS0,
 N15_1610_SPIF_CS1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 T19_1610_SPIF_CS2,
 P15_1610_SPIF_CS3,
 L3_1610_FLASH_CS2B_OE,
 M8_1610_FLASH_CS2B_WE,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 MMC_CMD,
 MMC_DAT1,
 MMC_DAT2,
 MMC_DAT0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 MMC_CLK,
 MMC_DAT3,
 M15_1710_MMC_CLKI,
 P19_1710_MMC_CMDDIR,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 P20_1710_MMC_DATDIR0,
 W9_USB0_TXEN,
 AA9_USB0_VP,
 Y5_USB0_RCV,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 R9_USB0_VM,
 V6_USB0_TXD,
 W5_USB0_SE0,
 V9_USB0_SPEED,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V9_USB0_SUSP,
 W9_USB2_TXEN,
 AA9_USB2_VP,
 Y5_USB2_RCV,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 R9_USB2_VM,
 V6_USB2_TXD,
 W5_USB2_SE0,
 R13_1610_UART1_TX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V14_16XX_UART1_RX,
 R14_1610_UART1_CTS,
 AA15_1610_UART1_RTS,
 R9_16XX_UART2_RX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 L14_16XX_UART3_RX,
 I2C_SCL,
 I2C_SDA,
 F18_1610_KBC0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 D20_1610_KBC1,
 D19_1610_KBC2,
 E18_1610_KBC3,
 C21_1610_KBC4,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 G18_1610_KBR0,
 F19_1610_KBR1,
 H14_1610_KBR2,
 E20_1610_KBR3,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 E19_1610_KBR4,
 N19_1610_KBR5,
 T20_1610_LOW_PWR,
 V5_1710_MCLK_ON,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V5_1710_MCLK_OFF,
 R10_1610_MCLK_ON,
 R10_1610_MCLK_OFF,
 P11_1610_CF_CD2,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 R11_1610_CF_IOIS16,
 V10_1610_CF_IREQ,
 W10_1610_CF_RESET,
 W11_1610_CF_CD1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
enum omap24xx_index {
 M19_24XX_I2C1_SCL,
 L15_24XX_I2C1_SDA,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 J15_24XX_I2C2_SCL,
 H19_24XX_I2C2_SDA,
 W19_24XX_SYS_NIRQ,
 W14_24XX_SYS_CLKOUT,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 L3_GPMC_WAIT0,
 N7_GPMC_WAIT1,
 M1_GPMC_WAIT2,
 P1_GPMC_WAIT3,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 Y15_24XX_MCBSP2_CLKX,
 R14_24XX_MCBSP2_FSX,
 W15_24XX_MCBSP2_DR,
 V15_24XX_MCBSP2_DX,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 M21_242X_GPIO11,
 AA10_242X_GPIO13,
 AA6_242X_GPIO14,
 AA4_242X_GPIO15,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 Y11_242X_GPIO16,
 AA12_242X_GPIO17,
 AA8_242X_GPIO58,
 Y20_24XX_GPIO60,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 W4__24XX_GPIO74,
 M15_24XX_GPIO92,
 V14_24XX_GPIO117,
 V4_242X_GPIO49,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 W2_242X_GPIO50,
 U4_242X_GPIO51,
 V3_242X_GPIO52,
 V2_242X_GPIO53,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V6_242X_GPIO53,
 T4_242X_GPIO54,
 Y4_242X_GPIO54,
 T3_242X_GPIO55,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 U2_242X_GPIO56,
 AA10_242X_DMAREQ0,
 AA6_242X_DMAREQ1,
 E4_242X_DMAREQ2,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 G4_242X_DMAREQ3,
 D3_242X_DMAREQ4,
 E3_242X_DMAREQ5,
 P20_24XX_TSC_IRQ,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 K15_24XX_UART3_TX,
 K14_24XX_UART3_RX,
 G19_24XX_MMC_CLKO,
 H18_24XX_MMC_CMD,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 F20_24XX_MMC_DAT0,
 H14_24XX_MMC_DAT1,
 E19_24XX_MMC_DAT2,
 D19_24XX_MMC_DAT3,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 F19_24XX_MMC_DAT_DIR0,
 E20_24XX_MMC_DAT_DIR1,
 F18_24XX_MMC_DAT_DIR2,
 E18_24XX_MMC_DAT_DIR3,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 G18_24XX_MMC_CMD_DIR,
 H15_24XX_MMC_CLKI,
 T19_24XX_KBR0,
 R19_24XX_KBR1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 V18_24XX_KBR2,
 M21_24XX_KBR3,
 E5__24XX_KBR4,
 M18_24XX_KBR5,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 R20_24XX_KBC0,
 M14_24XX_KBC1,
 H19_24XX_KBC2,
 V17_24XX_KBC3,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 P21_24XX_KBC4,
 L14_24XX_KBC5,
 N19_24XX_KBC6,
 B3__24XX_KBR5,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 AA4_24XX_KBC2,
 B13_24XX_KBC6,
};
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
