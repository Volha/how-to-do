#pragma once
#include <vector>
#include <algorithm>
namespace Control
{
	template <typename T>
	class Tree
	{
		template <typename NodeValueType> 
		struct Node
		{
			Node(const NodeValueType& v, Node* left = nullptr, Node* right = nullptr)
				: leftRef(left)
				, rightRef(right)
				, value(v)
			{
			
			}
			Node* leftRef;
			Node* rightRef;
			NodeValueType value;
		};
	typedef Node<T> NodeType;
	public:
		Tree()
			: m_node(nullptr)
		{
		
		}
		void Add(const T& nodeValue)
		{
			if (m_node == nullptr)
			{
				m_node = new NodeType(nodeValue);
				return;
			}

			NodeType* currentNode = m_node;
			while(currentNode)
			{
				if (nodeValue > currentNode->value)
				{
					if (currentNode->rightRef == nullptr)
					{
						currentNode->rightRef = new NodeType(nodeValue);
						break;
					}
					currentNode = currentNode->rightRef;
				}
				else
				{
					if (currentNode->leftRef == nullptr)
					{
						currentNode->leftRef = new NodeType(nodeValue);
						break;
					}
					currentNode = currentNode->leftRef;
				}
			}
		}

		std::vector<T> Traverse()
		{
			std::vector<T> res;
			Tr(m_node, res);
			return res;
		}



		std::vector<T> TraversSpecial()
		{
			std::vector<NodeType*> nextGen;
			std::vector<NodeType*> nextGen1;
			std::vector<T> res;
			res.push_back(m_node->value);
			
			nextGen.push_back(m_node->leftRef);
			nextGen.push_back(m_node->rightRef);
			
			while (!nextGen.empty())
			{
				std::for_each(nextGen.begin(), nextGen.end(), [&nextGen1, &res](NodeType* child)
				{
					if (child != nullptr)
					{
						nextGen1.push_back(child->leftRef);
						nextGen1.push_back(child->rightRef);
						res.push_back(child->value);
					}
				});
				nextGen.swap(nextGen1);
				nextGen1.clear();
			}
			return res;
		}

	private:
		void Tr(NodeType* node, std::vector<T>& res)
		{
			if (node == nullptr) return;
			
			Tr(node->rightRef, res);
			res.push_back(node->value);
			Tr(node->leftRef, res);
			
		}
	private:
		NodeType* m_node;
	};
}