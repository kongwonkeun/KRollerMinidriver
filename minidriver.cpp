//

#include "minidriver.h"

EXTERN_C_START

HID_REPORT_DESCRIPTOR   G_defaultReportDescriptor[] =
{
    // for hidmini control
    0x06,0x00,0xFF,     // USAGE_PAGE (Vender Defined Usage Page)
    0x09,0x01,          // USAGE (Vendor Usage 0x01)
    0xA1,0x01,          // COLLECTION (Application)
    0x85,REPORT_ID_CONTROL,
    0x09,0x01,          //   USAGE (Vendor Usage 0x01)
    0x15,0x00,          //   LOGICAL_MINIMUM(0)
    0x26,0xff,0x00,     //   LOGICAL_MAXIMUM(255)
    0x75,0x08,          //   REPORT_SIZE (0x08)
    0x96,(FEATURE_REPORT_SIZE_CB & 0xff),(FEATURE_REPORT_SIZE_CB >> 8), //   REPORT_COUNT
    0xB1,0x00,          //---FEATURE (Data, Ary, Abs)
    0x09,0x01,          //   USAGE (Vendor Usage 0x01)
    0x75,0x08,          //   REPORT_SIZE (0x08)
    0x96,(INPUT_REPORT_SIZE_CB & 0xff),(INPUT_REPORT_SIZE_CB >> 8),     //   REPORT_COUNT
    0x81,0x00,          //---INPUT (Data, Ary, Abs)
    0x09,0x01,          //   USAGE (Vendor Usage 0x01)
    0x75,0x08,          //   REPORT_SIZE (0x08)
    0x96,(OUTPUT_REPORT_SIZE_CB & 0xff),(OUTPUT_REPORT_SIZE_CB >> 8),   //   REPORT_COUNT
    0x91,0x00,          //---OUTPUT (Data, Ary, Abs)
    0xC0,               // END_COLLECTION

    // for mouse
    0x05,0x01,          // USAGE_PAGE (Generic Desktop)
    0x09,0x02,          // USAGE (Mouse)
    0xA1,0x01,          // COLLECTION (Application)
    0x85,REPORT_ID_MOUSE_INPUT,
    0x09,0x01,          //   USAGE (Pointer)
    0xA1,0x00,          //   COLLECTION (Physical)
    0x05,0x09,          //     USAGE_PAGE (Buttons)
    0x19,0x01,          //     USAGE_MINIMUM (1)
    0x29,0x03,          //     USAGE_MAXIMUM (3)
    0x15,0x00,          //     LOGICAL_MINIMUM (0)
    0x25,0x01,          //     LOGICAL_MAXIMUM (1)
    0x95,0x03,          //     REPORT_COUNT (3)
    0x75,0x01,          //     REPORT_SIZE (1)
    0x81,0x02,          //-----INPUT (Data, Variable, Absolute)
    0x95,0x01,          //     REPORT_COUNT (1)
    0x75,0x05,          //     REPORT_SIZE (5)
    0x81,0x01,          //-----INPUT (Constant)
    0x05,0x01,          //     USAGE_PAGE (Generic Desktop)
    0x09,0x30,          //     USAGE (X)
    0x09,0x31,          //     USAGE (Y)
    0x15,0x81,          //     LOGICAL_MINIMUM (-127)
    0x25,0x7F,          //     LOGICAL_MAXIMUM (127)
    0x75,0x08,          //     REPORT_SIZE (8)
    0x95,0x02,          //     REPORT_COUNT (2)
    0x81,0x06,          //-----Input (Data, Variable, Relative)
    0xC0,               //   END_COLLECTION
    0xC0,               // END_COLLECTION

    0x05,0x01,          // USAGE_PAGE (Generic Desktop)
    0x09,0x00,          // USAGE (Undefined)
    0xa1,0x01,          // COLLECTION (Application)
    0x85,REPORT_ID_MOUSE_OUTPUT,
    0x09,0x00,          //   USAGE (Undefined)
    0x15,0x00,          //   LOGICAL_MINIMUM (0)
    0x26,0xff,0x00,     //   LOGICAL_MAXIMUM (255)
    0x95,0x03,          //   REPORT_COUNT (3)
    0x75,0x08,          //   REPORT_SIZE (8)
    0x91,0x02,          //---OUTPUT (Data, Variable, Absolute)
    0xc0,               // END_COLLECTION

    // for keyboard
    0x05,0x01,          // USAGE_PAGE (Generic Desktop)
    0x09,0x06,          // USAGE (Keyboard)
    0xA1,0x01,          // COLLECTION (Application)
    0x85,REPORT_ID_KEYBOARD_INPUT,
    0x05,0x07,          //   USAGE_PAGE (Keyboard Key Codes)
    0x19,0xE0,          //   USAGE_MINIMUM (224)
    0x29,0xE7,          //   USAGE_MAXIMUM (231)
    0x15,0x00,          //   LOGICAL_MINIMUM (0)
    0x25,0x01,          //   LOGICAL_MAXIMUM (1)
    0x75,0x01,          //   REPORT_SIZE (1)
    0x95,0x08,          //   REPORT_COUNT (8)
    0x81,0x02,          //---INPUT (Data, Variable, Absolute)
    0x95,0x01,          //   REPORT_COUNT (1)
    0x75,0x08,          //   REPORT_SIZE (8)
    0x81,0x01,          //---INPUT (Constant)
    0x19,0x00,          //   USAGE_MINIMUM (0)
    0x29,0x65,          //   USAGE_MAXIMUM (101)
    0x15,0x00,          //   LOGICAL_MINIMUM (0)
    0x25,0x65,          //   LOGICAL_MAXIMUM (101)
    0x95,0x06,          //   REPORT_COUNT (6)
    0x75,0x08,          //   REPORT_SIZE (8)
    0x81,0x00,          //---INPUT (Data, Array, Absolute)
    0x05,0x08,          //   USAGE_PAGE (LEDs)
    0x19,0x01,          //   USAGE_MINIMUM (Num Lock)
    0x29,0x05,          //   USAGE_MAXIMUM (Kana)
    0x95,0x05,          //   REPORT_COUNT (5)
    0x75,0x01,          //   REPORT_SIZE (1)
    0x91,0x02,          //---OUTPUT (Data, Variable, Absolute)
    0x95,0x01,          //   REPORT_COUNT (1)
    0x75,0x03,          //   REPORT_SIZE (3)
    0x91,0x01,          //---OUTPUT (Constant)
    0xC0,               // END_COLLECTION

    0x05,0x01,          // USAGE_PAGE (Generic Desktop)
    0x09,0x00,          // USAGE (Undefined)
    0xa1,0x01,          // COLLECTION (Application)
    0x85,REPORT_ID_KEYBOARD_OUTPUT,
    0x09,0x00,          //   USAGE (Undefined)
    0x15,0x00,          //   LOGICAL_MINIMUM (0)
    0x26,0xff,0x00,     //   LOGICAL_MAXIMUM (255)
    0x95,0x08,          //   REPORT_COUNT (8)
    0x75,0x08,          //   REPORT_SIZE (8)
    0x91,0x02,          //---OUTPUT (Data, Variable, Absolute)*/
    0xc0                // END_COLLECTION
};

HID_DESCRIPTOR  G_defaultHidDescriptor =
{
    0x09,   // length of HID descriptor
    0x21,   // descriptor type == HID 0x21
    0x0100, // hid spec release
    0x00,   // country code == Not Specified
    0x01,   // number of HID class descriptors
    {       // DescriptorList[0]
        0x22,                               // report descriptor type 0x22
        sizeof(G_defaultReportDescriptor)   // total length of report descriptor
    }
};

NTSTATUS
DriverEntry(_In_ PDRIVER_OBJECT driverObject, _In_ PUNICODE_STRING registryPath)
{
    NTSTATUS status;
    WDF_DRIVER_CONFIG config;

    WDF_DRIVER_CONFIG_INIT(&config, EvtDeviceAdd);

    status = WdfDriverCreate(driverObject, registryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);
    if (!NT_SUCCESS(status)) {
        return status;
    }
    return status;
}

NTSTATUS
EvtDeviceAdd(_In_ WDFDRIVER driver, _Inout_ PWDFDEVICE_INIT deviceInit)
{
    NTSTATUS  status;
    WDFDEVICE device;
    PDEVICE_CONTEXT deviceContext;
    WDF_OBJECT_ATTRIBUTES  deviceAttributes;
    PHID_DEVICE_ATTRIBUTES hidAttributes;
    UNREFERENCED_PARAMETER(driver);

    // mark ourselves as a filter, which also relinquishes power policy ownership
    WdfFdoInitSetFilter(deviceInit);
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&deviceAttributes, DEVICE_CONTEXT);

    status = WdfDeviceCreate(&deviceInit, &deviceAttributes, &device);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    deviceContext = GetDeviceContext(device);
    deviceContext->device = device;
    deviceContext->deviceData = 0;

    hidAttributes = &deviceContext->hidDeviceAttributes;
    RtlZeroMemory(hidAttributes, sizeof(HID_DEVICE_ATTRIBUTES));

    hidAttributes->Size = sizeof(HID_DEVICE_ATTRIBUTES);
    hidAttributes->VendorID = HIDMINI_VID;
    hidAttributes->ProductID = HIDMINI_PID;
    hidAttributes->VersionNumber = HIDMINI_VERSION;

    status = QueueCreate(device, &deviceContext->defaultQueue);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    status = ManualQueueCreate(device, &deviceContext->manualQueue);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    // use default "HID Descriptor" (hardcoded)
    deviceContext->hidDescriptor = G_defaultHidDescriptor;

    status = CheckRegistryForDescriptor(device);
    if (NT_SUCCESS(status)) {
        status = ReadDescriptorFromRegistry(device);
        if (!NT_SUCCESS(status)) {
            //
        }
    }

    // we will use hard-coded report descriptor if registry one is not used.
    if (!NT_SUCCESS(status)) {
        deviceContext->reportDescriptor = G_defaultReportDescriptor;
        status = STATUS_SUCCESS;
    }
    return status;
}

void
EvtTimerFunc(_In_ WDFTIMER timer)
{
    NTSTATUS status;
    WDFQUEUE queue;
    WDFREQUEST request;
    PMANUAL_QUEUE_CONTEXT queueContext;
    HIDMINI_INPUT_REPORT  readReport;

    queue = (WDFQUEUE)WdfTimerGetParentObject(timer);
    queueContext = GetManualQueueContext(queue);

    // see if we have a request in manual queue
    status = WdfIoQueueRetrieveNextRequest(queueContext->queue, &request);
    if (NT_SUCCESS(status)) {
        readReport.reportId = REPORT_ID_CONTROL;
        readReport.data = queueContext->deviceContext->deviceData;
        status = RequestCopyFromBuffer(request, &readReport, sizeof(readReport));
        WdfRequestComplete(request, status);
    }
}

VOID
EvtIoDeviceControl(_In_ WDFQUEUE queue, _In_ WDFREQUEST request, _In_ size_t outputBufferLength, _In_ size_t inputBufferLength, _In_ ULONG ioControlCode)
{
    NTSTATUS status;
    BOOLEAN  completeRequest = TRUE;
    WDFDEVICE device = WdfIoQueueGetDevice(queue);
    PDEVICE_CONTEXT deviceContext = NULL;
    PQUEUE_CONTEXT  queueContext = GetQueueContext(queue);
    UNREFERENCED_PARAMETER(outputBufferLength);
    UNREFERENCED_PARAMETER(inputBufferLength);

    deviceContext = GetDeviceContext(device);

    switch (ioControlCode)
    {
    case IOCTL_HID_GET_DEVICE_DESCRIPTOR:
        _Analysis_assume_(deviceContext->hidDescriptor.bLength != 0);
        status = RequestCopyFromBuffer(request, &deviceContext->hidDescriptor, deviceContext->hidDescriptor.bLength);
        break;

    case IOCTL_HID_GET_DEVICE_ATTRIBUTES:
        status = RequestCopyFromBuffer(request, &queueContext->deviceContext->hidDeviceAttributes, sizeof(HID_DEVICE_ATTRIBUTES));
        break;

    case IOCTL_HID_GET_REPORT_DESCRIPTOR:
        status = RequestCopyFromBuffer(request, deviceContext->reportDescriptor, deviceContext->hidDescriptor.DescriptorList[0].wReportLength);
        break;

    case IOCTL_HID_READ_REPORT:
        status = ReadReport(queueContext, request, &completeRequest);
        break;

    case IOCTL_HID_WRITE_REPORT:
        status = WriteReport(queueContext, request);
        break;

    case IOCTL_UMDF_HID_GET_FEATURE:
        status = GetFeature(queueContext, request);
        break;

    case IOCTL_UMDF_HID_SET_FEATURE:
        status = SetFeature(queueContext, request);
        break;

    case IOCTL_UMDF_HID_GET_INPUT_REPORT:
        status = GetInputReport(queueContext, request, &completeRequest);
        break;

    case IOCTL_UMDF_HID_SET_OUTPUT_REPORT:
        status = SetOutputReport(queueContext, request);
        break;

    case IOCTL_HID_GET_STRING:
        status = GetString(request);
        break;

    case IOCTL_HID_GET_INDEXED_STRING:
        status = GetIndexedString(request);
        break;

    case IOCTL_HID_SEND_IDLE_NOTIFICATION_REQUEST:
    case IOCTL_HID_ACTIVATE_DEVICE:
    case IOCTL_HID_DEACTIVATE_DEVICE:
    case IOCTL_GET_PHYSICAL_DESCRIPTOR:
    default:
        status = STATUS_NOT_IMPLEMENTED;
        break;
    }

    // complete the request
    if (completeRequest) {
        WdfRequestComplete(request, status);
    }
}

NTSTATUS
QueueCreate(_In_ WDFDEVICE device, _Out_ WDFQUEUE *queue)
{
    NTSTATUS status;
    WDFQUEUE queue_;
    WDF_IO_QUEUE_CONFIG   queueConfig;
    WDF_OBJECT_ATTRIBUTES queueAttributes;
    PQUEUE_CONTEXT queueContext;

    WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(&queueConfig, WdfIoQueueDispatchSequential);

    // HIDclass uses INTERNAL_IOCTL which is not supported by UMDF
    // therefore the hidumdf.sys changes the IOCTL type to DEVICE_CONTROL for next stack and sends it down
    queueConfig.EvtIoDeviceControl = EvtIoDeviceControl;

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&queueAttributes, QUEUE_CONTEXT);

    status = WdfIoQueueCreate(device, &queueConfig, &queueAttributes, &queue_);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    queueContext = GetQueueContext(queue_);
    queueContext->queue = queue_;
    queueContext->deviceContext = GetDeviceContext(device);
    queueContext->outputReport = 0;

    *queue = queue_;
    return status;
}

//
// creates a manual queue to receive IOCTL_HID_READ_REPORT forwarded from the default queue handler
// creates a periodic timer to check and complete any pending request
// timer expiring is used to simulate a hardware event
//
// - hidclass.sys sends an ioctl to the miniport to read input report
// - request reaches the default queue. the request is forwarded to a manual queue temporarily
// - Later checks for any pending request in the manual queue, and then completes it
// - hidclass gets notified for the read request completionand return data to the caller
//
// On the other hand, for IOCTL_HID_WRITE_REPORT request, 
// the driver simply sends the request to the hardware and completes the request immediately
// there is no need to use another queue for write operation
//
NTSTATUS
ManualQueueCreate(_In_ WDFDEVICE device, _Out_ WDFQUEUE *queue)
{
    NTSTATUS status;
    WDFQUEUE queue_;
    WDF_IO_QUEUE_CONFIG   queueConfig;
    WDF_OBJECT_ATTRIBUTES queueAttributes;
    PMANUAL_QUEUE_CONTEXT queueContext;
    WDF_TIMER_CONFIG      timerConfig;
    WDF_OBJECT_ATTRIBUTES timerAttributes;
    ULONG timerPeriodInSeconds = 5;

    WDF_IO_QUEUE_CONFIG_INIT(&queueConfig, WdfIoQueueDispatchManual);
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&queueAttributes, MANUAL_QUEUE_CONTEXT);
    
    status = WdfIoQueueCreate(device, &queueConfig, &queueAttributes, &queue_);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    queueContext = GetManualQueueContext(queue_);
    queueContext->queue = queue_;
    queueContext->deviceContext = GetDeviceContext(device);

    WDF_TIMER_CONFIG_INIT_PERIODIC(&timerConfig, EvtTimerFunc, timerPeriodInSeconds * 1000);
    WDF_OBJECT_ATTRIBUTES_INIT(&timerAttributes);
    timerAttributes.ParentObject = queue_;

    status = WdfTimerCreate(&timerConfig, &timerAttributes, &queueContext->timer);
    if (!NT_SUCCESS(status)) {
        return status;
    }
    WdfTimerStart(queueContext->timer, WDF_REL_TIMEOUT_IN_SEC(1));

    *queue = queue_;
    return status;
}

NTSTATUS
ReadReport(_In_ PQUEUE_CONTEXT queueContext, _In_ WDFREQUEST request, _Always_(_Out_) BOOLEAN *completeRequest)
{
    NTSTATUS status;

    // forward the request to manual queue
    status = WdfRequestForwardToIoQueue(request, queueContext->deviceContext->manualQueue);
    if (!NT_SUCCESS(status)) {
        *completeRequest = TRUE;
    } else {
        *completeRequest = FALSE;
    }
    return status;
}

NTSTATUS
WriteReport(_In_ PQUEUE_CONTEXT queueContext, _In_ WDFREQUEST request)
{
    NTSTATUS status;
    HID_XFER_PACKET packet;
    PHIDMINI_OUTPUT_REPORT outputReport;
    ULONG reportSize;
    WDFREQUEST inputRequest;

    status = RequestGetHidXferPacket_ToWriteToDevice(request, &packet);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    if (packet.reportId == REPORT_ID_CONTROL)
    {
        reportSize = sizeof(HIDMINI_OUTPUT_REPORT);
        if (packet.reportBufferLen < reportSize) {
            status = STATUS_INVALID_BUFFER_SIZE;
            return status;
        }
        outputReport = (PHIDMINI_OUTPUT_REPORT)(packet.reportBuffer);
        queueContext->deviceContext->deviceData = outputReport->data;
    }
    else if (packet.reportId == REPORT_ID_MOUSE_OUTPUT) {
        packet.reportId = REPORT_ID_MOUSE_INPUT;
        packet.reportBuffer[0] = packet.reportId;
        reportSize = sizeof(HID_MOUSE_INPUT_REPORT);
        if (packet.reportBufferLen < reportSize) {
            status = STATUS_INVALID_BUFFER_SIZE;
            return status;
        }
        status = WdfIoQueueRetrieveNextRequest(queueContext->deviceContext->manualQueue, &inputRequest);
        if (!NT_SUCCESS(status)) {
            return status;
        }
        status = RequestCopyFromBuffer(inputRequest, packet.reportBuffer, reportSize);
        WdfRequestComplete(inputRequest, status);
    }
    else if (packet.reportId == REPORT_ID_KEYBOARD_OUTPUT) {
        packet.reportId = REPORT_ID_KEYBOARD_INPUT;
        packet.reportBuffer[0] = packet.reportId;
        reportSize = sizeof(HID_KEYBOARD_INPUT_REPORT);
        if (packet.reportBufferLen < reportSize) {
            status = STATUS_INVALID_BUFFER_SIZE;
            return status;
        }
        status = WdfIoQueueRetrieveNextRequest(queueContext->deviceContext->manualQueue, &inputRequest);
        if (!NT_SUCCESS(status)) {
            return status;
        }
        status = RequestCopyFromBuffer(inputRequest, packet.reportBuffer, reportSize);
        WdfRequestComplete(inputRequest, status);
    }
    else
    {
        status = STATUS_INVALID_PARAMETER;
        return status;
    }

    WdfRequestSetInformation(request, reportSize);
    return status;
}

NTSTATUS
GetFeature(_In_ PQUEUE_CONTEXT queueContext, _In_ WDFREQUEST request)
{
    NTSTATUS status;
    HID_XFER_PACKET packet;
    PMY_DEVICE_ATTRIBUTES  myAttributes;
    PHID_DEVICE_ATTRIBUTES hidAttributes = &queueContext->deviceContext->hidDeviceAttributes;
    ULONG reportSize;

    status = RequestGetHidXferPacket_ToReadFromDevice(request, &packet);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    if (packet.reportId != REPORT_ID_CONTROL) {
        status = STATUS_INVALID_PARAMETER;
        return status;
    }

    reportSize = sizeof(MY_DEVICE_ATTRIBUTES) + sizeof(packet.reportId);
    if (packet.reportBufferLen < reportSize) {
        status = STATUS_INVALID_BUFFER_SIZE;
        return status;
    }

    myAttributes = (PMY_DEVICE_ATTRIBUTES)(packet.reportBuffer + sizeof(packet.reportId));
    myAttributes->productId = hidAttributes->ProductID;
    myAttributes->vendorId = hidAttributes->VendorID;
    myAttributes->versionNumber = hidAttributes->VersionNumber;

    WdfRequestSetInformation(request, reportSize);
    return status;
}

NTSTATUS
SetFeature(_In_ PQUEUE_CONTEXT queueContext, _In_ WDFREQUEST request)
{
    NTSTATUS status;
    HID_XFER_PACKET packet;
    PHIDMINI_CONTROL_INFO  controlInfo;
    PHID_DEVICE_ATTRIBUTES hidAttributes = &queueContext->deviceContext->hidDeviceAttributes;
    ULONG reportSize;

    status = RequestGetHidXferPacket_ToWriteToDevice(request, &packet);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    if (packet.reportId != REPORT_ID_CONTROL) {
        status = STATUS_INVALID_PARAMETER;
        return status;
    }

    reportSize = sizeof(HIDMINI_CONTROL_INFO);
    if (packet.reportBufferLen < reportSize) {
        status = STATUS_INVALID_BUFFER_SIZE;
        return status;
    }

    controlInfo = (PHIDMINI_CONTROL_INFO)(packet.reportBuffer);

    switch (controlInfo->controlCode)
    {
    case HIDMINI_CONTROL_ATTRIBUTES:
        hidAttributes->ProductID     = controlInfo->u.attributes.productId;
        hidAttributes->VendorID      = controlInfo->u.attributes.vendorId;
        hidAttributes->VersionNumber = controlInfo->u.attributes.versionNumber;
        WdfRequestSetInformation(request, reportSize);
        break;

    default:
        status = STATUS_NOT_IMPLEMENTED;
        break;
    }

    return status;
}

NTSTATUS
GetInputReport(_In_ PQUEUE_CONTEXT queueContext, _In_ WDFREQUEST request, _Always_(_Out_) BOOLEAN *completeRequest)
{
    NTSTATUS status;
    HID_XFER_PACKET packet;
    PHIDMINI_INPUT_REPORT inputReport;
    ULONG reportSize;

    status = RequestGetHidXferPacket_ToReadFromDevice(request, &packet);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    if (packet.reportId == REPORT_ID_CONTROL)
    {
        reportSize = sizeof(HIDMINI_INPUT_REPORT);
        if (packet.reportBufferLen < reportSize) {
            status = STATUS_INVALID_BUFFER_SIZE;
            return status;
        }
        inputReport = (PHIDMINI_INPUT_REPORT)(packet.reportBuffer);
        inputReport->reportId = REPORT_ID_CONTROL;
        inputReport->data = queueContext->outputReport;
    }
    else if (packet.reportId == REPORT_ID_MOUSE_INPUT || packet.reportId == REPORT_ID_KEYBOARD_INPUT) {
        status = WdfRequestForwardToIoQueue(request, queueContext->deviceContext->manualQueue);
        if (!NT_SUCCESS(status)) {
            *completeRequest = TRUE;
        }
        else {
            *completeRequest = FALSE;
        }
        return status;
    }
    else
    {
        status = STATUS_INVALID_PARAMETER;
        return status;
    }

    WdfRequestSetInformation(request, reportSize);
    return status;
}

NTSTATUS
SetOutputReport(_In_ PQUEUE_CONTEXT queueContext, _In_ WDFREQUEST request)
{
    NTSTATUS status;
    HID_XFER_PACKET packet;
    PHIDMINI_OUTPUT_REPORT outputReport;
    ULONG reportSize;
    WDFREQUEST inputRequest;

    status = RequestGetHidXferPacket_ToWriteToDevice(request, &packet);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    if (packet.reportId == REPORT_ID_CONTROL)
    {
        reportSize = sizeof(HIDMINI_OUTPUT_REPORT);
        if (packet.reportBufferLen < reportSize) {
            status = STATUS_INVALID_BUFFER_SIZE;
            return status;
        }
        outputReport = (PHIDMINI_OUTPUT_REPORT)(packet.reportBuffer);
        queueContext->deviceContext->deviceData = outputReport->data;
    }
    else if (packet.reportId == REPORT_ID_MOUSE_OUTPUT) {
        packet.reportId = REPORT_ID_MOUSE_INPUT;
        packet.reportBuffer[0] = packet.reportId;
        reportSize = sizeof(HID_MOUSE_INPUT_REPORT);
        if (packet.reportBufferLen < reportSize) {
            status = STATUS_INVALID_BUFFER_SIZE;
            return status;
        }
        status = WdfIoQueueRetrieveNextRequest(queueContext->deviceContext->manualQueue, &inputRequest);
        if (!NT_SUCCESS(status)) {
            return status;
        }
        status = RequestCopyFromBuffer(inputRequest, packet.reportBuffer, reportSize);
        WdfRequestComplete(inputRequest, status);
    }
    else if (packet.reportId == REPORT_ID_KEYBOARD_OUTPUT) {
        packet.reportId = REPORT_ID_KEYBOARD_INPUT;
        packet.reportBuffer[0] = packet.reportId;
        reportSize = sizeof(HID_KEYBOARD_INPUT_REPORT);
        if (packet.reportBufferLen < reportSize) {
            status = STATUS_INVALID_BUFFER_SIZE;
            return status;
        }
        status = WdfIoQueueRetrieveNextRequest(queueContext->deviceContext->manualQueue, &inputRequest);
        if (!NT_SUCCESS(status)) {
            return status;
        }
        status = RequestCopyFromBuffer(inputRequest, packet.reportBuffer, reportSize);
        WdfRequestComplete(inputRequest, status);
    }
    else
    {
        status = STATUS_INVALID_PARAMETER;
        return status;
    }

    WdfRequestSetInformation(request, reportSize);
    return status;
}

NTSTATUS
GetString(_In_ WDFREQUEST request)
{
    NTSTATUS status;
    ULONG  languageId;
    ULONG  stringId;
    size_t stringSizeCb;
    PWSTR  string;

    status = GetStringId(request, &stringId, &languageId);
    UNREFERENCED_PARAMETER(languageId);

    if (!NT_SUCCESS(status)) {
        return status;
    }

    switch (stringId)
    {
    case HID_STRING_ID_IMANUFACTURER:
        stringSizeCb = sizeof(HIDMINI_MANUFACTURER_STRING);
        string = HIDMINI_MANUFACTURER_STRING;
        break;
    
    case HID_STRING_ID_IPRODUCT:
        stringSizeCb = sizeof(HIDMINI_PRODUCT_STRING);
        string = HIDMINI_PRODUCT_STRING;
        break;
    
    case HID_STRING_ID_ISERIALNUMBER:
        stringSizeCb = sizeof(HIDMINI_SERIAL_NUMBER_STRING);
        string = HIDMINI_SERIAL_NUMBER_STRING;
        break;
    
    default:
        status = STATUS_INVALID_PARAMETER;
        return status;
    }

    status = RequestCopyFromBuffer(request, string, stringSizeCb);
    return status;
}

NTSTATUS
GetIndexedString(_In_ WDFREQUEST request)
{
    NTSTATUS status;
    ULONG languageId;
    ULONG stringId;

    status = GetStringId(request, &stringId, &languageId);
    UNREFERENCED_PARAMETER(languageId);

    if (NT_SUCCESS(status)) {
        if (stringId != HIDMINI_DEVICE_STRING_INDEX)
        {
            status = STATUS_INVALID_PARAMETER;
            return status;
        }
        status = RequestCopyFromBuffer(request, HIDMINI_DEVICE_STRING, sizeof(HIDMINI_DEVICE_STRING));
    }
    return status;
}

NTSTATUS
GetStringId(_In_ WDFREQUEST request, _Out_ ULONG* stringId, _Out_ ULONG* languageId)
{
    NTSTATUS  status;
    WDFMEMORY inputMemory;
    size_t inputBufferLength;
    PVOID  inputBuffer;
    ULONG  inputValue;

    status = WdfRequestRetrieveInputMemory(request, &inputMemory);
    if (!NT_SUCCESS(status)) {
        return status;
    }
    inputBuffer = WdfMemoryGetBuffer(inputMemory, &inputBufferLength);

    if (inputBufferLength < sizeof(ULONG)) {
        status = STATUS_INVALID_BUFFER_SIZE;
        return status;
    }

    inputValue = (*(PULONG)inputBuffer);

    *stringId = (inputValue & 0x0ffff);
    *languageId = (inputValue >> 16);
    return status;
}

//
// driver copy data to the output buffer (towords app)
//
NTSTATUS
RequestCopyFromBuffer(_In_ WDFREQUEST request, _In_ PVOID sourceBuffer, _When_(numBytesToCopyFrom == 0, __drv_reportError(numBytesToCopyFrom cannot be zero)) _In_ size_t numBytesToCopyFrom)
{
    NTSTATUS  status;
    WDFMEMORY memory;
    size_t outputBufferLength;

    status = WdfRequestRetrieveOutputMemory(request, &memory);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    WdfMemoryGetBuffer(memory, &outputBufferLength);
    if (outputBufferLength < numBytesToCopyFrom) {
        status = STATUS_INVALID_BUFFER_SIZE;
        return status;
    }

    status = WdfMemoryCopyFromBuffer(memory, 0, sourceBuffer, numBytesToCopyFrom);
    if (!NT_SUCCESS(status)) {
        return status;
    }

    WdfRequestSetInformation(request, numBytesToCopyFrom);
    return status;
}

//
// HID minidriver IOCTL uses HID_XFER_PACKET
// 
// reportBuffer
// reportBufferLen
// reportId
//
// UMDF cannot handle embedded pointers when marshalling buffers between processes
// therefore a special driver mshiddumf.sys is introduced to convert such IRPs to new IRPs
//
// reportBuffer - passed as 1st buffer inside the IRP
// reportId - passed as 2nd buffer inside the IRP
//
// the new IRP is then passed to UMDF host and driver for further processing
//
NTSTATUS
RequestGetHidXferPacket_ToReadFromDevice(_In_ WDFREQUEST request, _Out_ HID_XFER_PACKET *packet)
{
    NTSTATUS  status;
    WDFMEMORY inputMemory;
    WDFMEMORY outputMemory;
    size_t inputBufferLength;
    size_t outputBufferLength;
    PVOID  inputBuffer;
    PVOID  outputBuffer;

    status = WdfRequestRetrieveInputMemory(request, &inputMemory);
    if (!NT_SUCCESS(status)) {
        return status;
    }
    inputBuffer = WdfMemoryGetBuffer(inputMemory, &inputBufferLength);
    if (inputBufferLength < sizeof(UCHAR)) {
        status = STATUS_INVALID_BUFFER_SIZE;
        return status;
    }

    // get id from input buffer
    packet->reportId = *(PUCHAR)inputBuffer;

    status = WdfRequestRetrieveOutputMemory(request, &outputMemory);
    if (!NT_SUCCESS(status)) {
        return status;
    }
    outputBuffer = WdfMemoryGetBuffer(outputMemory, &outputBufferLength);

    packet->reportBuffer = (PUCHAR)outputBuffer;
    packet->reportBufferLen = (ULONG)outputBufferLength;
    return status;
}

//
// HID minidriver IOCTL uses HID_XFER_PACKET
// 
// reportBuffer
// reportBufferLen
// reportId
//
// driver need to read from the input buffer (which was written by app)
//
// reportBuffer - input buffer
// reportId - from output buffer length (has reportId)
//
// the reportId is not stored inside the output buffer
// as the driver has no read-access rigth to the output buffer and
// trying to read from the buffer will cause an access violation error
// the workaround is to store the reportId in the outputBufferLength field
// to which the driver does have read-access right
//
NTSTATUS
RequestGetHidXferPacket_ToWriteToDevice(_In_ WDFREQUEST request, _Out_ HID_XFER_PACKET *packet)
{
    NTSTATUS  status;
    WDFMEMORY inputMemory;
    WDFMEMORY outputMemory;
    size_t inputBufferLength;
    size_t outputBufferLength;
    PVOID  inputBuffer;

    status = WdfRequestRetrieveOutputMemory(request, &outputMemory);
    if (!NT_SUCCESS(status)) {
        return status;
    }
    WdfMemoryGetBuffer(outputMemory, &outputBufferLength);

    // outputBufferLength field has reportId
    packet->reportId = (UCHAR)outputBufferLength;

    status = WdfRequestRetrieveInputMemory(request, &inputMemory);
    if (!NT_SUCCESS(status)) {
        return status;
    }
    inputBuffer = WdfMemoryGetBuffer(inputMemory, &inputBufferLength);

    packet->reportBuffer = (PUCHAR)inputBuffer;
    packet->reportBufferLen = (ULONG)inputBufferLength;
    return status;
}

//
// registry access functions
//
NTSTATUS
CheckRegistryForDescriptor(WDFDEVICE device)
{
    NTSTATUS status;
    UNICODE_STRING valueName;
    ULONG  value;
    WDFKEY hKey = NULL;

    status = WdfDeviceOpenRegistryKey(device, PLUGPLAY_REGKEY_DEVICE, KEY_READ, WDF_NO_OBJECT_ATTRIBUTES, &hKey);
    if (NT_SUCCESS(status))
    {
        RtlInitUnicodeString(&valueName, L"ReadFromRegistry");
        status = WdfRegistryQueryULong(hKey, &valueName, &value);
        if (NT_SUCCESS(status)) {
            if (value == 0) {
                status = STATUS_UNSUCCESSFUL;
            }
        }
        WdfRegistryClose(hKey);
    }
    return status;
}

NTSTATUS
ReadDescriptorFromRegistry(WDFDEVICE device)
{
    NTSTATUS  status;
    WDFMEMORY memory;
    UNICODE_STRING valueName;
    size_t bufferSize;
    PVOID  reportDescriptor;
    PDEVICE_CONTEXT deviceContext;
    WDF_OBJECT_ATTRIBUTES attributes;
    WDFKEY hKey = NULL;

    deviceContext = GetDeviceContext(device);

    status = WdfDeviceOpenRegistryKey(device, PLUGPLAY_REGKEY_DEVICE, KEY_READ, WDF_NO_OBJECT_ATTRIBUTES, &hKey);
    if (NT_SUCCESS(status))
    {
        RtlInitUnicodeString(&valueName, L"MyReportDescriptor");
        WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
        attributes.ParentObject = device;

        status = WdfRegistryQueryMemory(hKey, &valueName, NonPagedPool, &attributes, &memory, NULL);
        if (NT_SUCCESS(status))
        {
            reportDescriptor = WdfMemoryGetBuffer(memory, &bufferSize);

            deviceContext->readReportDescFromRegistry = TRUE;
            deviceContext->reportDescriptor = (PHID_REPORT_DESCRIPTOR)reportDescriptor;
            deviceContext->hidDescriptor.DescriptorList[0].wReportLength = (USHORT)bufferSize;
        }
        WdfRegistryClose(hKey);
    }
    return status;
}

EXTERN_C_END

//