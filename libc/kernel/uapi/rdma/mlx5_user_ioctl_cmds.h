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
#ifndef MLX5_USER_IOCTL_CMDS_H
#define MLX5_USER_IOCTL_CMDS_H
#include <linux/types.h>
#include <rdma/ib_user_ioctl_cmds.h>
enum mlx5_ib_create_flow_action_attrs {
  MLX5_IB_ATTR_CREATE_FLOW_ACTION_FLAGS = (1U << UVERBS_ID_NS_SHIFT),
};
enum mlx5_ib_alloc_dm_attrs {
  MLX5_IB_ATTR_ALLOC_DM_RESP_START_OFFSET = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_ATTR_ALLOC_DM_RESP_PAGE_INDEX,
};
enum mlx5_ib_devx_methods {
  MLX5_IB_METHOD_DEVX_OTHER = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_METHOD_DEVX_QUERY_UAR,
  MLX5_IB_METHOD_DEVX_QUERY_EQN,
};
enum mlx5_ib_devx_other_attrs {
  MLX5_IB_ATTR_DEVX_OTHER_CMD_IN = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_ATTR_DEVX_OTHER_CMD_OUT,
};
enum mlx5_ib_devx_obj_create_attrs {
  MLX5_IB_ATTR_DEVX_OBJ_CREATE_HANDLE = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_ATTR_DEVX_OBJ_CREATE_CMD_IN,
  MLX5_IB_ATTR_DEVX_OBJ_CREATE_CMD_OUT,
};
enum mlx5_ib_devx_query_uar_attrs {
  MLX5_IB_ATTR_DEVX_QUERY_UAR_USER_IDX = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_ATTR_DEVX_QUERY_UAR_DEV_IDX,
};
enum mlx5_ib_devx_obj_destroy_attrs {
  MLX5_IB_ATTR_DEVX_OBJ_DESTROY_HANDLE = (1U << UVERBS_ID_NS_SHIFT),
};
enum mlx5_ib_devx_obj_modify_attrs {
  MLX5_IB_ATTR_DEVX_OBJ_MODIFY_HANDLE = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_ATTR_DEVX_OBJ_MODIFY_CMD_IN,
  MLX5_IB_ATTR_DEVX_OBJ_MODIFY_CMD_OUT,
};
enum mlx5_ib_devx_obj_query_attrs {
  MLX5_IB_ATTR_DEVX_OBJ_QUERY_HANDLE = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_ATTR_DEVX_OBJ_QUERY_CMD_IN,
  MLX5_IB_ATTR_DEVX_OBJ_QUERY_CMD_OUT,
};
enum mlx5_ib_devx_query_eqn_attrs {
  MLX5_IB_ATTR_DEVX_QUERY_EQN_USER_VEC = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_ATTR_DEVX_QUERY_EQN_DEV_EQN,
};
enum mlx5_ib_devx_obj_methods {
  MLX5_IB_METHOD_DEVX_OBJ_CREATE = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_METHOD_DEVX_OBJ_DESTROY,
  MLX5_IB_METHOD_DEVX_OBJ_MODIFY,
  MLX5_IB_METHOD_DEVX_OBJ_QUERY,
};
enum mlx5_ib_devx_umem_reg_attrs {
  MLX5_IB_ATTR_DEVX_UMEM_REG_HANDLE = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_ATTR_DEVX_UMEM_REG_ADDR,
  MLX5_IB_ATTR_DEVX_UMEM_REG_LEN,
  MLX5_IB_ATTR_DEVX_UMEM_REG_ACCESS,
  MLX5_IB_ATTR_DEVX_UMEM_REG_OUT_ID,
};
enum mlx5_ib_devx_umem_dereg_attrs {
  MLX5_IB_ATTR_DEVX_UMEM_DEREG_HANDLE = (1U << UVERBS_ID_NS_SHIFT),
};
enum mlx5_ib_devx_umem_methods {
  MLX5_IB_METHOD_DEVX_UMEM_REG = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_METHOD_DEVX_UMEM_DEREG,
};
enum mlx5_ib_objects {
  MLX5_IB_OBJECT_DEVX = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_OBJECT_DEVX_OBJ,
  MLX5_IB_OBJECT_DEVX_UMEM,
  MLX5_IB_OBJECT_FLOW_MATCHER,
};
enum mlx5_ib_flow_matcher_create_attrs {
  MLX5_IB_ATTR_FLOW_MATCHER_CREATE_HANDLE = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_ATTR_FLOW_MATCHER_MATCH_MASK,
  MLX5_IB_ATTR_FLOW_MATCHER_FLOW_TYPE,
  MLX5_IB_ATTR_FLOW_MATCHER_MATCH_CRITERIA,
};
enum mlx5_ib_flow_matcher_destroy_attrs {
  MLX5_IB_ATTR_FLOW_MATCHER_DESTROY_HANDLE = (1U << UVERBS_ID_NS_SHIFT),
};
enum mlx5_ib_flow_matcher_methods {
  MLX5_IB_METHOD_FLOW_MATCHER_CREATE = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_METHOD_FLOW_MATCHER_DESTROY,
};
#define MLX5_IB_DW_MATCH_PARAM 0x80
struct mlx5_ib_match_params {
  __u32 match_params[MLX5_IB_DW_MATCH_PARAM];
};
enum mlx5_ib_flow_type {
  MLX5_IB_FLOW_TYPE_NORMAL,
  MLX5_IB_FLOW_TYPE_SNIFFER,
  MLX5_IB_FLOW_TYPE_ALL_DEFAULT,
  MLX5_IB_FLOW_TYPE_MC_DEFAULT,
};
enum mlx5_ib_create_flow_attrs {
  MLX5_IB_ATTR_CREATE_FLOW_HANDLE = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_ATTR_CREATE_FLOW_MATCH_VALUE,
  MLX5_IB_ATTR_CREATE_FLOW_DEST_QP,
  MLX5_IB_ATTR_CREATE_FLOW_DEST_DEVX,
  MLX5_IB_ATTR_CREATE_FLOW_MATCHER,
};
enum mlx5_ib_destoy_flow_attrs {
  MLX5_IB_ATTR_DESTROY_FLOW_HANDLE = (1U << UVERBS_ID_NS_SHIFT),
};
enum mlx5_ib_flow_methods {
  MLX5_IB_METHOD_CREATE_FLOW = (1U << UVERBS_ID_NS_SHIFT),
  MLX5_IB_METHOD_DESTROY_FLOW,
};
#endif
