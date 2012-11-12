#pragma once

template<int N>
class Packet
{
public: 
	Packet()
		:m_size(0)
	{
	
	}

	int GetFullSize()
	{
		return N;
	};
	
	
	char m_array[N];
	int m_size;
};