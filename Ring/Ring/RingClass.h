#pragma once 

template <typename T>
class RingClass
{
	class Node
	{
	public:
		Node(const T& val, Node* n = nullptr, Node* pr = nullptr)
			: value(val)
			, next(n)
			, previous(pr)
		{
			
		}

		T value;
		Node* next;
		Node* previous;
	};

public:
	RingClass()
		: currentNode(nullptr)
		, tailNode(nullptr)
	{
			
	}

	RingClass(const RingClass& r)
	{
		Node* p = r.tailNode;
		currentNode = nullptr;
		tailNode = nullptr;
		do
		{
			AddNode(p->value);
			p = p->previous;
		}
		while (p != r.tailNode);
	}

	~RingClass()
	{
		while (!IsEmpty())
		{
			RemoveNode(currentNode);
		}
	}

	bool IsEmpty() const
	{
		return currentNode == nullptr;
	}
	
	void AddNode(const T& val)
	{
		Node* newNode = new Node(val);
		if (currentNode == nullptr)
		{
			newNode->next = newNode;
			newNode->previous = newNode;
			tailNode = newNode;
		}
		else 
		{
			newNode->next = currentNode;
			newNode->previous = tailNode;
			currentNode->previous = newNode;
			tailNode->next = newNode;
		}
		currentNode = newNode;
	}
	
	const T& GetCurrentValue() const
	{
		return currentNode->value;
	}

	void MoveNext()
	{
		currentNode = currentNode->next;
	}

	void MovePrevious()
	{
		currentNode = currentNode->previous;
	}

private:
	void RemoveNode(Node* p)
	{
		if (p->next == p)
		{
			currentNode = nullptr; 
			tailNode = nullptr;
		}
		else
		{
			p->previous->next = p->next;
			p->next->previous = p->previous;
			if(p == currentNode)
			{
				currentNode = p->previous;
			} 
			if (p == tailNode)
			{
				tailNode = p->previous;
			}
		} 
		delete p;
	}
		

private:
	Node* currentNode;
	Node* tailNode;
};
