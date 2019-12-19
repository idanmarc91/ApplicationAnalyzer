#include "pch.h"
#include <iostream>
#include <windows.h>
//#include <tlhelp32.h>

#include "SystemFunctions.h"
#include "ApplicationTable.h"

using namespace std;

bool ApplicationTable::UpdateTableData()
{
	HANDLE hProcessSnap = SystemFunctions::GetProcessList();

	if (hProcessSnap == nullptr)
		return false;

	if (!CreateApplicationList(hProcessSnap))
		return false;
	
	PrintList();

	return true;
}
/// <summary>
/// This function create application list using the process snap handle to get all active process
/// </summary>
/// <param name="hProcessSnap"></param>
/// <returns></returns>
bool ApplicationTable::CreateApplicationList(HANDLE hProcessSnap)
{
	PROCESSENTRY32 processEntry32;
	MODULEENTRY32W processInfoExtention;



	processEntry32.dwSize = sizeof(PROCESSENTRY32W);
	processInfoExtention.dwSize = sizeof(MODULEENTRY32W);

	//get first process. if fail exit function.
	if (!Process32First(hProcessSnap, &processEntry32) && !Module32First(hProcessSnap,& processInfoExtention))
	{
		cout << "Process32First"; // show cause of failure
		CloseHandle(hProcessSnap);          // clean the snapshot object
		return false;
	}

	//create the list
	do
	{
		Application tempApp = Application(processEntry32, processInfoExtention);
		_applicationTable.push_back(tempApp);
	} while (Process32Next(hProcessSnap, &processEntry32));

	return true;

}

/// <summary>
/// This function print the list to cmd 
/// </summary>
void ApplicationTable::PrintList()
{
	//Print Data Header
	std::cout << "ProcessID		ProcessName" << std::endl;

	//Iterate on list and print the data
	for (int index = 0; index < _applicationTable.size(); index++)
	{
		std::cout << _applicationTable[index].GetId();
		std::cout << "			";
		std::wcout<< _applicationTable[index].GetName();
		std::cout << std::endl;
	}
}

ApplicationTable::~ApplicationTable()
{
}
