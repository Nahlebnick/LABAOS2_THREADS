#include "thread.h"

void Thread::StartThread(LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter)
{
	hThread = CreateThread(NULL, 0, lpStartAddress, lpParameter, 0, &IDThread);
	if (hThread == NULL)
		ErrorMessageBox();
}

void Thread::ErrorMessageBox()
{
	LPVOID lpMsgBuf;

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // язык по умолчанию
		(LPTSTR)&lpMsgBuf,
		0,
		NULL
	);
	// Показать ошибку в MessageBox.
	MessageBox(
		NULL,
		(LPCTSTR)lpMsgBuf,
		L"Ошибка Win32 API",
		MB_OK | MB_ICONINFORMATION
	);
	// Освободить буфер.
	LocalFree(lpMsgBuf);
}
