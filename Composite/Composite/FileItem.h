#pragma once
#include "BaseItem.h"

class FileItem : public BaseItem
{
public:
	FileItem(const std::string name);
	void AddItem(BasePtr);
	void RemoveItem(BasePtr);
	BasePtr Find(const std::string& path);
};