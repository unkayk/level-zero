/*
 *
 * Copyright (C) 2019-2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file zet_ddi.h
 * @version v1.13-r1.13.1
 *
 */
#ifndef _ZET_DDI_H
#define _ZET_DDI_H
#if defined(__cplusplus)
#pragma once
#endif
#include "zet_api.h"

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricProgrammableGetExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricProgrammableGetExp_t)(
    zet_device_handle_t,
    uint32_t*,
    zet_metric_programmable_exp_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricProgrammableGetPropertiesExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricProgrammableGetPropertiesExp_t)(
    zet_metric_programmable_exp_handle_t,
    zet_metric_programmable_exp_properties_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricProgrammableGetParamInfoExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricProgrammableGetParamInfoExp_t)(
    zet_metric_programmable_exp_handle_t,
    uint32_t*,
    zet_metric_programmable_param_info_exp_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricProgrammableGetParamValueInfoExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricProgrammableGetParamValueInfoExp_t)(
    zet_metric_programmable_exp_handle_t,
    uint32_t,
    uint32_t*,
    zet_metric_programmable_param_value_info_exp_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of MetricProgrammableExp functions pointers
typedef struct _zet_metric_programmable_exp_dditable_t
{
    zet_pfnMetricProgrammableGetExp_t                           pfnGetExp;
    zet_pfnMetricProgrammableGetPropertiesExp_t                 pfnGetPropertiesExp;
    zet_pfnMetricProgrammableGetParamInfoExp_t                  pfnGetParamInfoExp;
    zet_pfnMetricProgrammableGetParamValueInfoExp_t             pfnGetParamValueInfoExp;
} zet_metric_programmable_exp_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricProgrammableExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricProgrammableExpProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_metric_programmable_exp_dditable_t* pDdiTable                       ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetMetricProgrammableExpProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetMetricProgrammableExpProcAddrTable_t)(
    ze_api_version_t,
    zet_metric_programmable_exp_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricTracerCreateExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricTracerCreateExp_t)(
    zet_context_handle_t,
    zet_device_handle_t,
    uint32_t,
    zet_metric_group_handle_t*,
    zet_metric_tracer_exp_desc_t*,
    ze_event_handle_t,
    zet_metric_tracer_exp_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricTracerDestroyExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricTracerDestroyExp_t)(
    zet_metric_tracer_exp_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricTracerEnableExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricTracerEnableExp_t)(
    zet_metric_tracer_exp_handle_t,
    ze_bool_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricTracerDisableExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricTracerDisableExp_t)(
    zet_metric_tracer_exp_handle_t,
    ze_bool_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricTracerReadDataExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricTracerReadDataExp_t)(
    zet_metric_tracer_exp_handle_t,
    size_t*,
    uint8_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricTracerDecodeExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricTracerDecodeExp_t)(
    zet_metric_decoder_exp_handle_t,
    size_t*,
    uint8_t*,
    uint32_t,
    zet_metric_handle_t*,
    uint32_t*,
    uint32_t*,
    uint32_t*,
    zet_metric_entry_exp_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of MetricTracerExp functions pointers
typedef struct _zet_metric_tracer_exp_dditable_t
{
    zet_pfnMetricTracerCreateExp_t                              pfnCreateExp;
    zet_pfnMetricTracerDestroyExp_t                             pfnDestroyExp;
    zet_pfnMetricTracerEnableExp_t                              pfnEnableExp;
    zet_pfnMetricTracerDisableExp_t                             pfnDisableExp;
    zet_pfnMetricTracerReadDataExp_t                            pfnReadDataExp;
    zet_pfnMetricTracerDecodeExp_t                              pfnDecodeExp;
} zet_metric_tracer_exp_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricTracerExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricTracerExpProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_metric_tracer_exp_dditable_t* pDdiTable                             ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetMetricTracerExpProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetMetricTracerExpProcAddrTable_t)(
    ze_api_version_t,
    zet_metric_tracer_exp_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricDecoderCreateExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricDecoderCreateExp_t)(
    zet_metric_tracer_exp_handle_t,
    zet_metric_decoder_exp_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricDecoderDestroyExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricDecoderDestroyExp_t)(
    zet_metric_decoder_exp_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricDecoderGetDecodableMetricsExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricDecoderGetDecodableMetricsExp_t)(
    zet_metric_decoder_exp_handle_t,
    uint32_t*,
    zet_metric_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of MetricDecoderExp functions pointers
typedef struct _zet_metric_decoder_exp_dditable_t
{
    zet_pfnMetricDecoderCreateExp_t                             pfnCreateExp;
    zet_pfnMetricDecoderDestroyExp_t                            pfnDestroyExp;
    zet_pfnMetricDecoderGetDecodableMetricsExp_t                pfnGetDecodableMetricsExp;
} zet_metric_decoder_exp_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricDecoderExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricDecoderExpProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_metric_decoder_exp_dditable_t* pDdiTable                            ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetMetricDecoderExpProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetMetricDecoderExpProcAddrTable_t)(
    ze_api_version_t,
    zet_metric_decoder_exp_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDeviceGetDebugProperties 
typedef ze_result_t (ZE_APICALL *zet_pfnDeviceGetDebugProperties_t)(
    zet_device_handle_t,
    zet_device_debug_properties_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Device functions pointers
typedef struct _zet_device_dditable_t
{
    zet_pfnDeviceGetDebugProperties_t                           pfnGetDebugProperties;
} zet_device_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Device table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetDeviceProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_device_dditable_t* pDdiTable                                        ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetDeviceProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetDeviceProcAddrTable_t)(
    ze_api_version_t,
    zet_device_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDeviceGetConcurrentMetricGroupsExp 
typedef ze_result_t (ZE_APICALL *zet_pfnDeviceGetConcurrentMetricGroupsExp_t)(
    zet_device_handle_t,
    uint32_t,
    zet_metric_group_handle_t *,
    uint32_t *,
    uint32_t *
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDeviceCreateMetricGroupsFromMetricsExp 
typedef ze_result_t (ZE_APICALL *zet_pfnDeviceCreateMetricGroupsFromMetricsExp_t)(
    zet_device_handle_t,
    uint32_t,
    zet_metric_handle_t *,
    const char *,
    const char *,
    uint32_t *,
    zet_metric_group_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDeviceEnableMetricsExp 
typedef ze_result_t (ZE_APICALL *zet_pfnDeviceEnableMetricsExp_t)(
    zet_device_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDeviceDisableMetricsExp 
typedef ze_result_t (ZE_APICALL *zet_pfnDeviceDisableMetricsExp_t)(
    zet_device_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of DeviceExp functions pointers
typedef struct _zet_device_exp_dditable_t
{
    zet_pfnDeviceGetConcurrentMetricGroupsExp_t                 pfnGetConcurrentMetricGroupsExp;
    zet_pfnDeviceCreateMetricGroupsFromMetricsExp_t             pfnCreateMetricGroupsFromMetricsExp;
    zet_pfnDeviceEnableMetricsExp_t                             pfnEnableMetricsExp;
    zet_pfnDeviceDisableMetricsExp_t                            pfnDisableMetricsExp;
} zet_device_exp_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's DeviceExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetDeviceExpProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_device_exp_dditable_t* pDdiTable                                    ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetDeviceExpProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetDeviceExpProcAddrTable_t)(
    ze_api_version_t,
    zet_device_exp_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetContextActivateMetricGroups 
typedef ze_result_t (ZE_APICALL *zet_pfnContextActivateMetricGroups_t)(
    zet_context_handle_t,
    zet_device_handle_t,
    uint32_t,
    zet_metric_group_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Context functions pointers
typedef struct _zet_context_dditable_t
{
    zet_pfnContextActivateMetricGroups_t                        pfnActivateMetricGroups;
} zet_context_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Context table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetContextProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_context_dditable_t* pDdiTable                                       ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetContextProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetContextProcAddrTable_t)(
    ze_api_version_t,
    zet_context_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetCommandListAppendMetricStreamerMarker 
typedef ze_result_t (ZE_APICALL *zet_pfnCommandListAppendMetricStreamerMarker_t)(
    zet_command_list_handle_t,
    zet_metric_streamer_handle_t,
    uint32_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetCommandListAppendMetricQueryBegin 
typedef ze_result_t (ZE_APICALL *zet_pfnCommandListAppendMetricQueryBegin_t)(
    zet_command_list_handle_t,
    zet_metric_query_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetCommandListAppendMetricQueryEnd 
typedef ze_result_t (ZE_APICALL *zet_pfnCommandListAppendMetricQueryEnd_t)(
    zet_command_list_handle_t,
    zet_metric_query_handle_t,
    ze_event_handle_t,
    uint32_t,
    ze_event_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetCommandListAppendMetricMemoryBarrier 
typedef ze_result_t (ZE_APICALL *zet_pfnCommandListAppendMetricMemoryBarrier_t)(
    zet_command_list_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of CommandList functions pointers
typedef struct _zet_command_list_dditable_t
{
    zet_pfnCommandListAppendMetricStreamerMarker_t              pfnAppendMetricStreamerMarker;
    zet_pfnCommandListAppendMetricQueryBegin_t                  pfnAppendMetricQueryBegin;
    zet_pfnCommandListAppendMetricQueryEnd_t                    pfnAppendMetricQueryEnd;
    zet_pfnCommandListAppendMetricMemoryBarrier_t               pfnAppendMetricMemoryBarrier;
} zet_command_list_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's CommandList table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetCommandListProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_command_list_dditable_t* pDdiTable                                  ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetCommandListProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetCommandListProcAddrTable_t)(
    ze_api_version_t,
    zet_command_list_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetCommandListAppendMarkerExp 
typedef ze_result_t (ZE_APICALL *zet_pfnCommandListAppendMarkerExp_t)(
    zet_command_list_handle_t,
    zet_metric_group_handle_t,
    uint32_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of CommandListExp functions pointers
typedef struct _zet_command_list_exp_dditable_t
{
    zet_pfnCommandListAppendMarkerExp_t                         pfnAppendMarkerExp;
} zet_command_list_exp_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's CommandListExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetCommandListExpProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_command_list_exp_dditable_t* pDdiTable                              ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetCommandListExpProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetCommandListExpProcAddrTable_t)(
    ze_api_version_t,
    zet_command_list_exp_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetModuleGetDebugInfo 
typedef ze_result_t (ZE_APICALL *zet_pfnModuleGetDebugInfo_t)(
    zet_module_handle_t,
    zet_module_debug_info_format_t,
    size_t*,
    uint8_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Module functions pointers
typedef struct _zet_module_dditable_t
{
    zet_pfnModuleGetDebugInfo_t                                 pfnGetDebugInfo;
} zet_module_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Module table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetModuleProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_module_dditable_t* pDdiTable                                        ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetModuleProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetModuleProcAddrTable_t)(
    ze_api_version_t,
    zet_module_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetKernelGetProfileInfo 
typedef ze_result_t (ZE_APICALL *zet_pfnKernelGetProfileInfo_t)(
    zet_kernel_handle_t,
    zet_profile_properties_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Kernel functions pointers
typedef struct _zet_kernel_dditable_t
{
    zet_pfnKernelGetProfileInfo_t                               pfnGetProfileInfo;
} zet_kernel_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Kernel table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetKernelProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_kernel_dditable_t* pDdiTable                                        ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetKernelProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetKernelProcAddrTable_t)(
    ze_api_version_t,
    zet_kernel_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGet 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGet_t)(
    zet_metric_group_handle_t,
    uint32_t*,
    zet_metric_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGetProperties 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGetProperties_t)(
    zet_metric_handle_t,
    zet_metric_properties_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Metric functions pointers
typedef struct _zet_metric_dditable_t
{
    zet_pfnMetricGet_t                                          pfnGet;
    zet_pfnMetricGetProperties_t                                pfnGetProperties;
} zet_metric_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Metric table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_metric_dditable_t* pDdiTable                                        ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetMetricProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetMetricProcAddrTable_t)(
    ze_api_version_t,
    zet_metric_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricCreateFromProgrammableExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricCreateFromProgrammableExp_t)(
    zet_metric_programmable_exp_handle_t,
    zet_metric_programmable_param_value_exp_t*,
    uint32_t,
    const char*,
    const char*,
    uint32_t*,
    zet_metric_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricDestroyExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricDestroyExp_t)(
    zet_metric_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricCreateFromProgrammableExp2 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricCreateFromProgrammableExp2_t)(
    zet_metric_programmable_exp_handle_t,
    uint32_t,
    zet_metric_programmable_param_value_exp_t*,
    const char*,
    const char*,
    uint32_t*,
    zet_metric_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of MetricExp functions pointers
typedef struct _zet_metric_exp_dditable_t
{
    zet_pfnMetricCreateFromProgrammableExp_t                    pfnCreateFromProgrammableExp;
    zet_pfnMetricDestroyExp_t                                   pfnDestroyExp;
    zet_pfnMetricCreateFromProgrammableExp2_t                   pfnCreateFromProgrammableExp2;
} zet_metric_exp_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricExpProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_metric_exp_dditable_t* pDdiTable                                    ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetMetricExpProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetMetricExpProcAddrTable_t)(
    ze_api_version_t,
    zet_metric_exp_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGroupGet 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGroupGet_t)(
    zet_device_handle_t,
    uint32_t*,
    zet_metric_group_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGroupGetProperties 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGroupGetProperties_t)(
    zet_metric_group_handle_t,
    zet_metric_group_properties_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGroupCalculateMetricValues 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGroupCalculateMetricValues_t)(
    zet_metric_group_handle_t,
    zet_metric_group_calculation_type_t,
    size_t,
    const uint8_t*,
    uint32_t*,
    zet_typed_value_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of MetricGroup functions pointers
typedef struct _zet_metric_group_dditable_t
{
    zet_pfnMetricGroupGet_t                                     pfnGet;
    zet_pfnMetricGroupGetProperties_t                           pfnGetProperties;
    zet_pfnMetricGroupCalculateMetricValues_t                   pfnCalculateMetricValues;
} zet_metric_group_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricGroup table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricGroupProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_metric_group_dditable_t* pDdiTable                                  ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetMetricGroupProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetMetricGroupProcAddrTable_t)(
    ze_api_version_t,
    zet_metric_group_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGroupCalculateMultipleMetricValuesExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGroupCalculateMultipleMetricValuesExp_t)(
    zet_metric_group_handle_t,
    zet_metric_group_calculation_type_t,
    size_t,
    const uint8_t*,
    uint32_t*,
    uint32_t*,
    uint32_t*,
    zet_typed_value_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGroupGetGlobalTimestampsExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGroupGetGlobalTimestampsExp_t)(
    zet_metric_group_handle_t,
    ze_bool_t,
    uint64_t*,
    uint64_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGroupGetExportDataExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGroupGetExportDataExp_t)(
    zet_metric_group_handle_t,
    const uint8_t*,
    size_t,
    size_t*,
    uint8_t *
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGroupCalculateMetricExportDataExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGroupCalculateMetricExportDataExp_t)(
    ze_driver_handle_t,
    zet_metric_group_calculation_type_t,
    size_t,
    const uint8_t*,
    zet_metric_calculate_exp_desc_t*,
    uint32_t*,
    uint32_t*,
    uint32_t*,
    zet_typed_value_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGroupCreateExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGroupCreateExp_t)(
    zet_device_handle_t,
    const char*,
    const char*,
    zet_metric_group_sampling_type_flags_t,
    zet_metric_group_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGroupAddMetricExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGroupAddMetricExp_t)(
    zet_metric_group_handle_t,
    zet_metric_handle_t,
    size_t *,
    char*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGroupRemoveMetricExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGroupRemoveMetricExp_t)(
    zet_metric_group_handle_t,
    zet_metric_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGroupCloseExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGroupCloseExp_t)(
    zet_metric_group_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricGroupDestroyExp 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricGroupDestroyExp_t)(
    zet_metric_group_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of MetricGroupExp functions pointers
typedef struct _zet_metric_group_exp_dditable_t
{
    zet_pfnMetricGroupCalculateMultipleMetricValuesExp_t        pfnCalculateMultipleMetricValuesExp;
    zet_pfnMetricGroupGetGlobalTimestampsExp_t                  pfnGetGlobalTimestampsExp;
    zet_pfnMetricGroupGetExportDataExp_t                        pfnGetExportDataExp;
    zet_pfnMetricGroupCalculateMetricExportDataExp_t            pfnCalculateMetricExportDataExp;
    zet_pfnMetricGroupCreateExp_t                               pfnCreateExp;
    zet_pfnMetricGroupAddMetricExp_t                            pfnAddMetricExp;
    zet_pfnMetricGroupRemoveMetricExp_t                         pfnRemoveMetricExp;
    zet_pfnMetricGroupCloseExp_t                                pfnCloseExp;
    zet_pfnMetricGroupDestroyExp_t                              pfnDestroyExp;
} zet_metric_group_exp_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricGroupExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricGroupExpProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_metric_group_exp_dditable_t* pDdiTable                              ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetMetricGroupExpProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetMetricGroupExpProcAddrTable_t)(
    ze_api_version_t,
    zet_metric_group_exp_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricStreamerOpen 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricStreamerOpen_t)(
    zet_context_handle_t,
    zet_device_handle_t,
    zet_metric_group_handle_t,
    zet_metric_streamer_desc_t*,
    ze_event_handle_t,
    zet_metric_streamer_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricStreamerClose 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricStreamerClose_t)(
    zet_metric_streamer_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricStreamerReadData 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricStreamerReadData_t)(
    zet_metric_streamer_handle_t,
    uint32_t,
    size_t*,
    uint8_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of MetricStreamer functions pointers
typedef struct _zet_metric_streamer_dditable_t
{
    zet_pfnMetricStreamerOpen_t                                 pfnOpen;
    zet_pfnMetricStreamerClose_t                                pfnClose;
    zet_pfnMetricStreamerReadData_t                             pfnReadData;
} zet_metric_streamer_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricStreamer table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricStreamerProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_metric_streamer_dditable_t* pDdiTable                               ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetMetricStreamerProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetMetricStreamerProcAddrTable_t)(
    ze_api_version_t,
    zet_metric_streamer_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricQueryPoolCreate 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricQueryPoolCreate_t)(
    zet_context_handle_t,
    zet_device_handle_t,
    zet_metric_group_handle_t,
    const zet_metric_query_pool_desc_t*,
    zet_metric_query_pool_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricQueryPoolDestroy 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricQueryPoolDestroy_t)(
    zet_metric_query_pool_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of MetricQueryPool functions pointers
typedef struct _zet_metric_query_pool_dditable_t
{
    zet_pfnMetricQueryPoolCreate_t                              pfnCreate;
    zet_pfnMetricQueryPoolDestroy_t                             pfnDestroy;
} zet_metric_query_pool_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricQueryPool table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricQueryPoolProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_metric_query_pool_dditable_t* pDdiTable                             ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetMetricQueryPoolProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetMetricQueryPoolProcAddrTable_t)(
    ze_api_version_t,
    zet_metric_query_pool_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricQueryCreate 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricQueryCreate_t)(
    zet_metric_query_pool_handle_t,
    uint32_t,
    zet_metric_query_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricQueryDestroy 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricQueryDestroy_t)(
    zet_metric_query_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricQueryReset 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricQueryReset_t)(
    zet_metric_query_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetMetricQueryGetData 
typedef ze_result_t (ZE_APICALL *zet_pfnMetricQueryGetData_t)(
    zet_metric_query_handle_t,
    size_t*,
    uint8_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of MetricQuery functions pointers
typedef struct _zet_metric_query_dditable_t
{
    zet_pfnMetricQueryCreate_t                                  pfnCreate;
    zet_pfnMetricQueryDestroy_t                                 pfnDestroy;
    zet_pfnMetricQueryReset_t                                   pfnReset;
    zet_pfnMetricQueryGetData_t                                 pfnGetData;
} zet_metric_query_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's MetricQuery table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetMetricQueryProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_metric_query_dditable_t* pDdiTable                                  ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetMetricQueryProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetMetricQueryProcAddrTable_t)(
    ze_api_version_t,
    zet_metric_query_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetTracerExpCreate 
typedef ze_result_t (ZE_APICALL *zet_pfnTracerExpCreate_t)(
    zet_context_handle_t,
    const zet_tracer_exp_desc_t*,
    zet_tracer_exp_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetTracerExpDestroy 
typedef ze_result_t (ZE_APICALL *zet_pfnTracerExpDestroy_t)(
    zet_tracer_exp_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetTracerExpSetPrologues 
typedef ze_result_t (ZE_APICALL *zet_pfnTracerExpSetPrologues_t)(
    zet_tracer_exp_handle_t,
    zet_core_callbacks_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetTracerExpSetEpilogues 
typedef ze_result_t (ZE_APICALL *zet_pfnTracerExpSetEpilogues_t)(
    zet_tracer_exp_handle_t,
    zet_core_callbacks_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetTracerExpSetEnabled 
typedef ze_result_t (ZE_APICALL *zet_pfnTracerExpSetEnabled_t)(
    zet_tracer_exp_handle_t,
    ze_bool_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of TracerExp functions pointers
typedef struct _zet_tracer_exp_dditable_t
{
    zet_pfnTracerExpCreate_t                                    pfnCreate;
    zet_pfnTracerExpDestroy_t                                   pfnDestroy;
    zet_pfnTracerExpSetPrologues_t                              pfnSetPrologues;
    zet_pfnTracerExpSetEpilogues_t                              pfnSetEpilogues;
    zet_pfnTracerExpSetEnabled_t                                pfnSetEnabled;
} zet_tracer_exp_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's TracerExp table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetTracerExpProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_tracer_exp_dditable_t* pDdiTable                                    ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetTracerExpProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetTracerExpProcAddrTable_t)(
    ze_api_version_t,
    zet_tracer_exp_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDebugAttach 
typedef ze_result_t (ZE_APICALL *zet_pfnDebugAttach_t)(
    zet_device_handle_t,
    const zet_debug_config_t*,
    zet_debug_session_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDebugDetach 
typedef ze_result_t (ZE_APICALL *zet_pfnDebugDetach_t)(
    zet_debug_session_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDebugReadEvent 
typedef ze_result_t (ZE_APICALL *zet_pfnDebugReadEvent_t)(
    zet_debug_session_handle_t,
    uint64_t,
    zet_debug_event_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDebugAcknowledgeEvent 
typedef ze_result_t (ZE_APICALL *zet_pfnDebugAcknowledgeEvent_t)(
    zet_debug_session_handle_t,
    const zet_debug_event_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDebugInterrupt 
typedef ze_result_t (ZE_APICALL *zet_pfnDebugInterrupt_t)(
    zet_debug_session_handle_t,
    ze_device_thread_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDebugResume 
typedef ze_result_t (ZE_APICALL *zet_pfnDebugResume_t)(
    zet_debug_session_handle_t,
    ze_device_thread_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDebugReadMemory 
typedef ze_result_t (ZE_APICALL *zet_pfnDebugReadMemory_t)(
    zet_debug_session_handle_t,
    ze_device_thread_t,
    const zet_debug_memory_space_desc_t*,
    size_t,
    void*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDebugWriteMemory 
typedef ze_result_t (ZE_APICALL *zet_pfnDebugWriteMemory_t)(
    zet_debug_session_handle_t,
    ze_device_thread_t,
    const zet_debug_memory_space_desc_t*,
    size_t,
    const void*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDebugGetRegisterSetProperties 
typedef ze_result_t (ZE_APICALL *zet_pfnDebugGetRegisterSetProperties_t)(
    zet_device_handle_t,
    uint32_t*,
    zet_debug_regset_properties_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDebugReadRegisters 
typedef ze_result_t (ZE_APICALL *zet_pfnDebugReadRegisters_t)(
    zet_debug_session_handle_t,
    ze_device_thread_t,
    uint32_t,
    uint32_t,
    uint32_t,
    void*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDebugWriteRegisters 
typedef ze_result_t (ZE_APICALL *zet_pfnDebugWriteRegisters_t)(
    zet_debug_session_handle_t,
    ze_device_thread_t,
    uint32_t,
    uint32_t,
    uint32_t,
    void*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetDebugGetThreadRegisterSetProperties 
typedef ze_result_t (ZE_APICALL *zet_pfnDebugGetThreadRegisterSetProperties_t)(
    zet_debug_session_handle_t,
    ze_device_thread_t,
    uint32_t*,
    zet_debug_regset_properties_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Debug functions pointers
typedef struct _zet_debug_dditable_t
{
    zet_pfnDebugAttach_t                                        pfnAttach;
    zet_pfnDebugDetach_t                                        pfnDetach;
    zet_pfnDebugReadEvent_t                                     pfnReadEvent;
    zet_pfnDebugAcknowledgeEvent_t                              pfnAcknowledgeEvent;
    zet_pfnDebugInterrupt_t                                     pfnInterrupt;
    zet_pfnDebugResume_t                                        pfnResume;
    zet_pfnDebugReadMemory_t                                    pfnReadMemory;
    zet_pfnDebugWriteMemory_t                                   pfnWriteMemory;
    zet_pfnDebugGetRegisterSetProperties_t                      pfnGetRegisterSetProperties;
    zet_pfnDebugReadRegisters_t                                 pfnReadRegisters;
    zet_pfnDebugWriteRegisters_t                                pfnWriteRegisters;
    zet_pfnDebugGetThreadRegisterSetProperties_t                pfnGetThreadRegisterSetProperties;
} zet_debug_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Debug table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zetGetDebugProcAddrTable(
    ze_api_version_t version,                                               ///< [in] API version requested
    zet_debug_dditable_t* pDdiTable                                         ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zetGetDebugProcAddrTable
typedef ze_result_t (ZE_APICALL *zet_pfnGetDebugProcAddrTable_t)(
    ze_api_version_t,
    zet_debug_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Container for all DDI tables
typedef struct _zet_dditable_t
{
    zet_metric_programmable_exp_dditable_t  MetricProgrammableExp;
    zet_metric_tracer_exp_dditable_t    MetricTracerExp;
    zet_metric_decoder_exp_dditable_t   MetricDecoderExp;
    zet_device_dditable_t               Device;
    zet_device_exp_dditable_t           DeviceExp;
    zet_context_dditable_t              Context;
    zet_command_list_dditable_t         CommandList;
    zet_command_list_exp_dditable_t     CommandListExp;
    zet_module_dditable_t               Module;
    zet_kernel_dditable_t               Kernel;
    zet_metric_dditable_t               Metric;
    zet_metric_exp_dditable_t           MetricExp;
    zet_metric_group_dditable_t         MetricGroup;
    zet_metric_group_exp_dditable_t     MetricGroupExp;
    zet_metric_streamer_dditable_t      MetricStreamer;
    zet_metric_query_pool_dditable_t    MetricQueryPool;
    zet_metric_query_dditable_t         MetricQuery;
    zet_tracer_exp_dditable_t           TracerExp;
    zet_debug_dditable_t                Debug;
} zet_dditable_t;
/// @brief Container for all DDI tables with version and tables set by the Driver
typedef struct _zet_dditable_driver_t
{
    ze_api_version_t    version;
    uint8_t             isValidFlag;
    zet_metric_programmable_exp_dditable_t *    MetricProgrammableExp;
    zet_metric_tracer_exp_dditable_t *  MetricTracerExp;
    zet_metric_decoder_exp_dditable_t * MetricDecoderExp;
    zet_device_dditable_t *             Device;
    zet_device_exp_dditable_t *         DeviceExp;
    zet_context_dditable_t *            Context;
    zet_command_list_dditable_t *       CommandList;
    zet_command_list_exp_dditable_t *   CommandListExp;
    zet_module_dditable_t *             Module;
    zet_kernel_dditable_t *             Kernel;
    zet_metric_dditable_t *             Metric;
    zet_metric_exp_dditable_t *         MetricExp;
    zet_metric_group_dditable_t *       MetricGroup;
    zet_metric_group_exp_dditable_t *   MetricGroupExp;
    zet_metric_streamer_dditable_t *    MetricStreamer;
    zet_metric_query_pool_dditable_t *  MetricQueryPool;
    zet_metric_query_dditable_t *       MetricQuery;
    zet_tracer_exp_dditable_t *         TracerExp;
    zet_debug_dditable_t *              Debug;
} zet_dditable_driver_t;

#if defined(__cplusplus)
} // extern "C"
#endif

#endif // _ZET_DDI_H