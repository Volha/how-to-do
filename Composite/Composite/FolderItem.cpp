#include "stdafx.h"
#include "FolderItem.h"
#include <algorithm>

FolderItem::FolderItem(const std::string name)
	: BaseItem(name)
{
	
}

void FolderItem::AddItem(BasePtr childItem)
{
	m_children.push_back(childItem);
}

void FolderItem::RemoveItem(BasePtr childItem) 
{
	auto it = std::remove(m_children.begin(), m_children.end(), childItem);
	m_children.erase(it, m_children.end());
}

BaseItem::BasePtr FolderItem::Find(const std::string& path)
{
	size_t startPosition = 0;
	auto position = path.find_first_of("/\\", startPosition);
	auto subStrLength = position - startPosition;
	auto subStr = path.substr(startPosition, subStrLength);
	auto childIt = std::find_if(m_children.cbegin(), m_children.cend(),
		[&subStr](BasePtr child)->bool
		{
			return child->GetName() == subStr;
		}
	);

	if (childIt == m_children.cend())
	{
		return BasePtr();
	}

	if (position == std::string::npos)
	{
		return (*childIt);
	}
	std::string subPath = path.substr(position + 1);
	return (*childIt)->Find(subPath);
}
