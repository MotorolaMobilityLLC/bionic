/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef __PSP_SEV_USER_H__
#define __PSP_SEV_USER_H__
#include <linux/types.h>
enum {
  SEV_FACTORY_RESET = 0,
  SEV_PLATFORM_STATUS,
  SEV_PEK_GEN,
  SEV_PEK_CSR,
  SEV_PDH_GEN,
  SEV_PDH_CERT_EXPORT,
  SEV_PEK_CERT_IMPORT,
  SEV_GET_ID,
  SEV_GET_ID2,
  SNP_PLATFORM_STATUS,
  SNP_COMMIT,
  SNP_SET_CONFIG,
  SNP_VLEK_LOAD,
  SEV_MAX,
};
typedef enum {
  SEV_RET_NO_FW_CALL = - 1,
  SEV_RET_SUCCESS = 0,
  SEV_RET_INVALID_PLATFORM_STATE = 0x0001,
  SEV_RET_INVALID_GUEST_STATE = 0x0002,
  SEV_RET_INAVLID_CONFIG = 0x0003,
  SEV_RET_INVALID_CONFIG = SEV_RET_INAVLID_CONFIG,
  SEV_RET_INVALID_LEN = 0x0004,
  SEV_RET_ALREADY_OWNED = 0x0005,
  SEV_RET_INVALID_CERTIFICATE = 0x0006,
  SEV_RET_POLICY_FAILURE = 0x0007,
  SEV_RET_INACTIVE = 0x0008,
  SEV_RET_INVALID_ADDRESS = 0x0009,
  SEV_RET_BAD_SIGNATURE = 0x000A,
  SEV_RET_BAD_MEASUREMENT = 0x000B,
  SEV_RET_ASID_OWNED = 0x000C,
  SEV_RET_INVALID_ASID = 0x000D,
  SEV_RET_WBINVD_REQUIRED = 0x000E,
  SEV_RET_DFFLUSH_REQUIRED = 0x000F,
  SEV_RET_INVALID_GUEST = 0x0010,
  SEV_RET_INVALID_COMMAND = 0x0011,
  SEV_RET_ACTIVE = 0x0012,
  SEV_RET_HWSEV_RET_PLATFORM = 0x0013,
  SEV_RET_HWSEV_RET_UNSAFE = 0x0014,
  SEV_RET_UNSUPPORTED = 0x0015,
  SEV_RET_INVALID_PARAM = 0x0016,
  SEV_RET_RESOURCE_LIMIT = 0x0017,
  SEV_RET_SECURE_DATA_INVALID = 0x0018,
  SEV_RET_INVALID_PAGE_SIZE = 0x0019,
  SEV_RET_INVALID_PAGE_STATE = 0x001A,
  SEV_RET_INVALID_MDATA_ENTRY = 0x001B,
  SEV_RET_INVALID_PAGE_OWNER = 0x001C,
  SEV_RET_AEAD_OFLOW = 0x001D,
  SEV_RET_EXIT_RING_BUFFER = 0x001F,
  SEV_RET_RMP_INIT_REQUIRED = 0x0020,
  SEV_RET_BAD_SVN = 0x0021,
  SEV_RET_BAD_VERSION = 0x0022,
  SEV_RET_SHUTDOWN_REQUIRED = 0x0023,
  SEV_RET_UPDATE_FAILED = 0x0024,
  SEV_RET_RESTORE_REQUIRED = 0x0025,
  SEV_RET_RMP_INITIALIZATION_FAILED = 0x0026,
  SEV_RET_INVALID_KEY = 0x0027,
  SEV_RET_SHUTDOWN_INCOMPLETE = 0x0028,
  SEV_RET_INCORRECT_BUFFER_LENGTH = 0x0030,
  SEV_RET_EXPAND_BUFFER_LENGTH_REQUEST = 0x0031,
  SEV_RET_SPDM_REQUEST = 0x0032,
  SEV_RET_SPDM_ERROR = 0x0033,
  SEV_RET_SEV_STATUS_ERR_IN_DEV_CONN = 0x0035,
  SEV_RET_SEV_STATUS_INVALID_DEV_CTX = 0x0036,
  SEV_RET_SEV_STATUS_INVALID_TDI_CTX = 0x0037,
  SEV_RET_SEV_STATUS_INVALID_TDI = 0x0038,
  SEV_RET_SEV_STATUS_RECLAIM_REQUIRED = 0x0039,
  SEV_RET_IN_USE = 0x003A,
  SEV_RET_SEV_STATUS_INVALID_DEV_STATE = 0x003B,
  SEV_RET_SEV_STATUS_INVALID_TDI_STATE = 0x003C,
  SEV_RET_SEV_STATUS_DEV_CERT_CHANGED = 0x003D,
  SEV_RET_SEV_STATUS_RESYNC_REQ = 0x003E,
  SEV_RET_SEV_STATUS_RESPONSE_TOO_LARGE = 0x003F,
  SEV_RET_MAX,
} sev_ret_code;
struct sev_user_data_status {
  __u8 api_major;
  __u8 api_minor;
  __u8 state;
  __u32 flags;
  __u8 build;
  __u32 guest_count;
} __attribute__((__packed__));
#define SEV_STATUS_FLAGS_CONFIG_ES 0x0100
struct sev_user_data_pek_csr {
  __u64 address;
  __u32 length;
} __attribute__((__packed__));
struct sev_user_data_pek_cert_import {
  __u64 pek_cert_address;
  __u32 pek_cert_len;
  __u64 oca_cert_address;
  __u32 oca_cert_len;
} __attribute__((__packed__));
struct sev_user_data_pdh_cert_export {
  __u64 pdh_cert_address;
  __u32 pdh_cert_len;
  __u64 cert_chain_address;
  __u32 cert_chain_len;
} __attribute__((__packed__));
struct sev_user_data_get_id {
  __u8 socket1[64];
  __u8 socket2[64];
} __attribute__((__packed__));
struct sev_user_data_get_id2 {
  __u64 address;
  __u32 length;
} __attribute__((__packed__));
struct sev_user_data_snp_status {
  __u8 api_major;
  __u8 api_minor;
  __u8 state;
  __u8 is_rmp_initialized : 1;
  __u8 rsvd : 7;
  __u32 build_id;
  __u32 mask_chip_id : 1;
  __u32 mask_chip_key : 1;
  __u32 vlek_en : 1;
  __u32 feature_info : 1;
  __u32 rapl_dis : 1;
  __u32 ciphertext_hiding_cap : 1;
  __u32 ciphertext_hiding_en : 1;
  __u32 rsvd1 : 25;
  __u32 guest_count;
  __u64 current_tcb_version;
  __u64 reported_tcb_version;
} __attribute__((__packed__));
struct sev_user_data_snp_config {
  __u64 reported_tcb;
  __u32 mask_chip_id : 1;
  __u32 mask_chip_key : 1;
  __u32 rsvd : 30;
  __u8 rsvd1[52];
} __attribute__((__packed__));
struct sev_user_data_snp_vlek_load {
  __u32 len;
  __u8 vlek_wrapped_version;
  __u8 rsvd[3];
  __u64 vlek_wrapped_address;
} __attribute__((__packed__));
struct sev_user_data_snp_wrapped_vlek_hashstick {
  __u8 data[432];
} __attribute__((__packed__));
struct sev_issue_cmd {
  __u32 cmd;
  __u64 data;
  __u32 error;
} __attribute__((__packed__));
#define SEV_IOC_TYPE 'S'
#define SEV_ISSUE_CMD _IOWR(SEV_IOC_TYPE, 0x0, struct sev_issue_cmd)
#endif
