// FileManager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <memory>

class HandleWrapper
{
public:
	explicit HandleWrapper(HANDLE handle)
		: m_handle(handle)
	{
		
	}
	
	bool IsValid() const 
	{
		return m_handle != INVALID_HANDLE_VALUE;
	}

	HANDLE operator* () const
	{
		return m_handle;
	}

	~HandleWrapper()
	{
		if (IsValid()) 
		{
			CloseHandle(m_handle);
		}
	}
private:
	HANDLE m_handle;
};

class Worker
{
public:
	Worker(LPCWSTR fileName)
	:m_fileName(fileName)
	{
	
	}

	~Worker()
	{
		
	}

	void WriteToFile(std::string stringToWrite)
	{
		auto fileHandle = std::make_shared<HandleWrapper>(CreateFile(m_fileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0));
		if (fileHandle->IsValid()) 
		{
			DWORD bytesWritten = 0;
			BOOL returnValue = WriteFile(**fileHandle, stringToWrite.data(), stringToWrite.size(), &bytesWritten, nullptr);
			if (returnValue == FALSE)
			{
				DWORD  error = GetLastError();
			}
		}
	}
private:
	LPCWSTR m_fileName;
};

class DeleteFunct
{
public:
	void operator() (Worker* w)
	{
		if (w)
		{
			delete w;
		}
	}
};

void DeleteShPtr(Worker* w)
{
	if (w)
	{
		delete w;
	}
}

typedef void (*DeleterFunction)(Worker*);

int _tmain(int argc, _TCHAR* argv[])
{
	DeleteFunct d;
	std::shared_ptr<Worker> w(new Worker(L"FileName.txt"), [](Worker* w)
	{
		if (w)
		{
			delete w;
		}
	});
	w->WriteToFile("WRITE_String + String");

	return 0;
}

