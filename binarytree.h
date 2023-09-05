#pragma once

#include <iostream>

namespace mytree
{
	struct Node
	{
		int mData;
		Node* mpLeft;
		Node* mpRight;

		Node(int data = 0, Node* left = nullptr, Node* right = nullptr)
		{
			mData = data;
			mpLeft = left;
			mpRight = right;
		}
	};

	class BinaryTree
	{
	private:
		Node* mpRoot;

	public:
		BinaryTree()
		{
			mpRoot = CreateNode(0);
		}
		Node* CreateNode(int value, Node* pLeft=nullptr, Node* pRight=nullptr) // ¿Þ¿À´Â Áàµµ µÇ°í ¾ÈÁàµµ µÇ°Ô
		{
			return new Node(value, pLeft, pRight);
		}

		Node* GetRoot() { return mpRoot; }

		Node* InsertLeft(Node* parent, int value)
		{
			parent->mpLeft = CreateNode(value);
			return parent->mpLeft;
		}

		Node* InsertRight(Node* parent, int value)
		{
			parent->mpRight = CreateNode(value);
			return parent->mpRight;
		}
	};

}