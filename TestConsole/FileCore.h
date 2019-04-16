#pragma once
#include "Core.h"

#include <string>

// directory reading
#include <iostream>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <windows.h>
#include <stdio.h>


class DirectoryHandle()
{
public:
	DirectoryHandle(const std::string& directoryPath) : 
		fHandle(FindFirstFile(directoryPath.c_str(), wfd))
	{}

	~DirectoryHandle()
	{
		if (fHandle != nullptr)
		{

		}
	}


public:
	WIN32_FIND_DATA wfd;
	LARGE_INTEGER fileSize;
	TCHAR szData;
	HANDLE fHandle = INVALID_HANDLE_VALUE;
}
