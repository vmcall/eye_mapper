#include "stdafx.h"

bool g_initialised = false;
extern "C" BOOL __declspec(dllexport) WINAPI HookMain(LARGE_INTEGER *lpPerformanceCount)
{
	// INTIALISE
	if (!g_initialised)
	{
		g_initialised = true;
		MessageBoxA(0, 0, 0, 0);
	}
	return QueryPerformanceCounter(lpPerformanceCount);
}

