#pragma once

namespace BST
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

	class BinarySearchTree
	{
	private:
		Node* mpRoot;

	public:
		BinarySearchTree()
		{
			mpRoot = CreateNode(0);
		}
		Node* CreateNode(int value, Node* pLeft = nullptr, Node* pRight = nullptr) // øﬁø¿¥¬ ¡‡µµ µ«∞Ì æ»¡‡µµ µ«∞‘
		{
			return new Node(value, pLeft, pRight);
		}

		Node* GetRoot() { return mpRoot; }

		Node* Insert(Node* parent, int data)
		{
			//rules
		}
	};
}
