#include <ntddk.h> 
#include <windef.h>

#include "message/debug.h"

#pragma warning(push)
#pragma warning(disable : 4100 4057 4024 4201)

// undocumented 
NTKERNELAPI NTSTATUS IoCreateDriver(PUNICODE_STRING DriverName, PDRIVER_INITIALIZE InitializationFunction);

NTSTATUS DriverEntry(IN PDRIVER_OBJECT pDriverObject, IN PUNICODE_STRING pRegistryPath);

NTSTATUS real_main(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath);

VOID OnDriverUnload(IN PDRIVER_OBJECT pDriverObject);