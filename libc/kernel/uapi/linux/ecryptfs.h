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
#ifndef _LINUX_ECRYPTFS_H
#define _LINUX_ECRYPTFS_H
#define ECRYPTFS_VERSION_MAJOR 0x00
#define ECRYPTFS_VERSION_MINOR 0x04
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ECRYPTFS_SUPPORTED_FILE_VERSION 0x03
#define ECRYPTFS_VERSIONING_PASSPHRASE 0x00000001
#define ECRYPTFS_VERSIONING_PUBKEY 0x00000002
#define ECRYPTFS_VERSIONING_PLAINTEXT_PASSTHROUGH 0x00000004
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ECRYPTFS_VERSIONING_POLICY 0x00000008
#define ECRYPTFS_VERSIONING_XATTR 0x00000010
#define ECRYPTFS_VERSIONING_MULTKEY 0x00000020
#define ECRYPTFS_VERSIONING_DEVMISC 0x00000040
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ECRYPTFS_VERSIONING_HMAC 0x00000080
#define ECRYPTFS_VERSIONING_FILENAME_ENCRYPTION 0x00000100
#define ECRYPTFS_VERSIONING_GCM 0x00000200
#define ECRYPTFS_MAX_PASSWORD_LENGTH 64
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ECRYPTFS_MAX_PASSPHRASE_BYTES ECRYPTFS_MAX_PASSWORD_LENGTH
#define ECRYPTFS_SALT_SIZE 8
#define ECRYPTFS_SALT_SIZE_HEX (ECRYPTFS_SALT_SIZE*2)
#define ECRYPTFS_SIG_SIZE 8
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ECRYPTFS_SIG_SIZE_HEX (ECRYPTFS_SIG_SIZE*2)
#define ECRYPTFS_PASSWORD_SIG_SIZE ECRYPTFS_SIG_SIZE_HEX
#define ECRYPTFS_MAX_KEY_BYTES 64
#define ECRYPTFS_MAX_ENCRYPTED_KEY_BYTES 512
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ECRYPTFS_FILE_VERSION 0x03
#define ECRYPTFS_MAX_PKI_NAME_BYTES 16
#define RFC2440_CIPHER_DES3_EDE 0x02
#define RFC2440_CIPHER_CAST_5 0x03
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define RFC2440_CIPHER_BLOWFISH 0x04
#define RFC2440_CIPHER_AES_128 0x07
#define RFC2440_CIPHER_AES_192 0x08
#define RFC2440_CIPHER_AES_256 0x09
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define RFC2440_CIPHER_TWOFISH 0x0a
#define RFC2440_CIPHER_CAST_6 0x0b
#define RFC2440_CIPHER_RSA 0x01
struct ecryptfs_session_key {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ECRYPTFS_USERSPACE_SHOULD_TRY_TO_DECRYPT 0x00000001
#define ECRYPTFS_USERSPACE_SHOULD_TRY_TO_ENCRYPT 0x00000002
#define ECRYPTFS_CONTAINS_DECRYPTED_KEY 0x00000004
#define ECRYPTFS_CONTAINS_ENCRYPTED_KEY 0x00000008
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 flags;
 __u32 encrypted_key_size;
 __u32 decrypted_key_size;
 __u8 encrypted_key[ECRYPTFS_MAX_ENCRYPTED_KEY_BYTES];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 decrypted_key[ECRYPTFS_MAX_KEY_BYTES];
};
struct ecryptfs_password {
 __u32 password_bytes;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __s32 hash_algo;
 __u32 hash_iterations;
 __u32 session_key_encryption_key_bytes;
#define ECRYPTFS_PERSISTENT_PASSWORD 0x01
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ECRYPTFS_SESSION_KEY_ENCRYPTION_KEY_SET 0x02
 __u32 flags;
 __u8 session_key_encryption_key[ECRYPTFS_MAX_KEY_BYTES];
 __u8 signature[ECRYPTFS_PASSWORD_SIG_SIZE + 1];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 salt[ECRYPTFS_SALT_SIZE];
};
enum ecryptfs_token_types {ECRYPTFS_PASSWORD, ECRYPTFS_PRIVATE_KEY};
struct ecryptfs_private_key {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 key_size;
 __u32 data_len;
 __u8 signature[ECRYPTFS_PASSWORD_SIG_SIZE + 1];
 char pki_type[ECRYPTFS_MAX_PKI_NAME_BYTES + 1];
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 data[];
};
struct ecryptfs_auth_tok {
 __u16 version;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 token_type;
#define ECRYPTFS_ENCRYPT_ONLY 0x00000001
 __u32 flags;
 struct ecryptfs_session_key session_key;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 reserved[32];
 union {
 struct ecryptfs_password password;
 struct ecryptfs_private_key private_key;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 } token;
} __attribute__ ((packed));
#endif

