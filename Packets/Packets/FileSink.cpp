#include "stdafx.h"
#include "FileSink.h"


FileSink::FileSink()
	:m_fileHandle(std::make_shared<HandleWrapper>(CreateFile(
					L"FileForWriting.txt", 
					GENERIC_WRITE, 
					FILE_SHARE_READ, 
					nullptr, 
					CREATE_ALWAYS, 
					FILE_ATTRIBUTE_NORMAL, 
					nullptr
					)))
{
	SetFilePointer(**m_fileHandle, 0, nullptr, FILE_BEGIN); 
}

void FileSink::Consume(PacketType* p)
{
	DWORD bytesWritten = 0;
	BOOL returnValue = WriteFile(**m_fileHandle, p->m_array, p->m_size, &bytesWritten, nullptr);
	if (returnValue == FALSE)
	{
		DWORD  error = GetLastError();
		return;
	}
}
