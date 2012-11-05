#pragma once 

template <typename T>
class RingClass
{
public:
	RingClass()
		: currentNode(nullptr)
		, tailNode(nullptr)
	{
			
	}

	void AddNode(const T& val)
	{
		Node* newNode = new Node(val);
		if (currentNode == nullptr)
		{
			newNode->next = newNode;
			tailNode = newNode;
		}
		else 
		{
			newNode->next = currentNode;
			tailNode->next = newNode;
		}
		currentNode = newNode;
	}

	void RemoveNode()
	{
		Node* previousNode(currentNode);
		while (previousNode->next != currentNode)
		{
			previousNode = previousNode->next;
		}
		previousNode->next = currentNode->next;
		currentNode = previousNode;
	}
		
	const T& GetCurrentValue() const
	{
		return currentNode->value;
	}

	void MoveNext()
	{
		currentNode = currentNode->next;
	}

private:
	class Node
	{
	public:
		Node(const T& val, Node* r = nullptr)
			: value(val)
			, next(r)
		{
					
		}
		T value;
		Node* next;
	};

	Node* currentNode;
	Node* tailNode;
};
