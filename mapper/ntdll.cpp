#include "stdafx.h"
#include "ntdll.hpp"

NtCreateSection_t ntdll::NtCreateSection = nullptr;
NtMapViewOfSection_t ntdll::NtMapViewOfSection = nullptr;

void ntdll::initialise()
{
	auto module_handle = GetModuleHandle(L"ntdll.dll");
	ntdll::NtCreateSection = reinterpret_cast<NtCreateSection_t>(GetProcAddress(module_handle, "NtCreateSection"));
	ntdll::NtMapViewOfSection = reinterpret_cast<NtMapViewOfSection_t>(GetProcAddress(module_handle, "NtMapViewOfSection"));
}
