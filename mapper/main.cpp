#include "stdafx.h"
#include "ntdll.hpp"
#include <windows.h>

int main()
{
	ntdll::initialise();

	auto buffer = binary_file::read_file("D:\\test.dll");

	process proc = process(process::from_name("RainbowSix.exe"), 0x1fffff);

	logger::log_formatted("Name", proc.get_name());
	injection::manualmap(proc).inject(buffer);
}