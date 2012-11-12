#pragma once

//template<int N>
class Packet
{
public: 
	Packet()
		:m_size(0)
	{
	
	}
	/*int GetFullSize()
	{
		return N;
	};*/
	
	
	char m_array[100];
	int m_size;
};