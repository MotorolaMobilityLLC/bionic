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
#ifndef IB_USER_IOCTL_CMDS_H
#define IB_USER_IOCTL_CMDS_H
#define UVERBS_ID_NS_MASK 0xF000
#define UVERBS_ID_NS_SHIFT 12
#define UVERBS_UDATA_DRIVER_DATA_NS 1
#define UVERBS_UDATA_DRIVER_DATA_FLAG (1UL << UVERBS_ID_NS_SHIFT)
enum uverbs_default_objects {
  UVERBS_OBJECT_DEVICE,
  UVERBS_OBJECT_PD,
  UVERBS_OBJECT_COMP_CHANNEL,
  UVERBS_OBJECT_CQ,
  UVERBS_OBJECT_QP,
  UVERBS_OBJECT_SRQ,
  UVERBS_OBJECT_AH,
  UVERBS_OBJECT_MR,
  UVERBS_OBJECT_MW,
  UVERBS_OBJECT_FLOW,
  UVERBS_OBJECT_XRCD,
  UVERBS_OBJECT_RWQ_IND_TBL,
  UVERBS_OBJECT_WQ,
  UVERBS_OBJECT_FLOW_ACTION,
  UVERBS_OBJECT_DM,
  UVERBS_OBJECT_COUNTERS,
  UVERBS_OBJECT_ASYNC_EVENT,
};
enum {
  UVERBS_ATTR_UHW_IN = UVERBS_UDATA_DRIVER_DATA_FLAG,
  UVERBS_ATTR_UHW_OUT,
};
enum uverbs_methods_device {
  UVERBS_METHOD_INVOKE_WRITE,
  UVERBS_METHOD_INFO_HANDLES,
  UVERBS_METHOD_QUERY_PORT,
  UVERBS_METHOD_GET_CONTEXT,
};
enum uverbs_attrs_invoke_write_cmd_attr_ids {
  UVERBS_ATTR_CORE_IN,
  UVERBS_ATTR_CORE_OUT,
  UVERBS_ATTR_WRITE_CMD,
};
enum uverbs_attrs_query_port_cmd_attr_ids {
  UVERBS_ATTR_QUERY_PORT_PORT_NUM,
  UVERBS_ATTR_QUERY_PORT_RESP,
};
enum uverbs_attrs_get_context_attr_ids {
  UVERBS_ATTR_GET_CONTEXT_NUM_COMP_VECTORS,
  UVERBS_ATTR_GET_CONTEXT_CORE_SUPPORT,
};
enum uverbs_attrs_create_cq_cmd_attr_ids {
  UVERBS_ATTR_CREATE_CQ_HANDLE,
  UVERBS_ATTR_CREATE_CQ_CQE,
  UVERBS_ATTR_CREATE_CQ_USER_HANDLE,
  UVERBS_ATTR_CREATE_CQ_COMP_CHANNEL,
  UVERBS_ATTR_CREATE_CQ_COMP_VECTOR,
  UVERBS_ATTR_CREATE_CQ_FLAGS,
  UVERBS_ATTR_CREATE_CQ_RESP_CQE,
  UVERBS_ATTR_CREATE_CQ_EVENT_FD,
};
enum uverbs_attrs_destroy_cq_cmd_attr_ids {
  UVERBS_ATTR_DESTROY_CQ_HANDLE,
  UVERBS_ATTR_DESTROY_CQ_RESP,
};
enum uverbs_attrs_create_flow_action_esp {
  UVERBS_ATTR_CREATE_FLOW_ACTION_ESP_HANDLE,
  UVERBS_ATTR_FLOW_ACTION_ESP_ATTRS,
  UVERBS_ATTR_FLOW_ACTION_ESP_ESN,
  UVERBS_ATTR_FLOW_ACTION_ESP_KEYMAT,
  UVERBS_ATTR_FLOW_ACTION_ESP_REPLAY,
  UVERBS_ATTR_FLOW_ACTION_ESP_ENCAP,
};
enum uverbs_attrs_modify_flow_action_esp {
  UVERBS_ATTR_MODIFY_FLOW_ACTION_ESP_HANDLE = UVERBS_ATTR_CREATE_FLOW_ACTION_ESP_HANDLE,
};
enum uverbs_attrs_destroy_flow_action_esp {
  UVERBS_ATTR_DESTROY_FLOW_ACTION_HANDLE,
};
enum uverbs_attrs_create_qp_cmd_attr_ids {
  UVERBS_ATTR_CREATE_QP_HANDLE,
  UVERBS_ATTR_CREATE_QP_XRCD_HANDLE,
  UVERBS_ATTR_CREATE_QP_PD_HANDLE,
  UVERBS_ATTR_CREATE_QP_SRQ_HANDLE,
  UVERBS_ATTR_CREATE_QP_SEND_CQ_HANDLE,
  UVERBS_ATTR_CREATE_QP_RECV_CQ_HANDLE,
  UVERBS_ATTR_CREATE_QP_IND_TABLE_HANDLE,
  UVERBS_ATTR_CREATE_QP_USER_HANDLE,
  UVERBS_ATTR_CREATE_QP_CAP,
  UVERBS_ATTR_CREATE_QP_TYPE,
  UVERBS_ATTR_CREATE_QP_FLAGS,
  UVERBS_ATTR_CREATE_QP_SOURCE_QPN,
  UVERBS_ATTR_CREATE_QP_EVENT_FD,
  UVERBS_ATTR_CREATE_QP_RESP_CAP,
  UVERBS_ATTR_CREATE_QP_RESP_QP_NUM,
};
enum uverbs_attrs_destroy_qp_cmd_attr_ids {
  UVERBS_ATTR_DESTROY_QP_HANDLE,
  UVERBS_ATTR_DESTROY_QP_RESP,
};
enum uverbs_methods_qp {
  UVERBS_METHOD_QP_CREATE,
  UVERBS_METHOD_QP_DESTROY,
};
enum uverbs_attrs_create_srq_cmd_attr_ids {
  UVERBS_ATTR_CREATE_SRQ_HANDLE,
  UVERBS_ATTR_CREATE_SRQ_PD_HANDLE,
  UVERBS_ATTR_CREATE_SRQ_XRCD_HANDLE,
  UVERBS_ATTR_CREATE_SRQ_CQ_HANDLE,
  UVERBS_ATTR_CREATE_SRQ_USER_HANDLE,
  UVERBS_ATTR_CREATE_SRQ_MAX_WR,
  UVERBS_ATTR_CREATE_SRQ_MAX_SGE,
  UVERBS_ATTR_CREATE_SRQ_LIMIT,
  UVERBS_ATTR_CREATE_SRQ_MAX_NUM_TAGS,
  UVERBS_ATTR_CREATE_SRQ_TYPE,
  UVERBS_ATTR_CREATE_SRQ_EVENT_FD,
  UVERBS_ATTR_CREATE_SRQ_RESP_MAX_WR,
  UVERBS_ATTR_CREATE_SRQ_RESP_MAX_SGE,
  UVERBS_ATTR_CREATE_SRQ_RESP_SRQ_NUM,
};
enum uverbs_attrs_destroy_srq_cmd_attr_ids {
  UVERBS_ATTR_DESTROY_SRQ_HANDLE,
  UVERBS_ATTR_DESTROY_SRQ_RESP,
};
enum uverbs_methods_srq {
  UVERBS_METHOD_SRQ_CREATE,
  UVERBS_METHOD_SRQ_DESTROY,
};
enum uverbs_methods_cq {
  UVERBS_METHOD_CQ_CREATE,
  UVERBS_METHOD_CQ_DESTROY,
};
enum uverbs_attrs_create_wq_cmd_attr_ids {
  UVERBS_ATTR_CREATE_WQ_HANDLE,
  UVERBS_ATTR_CREATE_WQ_PD_HANDLE,
  UVERBS_ATTR_CREATE_WQ_CQ_HANDLE,
  UVERBS_ATTR_CREATE_WQ_USER_HANDLE,
  UVERBS_ATTR_CREATE_WQ_TYPE,
  UVERBS_ATTR_CREATE_WQ_EVENT_FD,
  UVERBS_ATTR_CREATE_WQ_MAX_WR,
  UVERBS_ATTR_CREATE_WQ_MAX_SGE,
  UVERBS_ATTR_CREATE_WQ_FLAGS,
  UVERBS_ATTR_CREATE_WQ_RESP_MAX_WR,
  UVERBS_ATTR_CREATE_WQ_RESP_MAX_SGE,
  UVERBS_ATTR_CREATE_WQ_RESP_WQ_NUM,
};
enum uverbs_attrs_destroy_wq_cmd_attr_ids {
  UVERBS_ATTR_DESTROY_WQ_HANDLE,
  UVERBS_ATTR_DESTROY_WQ_RESP,
};
enum uverbs_methods_wq {
  UVERBS_METHOD_WQ_CREATE,
  UVERBS_METHOD_WQ_DESTROY,
};
enum uverbs_methods_actions_flow_action_ops {
  UVERBS_METHOD_FLOW_ACTION_ESP_CREATE,
  UVERBS_METHOD_FLOW_ACTION_DESTROY,
  UVERBS_METHOD_FLOW_ACTION_ESP_MODIFY,
};
enum uverbs_attrs_alloc_dm_cmd_attr_ids {
  UVERBS_ATTR_ALLOC_DM_HANDLE,
  UVERBS_ATTR_ALLOC_DM_LENGTH,
  UVERBS_ATTR_ALLOC_DM_ALIGNMENT,
};
enum uverbs_attrs_free_dm_cmd_attr_ids {
  UVERBS_ATTR_FREE_DM_HANDLE,
};
enum uverbs_methods_dm {
  UVERBS_METHOD_DM_ALLOC,
  UVERBS_METHOD_DM_FREE,
};
enum uverbs_attrs_reg_dm_mr_cmd_attr_ids {
  UVERBS_ATTR_REG_DM_MR_HANDLE,
  UVERBS_ATTR_REG_DM_MR_OFFSET,
  UVERBS_ATTR_REG_DM_MR_LENGTH,
  UVERBS_ATTR_REG_DM_MR_PD_HANDLE,
  UVERBS_ATTR_REG_DM_MR_ACCESS_FLAGS,
  UVERBS_ATTR_REG_DM_MR_DM_HANDLE,
  UVERBS_ATTR_REG_DM_MR_RESP_LKEY,
  UVERBS_ATTR_REG_DM_MR_RESP_RKEY,
};
enum uverbs_methods_mr {
  UVERBS_METHOD_DM_MR_REG,
  UVERBS_METHOD_MR_DESTROY,
  UVERBS_METHOD_ADVISE_MR,
};
enum uverbs_attrs_mr_destroy_ids {
  UVERBS_ATTR_DESTROY_MR_HANDLE,
};
enum uverbs_attrs_advise_mr_cmd_attr_ids {
  UVERBS_ATTR_ADVISE_MR_PD_HANDLE,
  UVERBS_ATTR_ADVISE_MR_ADVICE,
  UVERBS_ATTR_ADVISE_MR_FLAGS,
  UVERBS_ATTR_ADVISE_MR_SGE_LIST,
};
enum uverbs_attrs_create_counters_cmd_attr_ids {
  UVERBS_ATTR_CREATE_COUNTERS_HANDLE,
};
enum uverbs_attrs_destroy_counters_cmd_attr_ids {
  UVERBS_ATTR_DESTROY_COUNTERS_HANDLE,
};
enum uverbs_attrs_read_counters_cmd_attr_ids {
  UVERBS_ATTR_READ_COUNTERS_HANDLE,
  UVERBS_ATTR_READ_COUNTERS_BUFF,
  UVERBS_ATTR_READ_COUNTERS_FLAGS,
};
enum uverbs_methods_actions_counters_ops {
  UVERBS_METHOD_COUNTERS_CREATE,
  UVERBS_METHOD_COUNTERS_DESTROY,
  UVERBS_METHOD_COUNTERS_READ,
};
enum uverbs_attrs_info_handles_id {
  UVERBS_ATTR_INFO_OBJECT_ID,
  UVERBS_ATTR_INFO_TOTAL_HANDLES,
  UVERBS_ATTR_INFO_HANDLES_LIST,
};
enum uverbs_methods_pd {
  UVERBS_METHOD_PD_DESTROY,
};
enum uverbs_attrs_pd_destroy_ids {
  UVERBS_ATTR_DESTROY_PD_HANDLE,
};
enum uverbs_methods_mw {
  UVERBS_METHOD_MW_DESTROY,
};
enum uverbs_attrs_mw_destroy_ids {
  UVERBS_ATTR_DESTROY_MW_HANDLE,
};
enum uverbs_methods_xrcd {
  UVERBS_METHOD_XRCD_DESTROY,
};
enum uverbs_attrs_xrcd_destroy_ids {
  UVERBS_ATTR_DESTROY_XRCD_HANDLE,
};
enum uverbs_methods_ah {
  UVERBS_METHOD_AH_DESTROY,
};
enum uverbs_attrs_ah_destroy_ids {
  UVERBS_ATTR_DESTROY_AH_HANDLE,
};
enum uverbs_methods_rwq_ind_tbl {
  UVERBS_METHOD_RWQ_IND_TBL_DESTROY,
};
enum uverbs_attrs_rwq_ind_tbl_destroy_ids {
  UVERBS_ATTR_DESTROY_RWQ_IND_TBL_HANDLE,
};
enum uverbs_methods_flow {
  UVERBS_METHOD_FLOW_DESTROY,
};
enum uverbs_attrs_flow_destroy_ids {
  UVERBS_ATTR_DESTROY_FLOW_HANDLE,
};
enum uverbs_method_async_event {
  UVERBS_METHOD_ASYNC_EVENT_ALLOC,
};
enum uverbs_attrs_async_event_create {
  UVERBS_ATTR_ASYNC_EVENT_ALLOC_FD_HANDLE,
};
#endif
