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
#ifndef __ASM_ARCH_DMA_H
#define __ASM_ARCH_DMA_H
#define OMAP_DMA_BASE (0xfffed800)
#define OMAP_DMA_GCR (OMAP_DMA_BASE + 0x400)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_GSCR (OMAP_DMA_BASE + 0x404)
#define OMAP_DMA_GRST (OMAP_DMA_BASE + 0x408)
#define OMAP_DMA_HW_ID (OMAP_DMA_BASE + 0x442)
#define OMAP_DMA_PCH2_ID (OMAP_DMA_BASE + 0x444)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_PCH0_ID (OMAP_DMA_BASE + 0x446)
#define OMAP_DMA_PCH1_ID (OMAP_DMA_BASE + 0x448)
#define OMAP_DMA_PCHG_ID (OMAP_DMA_BASE + 0x44a)
#define OMAP_DMA_PCHD_ID (OMAP_DMA_BASE + 0x44c)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_CAPS_0_U (OMAP_DMA_BASE + 0x44e)
#define OMAP_DMA_CAPS_0_L (OMAP_DMA_BASE + 0x450)
#define OMAP_DMA_CAPS_1_U (OMAP_DMA_BASE + 0x452)
#define OMAP_DMA_CAPS_1_L (OMAP_DMA_BASE + 0x454)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_CAPS_2 (OMAP_DMA_BASE + 0x456)
#define OMAP_DMA_CAPS_3 (OMAP_DMA_BASE + 0x458)
#define OMAP_DMA_CAPS_4 (OMAP_DMA_BASE + 0x45a)
#define OMAP_DMA_PCH2_SR (OMAP_DMA_BASE + 0x460)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_PCH0_SR (OMAP_DMA_BASE + 0x480)
#define OMAP_DMA_PCH1_SR (OMAP_DMA_BASE + 0x482)
#define OMAP_DMA_PCHD_SR (OMAP_DMA_BASE + 0x4c0)
#define OMAP24XX_DMA_BASE (L4_24XX_BASE + 0x56000)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA4_REVISION (OMAP24XX_DMA_BASE + 0x00)
#define OMAP_DMA4_GCR_REG (OMAP24XX_DMA_BASE + 0x78)
#define OMAP_DMA4_IRQSTATUS_L0 (OMAP24XX_DMA_BASE + 0x08)
#define OMAP_DMA4_IRQSTATUS_L1 (OMAP24XX_DMA_BASE + 0x0c)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA4_IRQSTATUS_L2 (OMAP24XX_DMA_BASE + 0x10)
#define OMAP_DMA4_IRQSTATUS_L3 (OMAP24XX_DMA_BASE + 0x14)
#define OMAP_DMA4_IRQENABLE_L0 (OMAP24XX_DMA_BASE + 0x18)
#define OMAP_DMA4_IRQENABLE_L1 (OMAP24XX_DMA_BASE + 0x1c)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA4_IRQENABLE_L2 (OMAP24XX_DMA_BASE + 0x20)
#define OMAP_DMA4_IRQENABLE_L3 (OMAP24XX_DMA_BASE + 0x24)
#define OMAP_DMA4_SYSSTATUS (OMAP24XX_DMA_BASE + 0x28)
#define OMAP_DMA4_CAPS_0 (OMAP24XX_DMA_BASE + 0x64)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA4_CAPS_2 (OMAP24XX_DMA_BASE + 0x6c)
#define OMAP_DMA4_CAPS_3 (OMAP24XX_DMA_BASE + 0x70)
#define OMAP_DMA4_CAPS_4 (OMAP24XX_DMA_BASE + 0x74)
#define OMAP_LOGICAL_DMA_CH_COUNT 32  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_CCR_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0x80)
#define OMAP_DMA_CLNK_CTRL_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0x84)
#define OMAP_DMA_CICR_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0x88)
#define OMAP_DMA_CSR_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0x8c)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_CSDP_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0x90)
#define OMAP_DMA_CEN_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0x94)
#define OMAP_DMA_CFN_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0x98)
#define OMAP_DMA_CSEI_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0xa4)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_CSFI_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0xa8)
#define OMAP_DMA_CDEI_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0xac)
#define OMAP_DMA_CDFI_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0xb0)
#define OMAP_DMA_CSAC_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0xb4)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_CDAC_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0xb8)
#define OMAP1_DMA_CSSA_L_REG(n) __REG16(OMAP_DMA_BASE + 0x40 * (n) + 0x08)
#define OMAP1_DMA_CSSA_U_REG(n) __REG16(OMAP_DMA_BASE + 0x40 * (n) + 0x0a)
#define OMAP1_DMA_CDSA_L_REG(n) __REG16(OMAP_DMA_BASE + 0x40 * (n) + 0x0c)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP1_DMA_CDSA_U_REG(n) __REG16(OMAP_DMA_BASE + 0x40 * (n) + 0x0e)
#define OMAP1_DMA_COLOR_L_REG(n) __REG16(OMAP_DMA_BASE + 0x40 * (n) + 0x20)
#define OMAP1_DMA_CCR2_REG(n) __REG16(OMAP_DMA_BASE + 0x40 * (n) + 0x24)
#define OMAP1_DMA_COLOR_U_REG(n) __REG16(OMAP_DMA_BASE + 0x40 * (n) + 0x22)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP1_DMA_LCH_CTRL_REG(n) __REG16(OMAP_DMA_BASE + 0x40 * (n) + 0x2a)
#define OMAP2_DMA_CSSA_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0x9c)
#define OMAP2_DMA_CDSA_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0xa0)
#define OMAP2_DMA_CCEN_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0xbc)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP2_DMA_CCFN_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0xc0)
#define OMAP2_DMA_COLOR_REG(n) __REG32(OMAP24XX_DMA_BASE + 0x60 * (n) + 0xc4)
#define OMAP_DMA_NO_DEVICE 0
#define OMAP_DMA_MCSI1_TX 1
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_MCSI1_RX 2
#define OMAP_DMA_I2C_RX 3
#define OMAP_DMA_I2C_TX 4
#define OMAP_DMA_EXT_NDMA_REQ 5
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_EXT_NDMA_REQ2 6
#define OMAP_DMA_UWIRE_TX 7
#define OMAP_DMA_MCBSP1_TX 8
#define OMAP_DMA_MCBSP1_RX 9
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_MCBSP3_TX 10
#define OMAP_DMA_MCBSP3_RX 11
#define OMAP_DMA_UART1_TX 12
#define OMAP_DMA_UART1_RX 13
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_UART2_TX 14
#define OMAP_DMA_UART2_RX 15
#define OMAP_DMA_MCBSP2_TX 16
#define OMAP_DMA_MCBSP2_RX 17
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_UART3_TX 18
#define OMAP_DMA_UART3_RX 19
#define OMAP_DMA_CAMERA_IF_RX 20
#define OMAP_DMA_MMC_TX 21
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_MMC_RX 22
#define OMAP_DMA_NAND 23
#define OMAP_DMA_IRQ_LCD_LINE 24
#define OMAP_DMA_MEMORY_STICK 25
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_USB_W2FC_RX0 26
#define OMAP_DMA_USB_W2FC_RX1 27
#define OMAP_DMA_USB_W2FC_RX2 28
#define OMAP_DMA_USB_W2FC_TX0 29
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_USB_W2FC_TX1 30
#define OMAP_DMA_USB_W2FC_TX2 31
#define OMAP_DMA_CRYPTO_DES_IN 32
#define OMAP_DMA_SPI_TX 33
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_SPI_RX 34
#define OMAP_DMA_CRYPTO_HASH 35
#define OMAP_DMA_CCP_ATTN 36
#define OMAP_DMA_CCP_FIFO_NOT_EMPTY 37
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_CMT_APE_TX_CHAN_0 38
#define OMAP_DMA_CMT_APE_RV_CHAN_0 39
#define OMAP_DMA_CMT_APE_TX_CHAN_1 40
#define OMAP_DMA_CMT_APE_RV_CHAN_1 41
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_CMT_APE_TX_CHAN_2 42
#define OMAP_DMA_CMT_APE_RV_CHAN_2 43
#define OMAP_DMA_CMT_APE_TX_CHAN_3 44
#define OMAP_DMA_CMT_APE_RV_CHAN_3 45
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_CMT_APE_TX_CHAN_4 46
#define OMAP_DMA_CMT_APE_RV_CHAN_4 47
#define OMAP_DMA_CMT_APE_TX_CHAN_5 48
#define OMAP_DMA_CMT_APE_RV_CHAN_5 49
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_CMT_APE_TX_CHAN_6 50
#define OMAP_DMA_CMT_APE_RV_CHAN_6 51
#define OMAP_DMA_CMT_APE_TX_CHAN_7 52
#define OMAP_DMA_CMT_APE_RV_CHAN_7 53
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_MMC2_TX 54
#define OMAP_DMA_MMC2_RX 55
#define OMAP_DMA_CRYPTO_DES_OUT 56
#define OMAP24XX_DMA_NO_DEVICE 0
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_XTI_DMA 1  
#define OMAP24XX_DMA_EXT_DMAREQ0 2  
#define OMAP24XX_DMA_EXT_DMAREQ1 3  
#define OMAP24XX_DMA_GPMC 4  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_GFX 5  
#define OMAP24XX_DMA_DSS 6  
#define OMAP24XX_DMA_VLYNQ_TX 7  
#define OMAP24XX_DMA_CWT 8  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_AES_TX 9  
#define OMAP24XX_DMA_AES_RX 10  
#define OMAP24XX_DMA_DES_TX 11  
#define OMAP24XX_DMA_DES_RX 12  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_SHA1MD5_RX 13  
#define OMAP24XX_DMA_EXT_DMAREQ2 14  
#define OMAP24XX_DMA_EXT_DMAREQ3 15  
#define OMAP24XX_DMA_EXT_DMAREQ4 16  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_EAC_AC_RD 17  
#define OMAP24XX_DMA_EAC_AC_WR 18  
#define OMAP24XX_DMA_EAC_MD_UL_RD 19  
#define OMAP24XX_DMA_EAC_MD_UL_WR 20  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_EAC_MD_DL_RD 21  
#define OMAP24XX_DMA_EAC_MD_DL_WR 22  
#define OMAP24XX_DMA_EAC_BT_UL_RD 23  
#define OMAP24XX_DMA_EAC_BT_UL_WR 24  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_EAC_BT_DL_RD 25  
#define OMAP24XX_DMA_EAC_BT_DL_WR 26  
#define OMAP24XX_DMA_I2C1_TX 27  
#define OMAP24XX_DMA_I2C1_RX 28  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_I2C2_TX 29  
#define OMAP24XX_DMA_I2C2_RX 30  
#define OMAP24XX_DMA_MCBSP1_TX 31  
#define OMAP24XX_DMA_MCBSP1_RX 32  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_MCBSP2_TX 33  
#define OMAP24XX_DMA_MCBSP2_RX 34  
#define OMAP24XX_DMA_SPI1_TX0 35  
#define OMAP24XX_DMA_SPI1_RX0 36  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_SPI1_TX1 37  
#define OMAP24XX_DMA_SPI1_RX1 38  
#define OMAP24XX_DMA_SPI1_TX2 39  
#define OMAP24XX_DMA_SPI1_RX2 40  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_SPI1_TX3 41  
#define OMAP24XX_DMA_SPI1_RX3 42  
#define OMAP24XX_DMA_SPI2_TX0 43  
#define OMAP24XX_DMA_SPI2_RX0 44  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_SPI2_TX1 45  
#define OMAP24XX_DMA_SPI2_RX1 46  
#define OMAP24XX_DMA_UART1_TX 49  
#define OMAP24XX_DMA_UART1_RX 50  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_UART2_TX 51  
#define OMAP24XX_DMA_UART2_RX 52  
#define OMAP24XX_DMA_UART3_TX 53  
#define OMAP24XX_DMA_UART3_RX 54  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_USB_W2FC_TX0 55  
#define OMAP24XX_DMA_USB_W2FC_RX0 56  
#define OMAP24XX_DMA_USB_W2FC_TX1 57  
#define OMAP24XX_DMA_USB_W2FC_RX1 58  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_USB_W2FC_TX2 59  
#define OMAP24XX_DMA_USB_W2FC_RX2 60  
#define OMAP24XX_DMA_MMC1_TX 61  
#define OMAP24XX_DMA_MMC1_RX 62  
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP24XX_DMA_MS 63  
#define OMAP24XX_DMA_EXT_DMAREQ5 64  
#define OMAP1510_DMA_LCD_BASE (0xfffedb00)
#define OMAP1510_DMA_LCD_CTRL (OMAP1510_DMA_LCD_BASE + 0x00)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP1510_DMA_LCD_TOP_F1_L (OMAP1510_DMA_LCD_BASE + 0x02)
#define OMAP1510_DMA_LCD_TOP_F1_U (OMAP1510_DMA_LCD_BASE + 0x04)
#define OMAP1510_DMA_LCD_BOT_F1_L (OMAP1510_DMA_LCD_BASE + 0x06)
#define OMAP1510_DMA_LCD_BOT_F1_U (OMAP1510_DMA_LCD_BASE + 0x08)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP1610_DMA_LCD_BASE (0xfffee300)
#define OMAP1610_DMA_LCD_CSDP (OMAP1610_DMA_LCD_BASE + 0xc0)
#define OMAP1610_DMA_LCD_CCR (OMAP1610_DMA_LCD_BASE + 0xc2)
#define OMAP1610_DMA_LCD_CTRL (OMAP1610_DMA_LCD_BASE + 0xc4)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP1610_DMA_LCD_TOP_B1_L (OMAP1610_DMA_LCD_BASE + 0xc8)
#define OMAP1610_DMA_LCD_TOP_B1_U (OMAP1610_DMA_LCD_BASE + 0xca)
#define OMAP1610_DMA_LCD_BOT_B1_L (OMAP1610_DMA_LCD_BASE + 0xcc)
#define OMAP1610_DMA_LCD_BOT_B1_U (OMAP1610_DMA_LCD_BASE + 0xce)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP1610_DMA_LCD_TOP_B2_L (OMAP1610_DMA_LCD_BASE + 0xd0)
#define OMAP1610_DMA_LCD_TOP_B2_U (OMAP1610_DMA_LCD_BASE + 0xd2)
#define OMAP1610_DMA_LCD_BOT_B2_L (OMAP1610_DMA_LCD_BASE + 0xd4)
#define OMAP1610_DMA_LCD_BOT_B2_U (OMAP1610_DMA_LCD_BASE + 0xd6)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP1610_DMA_LCD_SRC_EI_B1 (OMAP1610_DMA_LCD_BASE + 0xd8)
#define OMAP1610_DMA_LCD_SRC_FI_B1_L (OMAP1610_DMA_LCD_BASE + 0xda)
#define OMAP1610_DMA_LCD_SRC_EN_B1 (OMAP1610_DMA_LCD_BASE + 0xe0)
#define OMAP1610_DMA_LCD_SRC_FN_B1 (OMAP1610_DMA_LCD_BASE + 0xe4)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP1610_DMA_LCD_LCH_CTRL (OMAP1610_DMA_LCD_BASE + 0xea)
#define OMAP1610_DMA_LCD_SRC_FI_B1_U (OMAP1610_DMA_LCD_BASE + 0xf4)
#define OMAP1_DMA_TOUT_IRQ (1 << 0)
#define OMAP_DMA_DROP_IRQ (1 << 1)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_HALF_IRQ (1 << 2)
#define OMAP_DMA_FRAME_IRQ (1 << 3)
#define OMAP_DMA_LAST_IRQ (1 << 4)
#define OMAP_DMA_BLOCK_IRQ (1 << 5)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP1_DMA_SYNC_IRQ (1 << 6)
#define OMAP2_DMA_PKT_IRQ (1 << 7)
#define OMAP2_DMA_TRANS_ERR_IRQ (1 << 8)
#define OMAP2_DMA_SECURE_ERR_IRQ (1 << 9)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP2_DMA_SUPERVISOR_ERR_IRQ (1 << 10)
#define OMAP2_DMA_MISALIGNED_ERR_IRQ (1 << 11)
#define OMAP_DMA_DATA_TYPE_S8 0x00
#define OMAP_DMA_DATA_TYPE_S16 0x01
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_DATA_TYPE_S32 0x02
#define OMAP_DMA_SYNC_ELEMENT 0x00
#define OMAP_DMA_SYNC_FRAME 0x01
#define OMAP_DMA_SYNC_BLOCK 0x02
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_PORT_EMIFF 0x00
#define OMAP_DMA_PORT_EMIFS 0x01
#define OMAP_DMA_PORT_OCP_T1 0x02
#define OMAP_DMA_PORT_TIPB 0x03
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_PORT_OCP_T2 0x04
#define OMAP_DMA_PORT_MPUI 0x05
#define OMAP_DMA_AMODE_CONSTANT 0x00
#define OMAP_DMA_AMODE_POST_INC 0x01
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define OMAP_DMA_AMODE_SINGLE_IDX 0x02
#define OMAP_DMA_AMODE_DOUBLE_IDX 0x03
enum {
 OMAP_LCD_DMA_B1_TOP,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_LCD_DMA_B1_BOTTOM,
 OMAP_LCD_DMA_B2_TOP,
 OMAP_LCD_DMA_B2_BOTTOM
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum omap_dma_burst_mode {
 OMAP_DMA_DATA_BURST_DIS = 0,
 OMAP_DMA_DATA_BURST_4,
 OMAP_DMA_DATA_BURST_8,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DMA_DATA_BURST_16,
};
enum omap_dma_color_mode {
 OMAP_DMA_COLOR_DIS = 0,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DMA_CONSTANT_FILL,
 OMAP_DMA_TRANSPARENT_COPY
};
enum omap_dma_write_mode {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 OMAP_DMA_WRITE_NON_POSTED = 0,
 OMAP_DMA_WRITE_POSTED,
 OMAP_DMA_WRITE_LAST_NON_POSTED
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct omap_dma_channel_params {
 int data_type;
 int elem_count;
 int frame_count;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int src_port;
 int src_amode;
 unsigned long src_start;
 int src_ei;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int src_fi;
 int dst_port;
 int dst_amode;
 unsigned long dst_start;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int dst_ei;
 int dst_fi;
 int trigger;
 int sync_mode;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int src_or_dst_synch;
 int ie;
};
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
