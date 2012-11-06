#pragma once
#include "BaseItem.h"
#include <vector>

class FolderItem: public BaseItem
{
public:
	FolderItem(const std::string name);
	void AddItem(BasePtr);
	void RemoveItem(BasePtr);
	BasePtr Find(const std::string& path);
private:
	std::vector<BasePtr> m_children;
};
