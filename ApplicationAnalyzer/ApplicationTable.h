#pragma once

#include <vector>
#include "Application.h"

class ApplicationTable
{
public:
	ApplicationTable()
	{
		//_applicationTable = new std::vector<Application>();
	};

	bool UpdateTableData();
	bool CreateApplicationList(HANDLE ps);
	void PrintList();
	~ApplicationTable();
	

private:
	 std::vector<Application> _applicationTable;
	
	
};

