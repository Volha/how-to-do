#pragma once

#include "stdafx.h"
#include <memory>
#include <string>

class BaseItem
{
public: 
	typedef std::shared_ptr<BaseItem> BasePtr;
	BaseItem(const std::string& name)
		: m_name(name)
	{
	}
	virtual ~BaseItem()
	{
	}
	virtual void AddItem(BasePtr) = 0;
	virtual void RemoveItem(BasePtr) = 0;
	virtual const std::string& GetName() const
	{
		return m_name;
	}
	virtual BasePtr Find(const std::string& path) = 0;
private:
	std::string m_name;
};
//using BaseItem::BasePtr;