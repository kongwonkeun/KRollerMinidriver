//

#pragma once

#include "common.h"
#include <wdf.h>
#include <hidport.h>

EXTERN_C_START

typedef UCHAR   HID_REPORT_DESCRIPTOR, *PHID_REPORT_DESCRIPTOR;

DRIVER_INITIALIZE           DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD   EvtDeviceAdd;
EVT_WDF_TIMER               EvtTimerFunc;
EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL  EvtIoDeviceControl;

typedef struct _DEVICE_CONTEXT
{
    WDFDEVICE               device;
    WDFQUEUE                defaultQueue;
    WDFQUEUE                manualQueue;
    HID_DEVICE_ATTRIBUTES   hidDeviceAttributes;
    BYTE                    deviceData;
    HID_DESCRIPTOR          hidDescriptor;
    PHID_REPORT_DESCRIPTOR  reportDescriptor;
    BOOLEAN                 readReportDescFromRegistry;
}
DEVICE_CONTEXT,
*PDEVICE_CONTEXT;
WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEVICE_CONTEXT, GetDeviceContext);

typedef struct _QUEUE_CONTEXT
{
    WDFQUEUE                queue;
    PDEVICE_CONTEXT         deviceContext;
    UCHAR                   outputReport;
}
QUEUE_CONTEXT,
*PQUEUE_CONTEXT;
WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(QUEUE_CONTEXT, GetQueueContext);

typedef struct _MANUAL_QUEUE_CONTEXT
{
    WDFQUEUE                queue;
    PDEVICE_CONTEXT         deviceContext;
    WDFTIMER                timer;
}
MANUAL_QUEUE_CONTEXT,
*PMANUAL_QUEUE_CONTEXT;
WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(MANUAL_QUEUE_CONTEXT, GetManualQueueContext);

NTSTATUS QueueCreate(_In_ WDFDEVICE device, _Out_ WDFQUEUE *queue);
NTSTATUS ManualQueueCreate(_In_ WDFDEVICE device, _Out_ WDFQUEUE *queue);
NTSTATUS ReadReport(_In_ PQUEUE_CONTEXT queueContext, _In_ WDFREQUEST request, _Always_(_Out_) BOOLEAN *CompleteRequest);
NTSTATUS WriteReport(_In_ PQUEUE_CONTEXT queueContext, _In_ WDFREQUEST request);
NTSTATUS GetFeature(_In_ PQUEUE_CONTEXT queueContext, _In_ WDFREQUEST request);
NTSTATUS SetFeature(_In_ PQUEUE_CONTEXT queueContext, _In_ WDFREQUEST request);
NTSTATUS GetInputReport(_In_ PQUEUE_CONTEXT queueContext, _In_ WDFREQUEST request, _Always_(_Out_) BOOLEAN *CompleteRequest);
NTSTATUS SetOutputReport(_In_ PQUEUE_CONTEXT queueContext, _In_ WDFREQUEST request);
NTSTATUS GetString(_In_ WDFREQUEST request);
NTSTATUS GetIndexedString(_In_ WDFREQUEST request);
NTSTATUS GetStringId(_In_ WDFREQUEST request, _Out_ ULONG *stringId, _Out_ ULONG *languageId);
NTSTATUS RequestCopyFromBuffer(
    _In_ WDFREQUEST request,
    _In_ PVOID sourceBuffer,
    _When_(numBytesToCopyFrom == 0, __drv_reportError(numBytesToCopyFrom cannot be zero))
    _In_ size_t numBytesToCopyFrom
);
NTSTATUS RequestGetHidXferPacket_ToReadFromDevice(_In_ WDFREQUEST request, _Out_ HID_XFER_PACKET *packet);
NTSTATUS RequestGetHidXferPacket_ToWriteToDevice(_In_ WDFREQUEST request, _Out_ HID_XFER_PACKET *packet);
NTSTATUS CheckRegistryForDescriptor(_In_ WDFDEVICE device);
NTSTATUS ReadDescriptorFromRegistry(_In_ WDFDEVICE device);

// these are the device attributes returned by the mini driver in response to IOCTL_HID_GET_DEVICE_ATTRIBUTES.
#define HIDMINI_PID     0xFEED
#define HIDMINI_VID     0xDEED
#define HIDMINI_VERSION 0x0101

EXTERN_C_END

//
