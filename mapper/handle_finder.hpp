#pragma once
#include "stdafx.h"

class handle_finder
{
public:
	static HANDLE find(const std::string& process_name, const uint32_t handle_access);
};
