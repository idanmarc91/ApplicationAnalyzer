#pragma once

#include <string>
#include <tlhelp32.h>
#include <windows.h>

class Application
{
public:
	Application(PROCESSENTRY32 processEntry);
	DWORD GetId();
	WCHAR* GetName();

	~Application();

	

private:
	DWORD _id;
	std::string _name;
	WCHAR _path [260];
	//cpu usage, memory usage, user name, network usage,

};

