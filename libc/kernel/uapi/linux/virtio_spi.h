/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _LINUX_VIRTIO_VIRTIO_SPI_H
#define _LINUX_VIRTIO_VIRTIO_SPI_H
#include <linux/types.h>
#include <linux/virtio_config.h>
#include <linux/virtio_ids.h>
#include <linux/virtio_types.h>
#define VIRTIO_SPI_CPHA _BITUL(0)
#define VIRTIO_SPI_CPOL _BITUL(1)
#define VIRTIO_SPI_CS_HIGH _BITUL(2)
#define VIRTIO_SPI_MODE_LSB_FIRST _BITUL(3)
#define VIRTIO_SPI_MODE_LOOP _BITUL(4)
struct virtio_spi_config {
  __u8 cs_max_number;
  __u8 cs_change_supported;
#define VIRTIO_SPI_RX_TX_SUPPORT_DUAL _BITUL(0)
#define VIRTIO_SPI_RX_TX_SUPPORT_QUAD _BITUL(1)
#define VIRTIO_SPI_RX_TX_SUPPORT_OCTAL _BITUL(2)
  __u8 tx_nbits_supported;
  __u8 rx_nbits_supported;
  __le32 bits_per_word_mask;
#define VIRTIO_SPI_MF_SUPPORT_CPHA_0 _BITUL(0)
#define VIRTIO_SPI_MF_SUPPORT_CPHA_1 _BITUL(1)
#define VIRTIO_SPI_MF_SUPPORT_CPOL_0 _BITUL(2)
#define VIRTIO_SPI_MF_SUPPORT_CPOL_1 _BITUL(3)
#define VIRTIO_SPI_MF_SUPPORT_CS_HIGH _BITUL(4)
#define VIRTIO_SPI_MF_SUPPORT_LSB_FIRST _BITUL(5)
#define VIRTIO_SPI_MF_SUPPORT_LOOPBACK _BITUL(6)
  __le32 mode_func_supported;
  __le32 max_freq_hz;
  __le32 max_word_delay_ns;
  __le32 max_cs_setup_ns;
  __le32 max_cs_hold_ns;
  __le32 max_cs_inactive_ns;
};
struct spi_transfer_head {
  __u8 chip_select_id;
  __u8 bits_per_word;
  __u8 cs_change;
  __u8 tx_nbits;
  __u8 rx_nbits;
  __u8 reserved[3];
  __le32 mode;
  __le32 freq;
  __le32 word_delay_ns;
  __le32 cs_setup_ns;
  __le32 cs_delay_hold_ns;
  __le32 cs_change_delay_inactive_ns;
};
struct spi_transfer_result {
#define VIRTIO_SPI_TRANS_OK 0
#define VIRTIO_SPI_PARAM_ERR 1
#define VIRTIO_SPI_TRANS_ERR 2
  __u8 result;
};
#endif
