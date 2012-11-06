#include "stdafx.h"
#include "FileItem.h"

FileItem::FileItem(const std::string name)
	: BaseItem(name)
{
	
}

void FileItem::AddItem(BasePtr childItem)
{
	
}

void FileItem::RemoveItem(BasePtr childItem)
{
	
}

FileItem::BasePtr FileItem::Find(const std::string& path)
{
	return FileItem::BasePtr();
}
