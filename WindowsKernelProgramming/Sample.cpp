//Each Driver has an entry point calld DriverEntry

//The function is called by a kernel/system space thread at IRQL PASSIVE_LEVEL(0)

#include <ntddk.h>




void SampleUnload(_In_ PDRIVER_OBJECT DriverObject) {
	UNREFERENCED_PARAMETER(DriverObject);
	KdPrint(("Bye Bye from Unload"));

}


extern "C" NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath) {
	RTL_OSVERSIONINFOW info = { sizeof(info) };

	NTSTATUS status;
	status = RtlGetVersion(&info);
	//UNREFERENCED_PARAMETER(DriverObject);
	UNREFERENCED_PARAMETER(RegistryPath);
	KdPrint(("Hello from  DriverEntry"));
	KdPrint(("OS Build Number: %u\nMajor Version Number: %u\nMinor Version: %u\n", info.dwBuildNumber, info.dwMajorVersion, info.dwMinorVersion));
	DriverObject->DriverUnload = SampleUnload;

	return STATUS_SUCCESS;

}
