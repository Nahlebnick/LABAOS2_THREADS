#pragma once

#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <windows.h>

class Thread
{
	HANDLE hThread;
	DWORD IDThread;
public:
	Thread() : hThread(0), IDThread(0) {};

	void StartThread(LPTHREAD_START_ROUTINE lpStartAddress, // адрес исполняемой функции
		LPVOID lpParameter); // адрес параметра

	void ErrorMessageBox();
};

#endif // PROCESS_H
