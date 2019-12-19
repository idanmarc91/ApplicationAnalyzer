#include "pch.h"
#include "Application.h"


Application::Application(PROCESSENTRY32 processEntry, MODULEENTRY32W moduleEntry)
{
	_id = processEntry.th32ProcessID;
	wcsncpy_s(_name, processEntry.szExeFile, MAX_PATH);
	//wcsncpy_s(_path, moduleEntry.szExePath, MAX_PATH);
	_numOfThreads = processEntry.cntThreads;
}

DWORD Application::GetId()
{
	return _id;
}

WCHAR* Application::GetName()
{
	return _name;
}

DWORD Application::GetNumOfThreads()
{
	return _numOfThreads;
}


Application::~Application()
{
}
