// testapp.cpp : Defines the entry point for the console application.
//

#include <windows.h>

int main()
{
	MessageBoxA(0, 0, 0, 0);
	while (true)
	{
		LARGE_INTEGER a;
		QueryPerformanceCounter(&a);
		Sleep(1);
	}

    return 0;
}

