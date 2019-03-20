#pragma once
#include "stdafx.h"

typedef NTSTATUS(NTAPI* NtCreateSection_t)(
	PHANDLE				 sectionHandle,
	ULONG                DesiredAccess,
	POBJECT_ATTRIBUTES   ObjectAttributes OPTIONAL,
	PLARGE_INTEGER       MaximumSize OPTIONAL,
	ULONG                PageAttributess,
	ULONG                SectionAttributes,
	HANDLE               FileHandle OPTIONAL);

typedef NTSTATUS(NTAPI* NtMapViewOfSection_t)(
	HANDLE			SectionHandle,
	HANDLE          ProcessHandle,
	PVOID           *BaseAddress,
	ULONG_PTR       ZeroBits,
	SIZE_T          CommitSize,
	PLARGE_INTEGER  SectionOffset,
	PSIZE_T         ViewSize,
	int InheritDisposition,
	ULONG           AllocationType,
	ULONG           Win32Protect);

namespace ntdll
{
	void initialise();
	extern NtCreateSection_t NtCreateSection;
	extern NtMapViewOfSection_t NtMapViewOfSection;
}