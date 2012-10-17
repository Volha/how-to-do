#include "StdAfx.h"
#include "HandlerClass.h"


HandlerClass::HandlerClass()
	: m_progress(0)
{
}

HandlerClass::~HandlerClass()
{
}

void HandlerClass::OnProgress(int i)
{
	Lock lock(m_mutex);
	m_progress = i;
	m_condition.notify_all();
};

int HandlerClass::GetProgress() const
{
	Lock lock(m_mutex);
	return m_progress;
};

void HandlerClass::WaitUntilProgressChanged()
{
	Lock lock(m_mutex);
	m_condition.wait(lock);
};

void HandlerClass::IncrementProgress()
{
	Lock lock(m_mutex);
	++m_progress;
	m_condition.notify_all();
};