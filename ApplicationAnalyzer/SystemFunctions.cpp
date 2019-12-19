#include "pch.h"
#include <windows.h>
#include <iostream>
//#include <tlhelp32.h>

#include "SystemFunctions.h"

using namespace std;

HANDLE SystemFunctions::GetProcessList()
{
	HANDLE hProcessSnap;
	//PROCESSENTRY32 processEntry32;

	// Take a snapshot of all processes in the system.
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		cout << "Error while getting process list";
		return nullptr;
	}	
	return hProcessSnap;
}

