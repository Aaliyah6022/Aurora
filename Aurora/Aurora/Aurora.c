#include "Aurora.h"

#define printf(...) DbgPrintEx(0, 0, __VA_ARGS__)

NTSTATUS DriverEntry(IN PDRIVER_OBJECT pDriverObject, IN PUNICODE_STRING pRegistryPath)
{
	NTSTATUS Status = STATUS_SUCCESS;

	UNREFERENCED_PARAMETER(pRegistryPath); 
	UNREFERENCED_PARAMETER(pDriverObject);

	UNICODE_STRING  drv_name;
	RtlInitUnicodeString(&drv_name, L"\\Driver\\aurora");
	IoCreateDriver(&drv_name, &real_main); //so it's kdmapper-able

	printf("this should never print\n");
	return Status;
}

NTSTATUS real_main(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath)
{
	UNREFERENCED_PARAMETER(pRegistryPath);
	UNICODE_STRING dev_name, sym_link;
	PDEVICE_OBJECT dev_obj;

	if (!pDriverObject)
		return STATUS_FAILED_DRIVER_ENTRY;

	RtlInitUnicodeString(&dev_name, L"\\Device\\aurora");
	auto status = IoCreateDevice(pDriverObject, 0, &dev_name, FILE_DEVICE_UNKNOWN, FILE_DEVICE_SECURE_OPEN, FALSE, &dev_obj);
	if (status != STATUS_SUCCESS) return status;

	RtlInitUnicodeString(&sym_link, L"\\DosDevices\\aurora");
	status = IoCreateSymbolicLink(&sym_link, &dev_name);
	if (status != STATUS_SUCCESS) return status;

	pDriverObject->DriverUnload = &OnDriverUnload;

	return status;
	printf("we are in\n");
	DebugMessage("shit we're in\n");
}

VOID OnDriverUnload(IN PDRIVER_OBJECT pDriverObject)
{
	NTSTATUS Status = STATUS_SUCCESS;

	UNREFERENCED_PARAMETER(pDriverObject);

	DebugMessage("Driver unload routine triggered!\n");
	printf("we are out\n");

	return Status;
}
