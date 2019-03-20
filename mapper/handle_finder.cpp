#include "stdafx.h"
#include "handle_finder.hpp"

typedef struct _SYSTEM_HANDLE
{
	ULONG ProcessId;
	BYTE ObjectTypeNumber;
	BYTE Flags;
	USHORT Handle;
	PVOID Object;
	ACCESS_MASK GrantedAccess;
} SYSTEM_HANDLE, *PSYSTEM_HANDLE;

typedef struct _SYSTEM_HANDLE_INFORMATION
{
	ULONG HandleCount;
	SYSTEM_HANDLE Handles[1];
} SYSTEM_HANDLE_INFORMATION, *PSYSTEM_HANDLE_INFORMATION;

HANDLE handle_finder::find(const std::string& process_name, const uint32_t handle_access)
{
	std::vector<uint8_t> buffer;
	ULONG buffer_size = 0;

	buffer.reserve(10000);

	auto status = -1;
	while (status != 0)
	{
		status = NtQuerySystemInformation(static_cast<SYSTEM_INFORMATION_CLASS>(0x10), buffer.data(), buffer_size, &buffer_size);

		if (status == STATUS_INFO_LENGTH_MISMATCH)
			buffer.reserve(buffer_size);
	}

	auto handle_info = reinterpret_cast<PSYSTEM_HANDLE_INFORMATION>(buffer.data());
	auto my_process_id = process::current_process().get_id();

	for (int i = 0; i < handle_info->HandleCount; i++) {
		auto handle = handle_info->Handles[i];

		if (handle.ObjectTypeNumber == 7 && handle.GrantedAccess & handle_access == handle_access && handle.ProcessId == my_process_id)
		{
			char buffer[MAX_PATH];
			GetModuleBaseNameA(reinterpret_cast<HANDLE>(handle.Handle), nullptr, buffer, MAX_PATH);

			if (buffer == process_name)
				return reinterpret_cast<HANDLE>(handle.Handle);
		}
	}

	return 0;
}
