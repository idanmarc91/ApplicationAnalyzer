#pragma once

#include <string>
#include <tlhelp32.h>
#include <windows.h>

class Application
{
public:
	Application(PROCESSENTRY32 processEntry, MODULEENTRY32W moduleEntry);
	DWORD GetId();
	WCHAR* GetName();
	DWORD GetNumOfThreads();

	~Application();

	

private:
	DWORD _id;
	WCHAR _path [MAX_PATH];
	DWORD _numOfThreads;
	WCHAR _name [MAX_PATH];
	//cpu usage, memory usage, user name, network usage,

};

