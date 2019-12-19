#include "pch.h"
#include "Application.h"


Application::Application(PROCESSENTRY32 processEntry)
{
	_id = processEntry.th32ProcessID;
	wcsncpy_s(_path, processEntry.szExeFile, 260);
	//_path = ;
	//_name =
}

DWORD Application::GetId()
{
	return _id;
}

WCHAR* Application::GetName()
{
	return _path;
}


Application::~Application()
{
}
