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
			if (parent == nullptr)
			{
				return CreateNode(data);
			}

			if (data < parent->mData)
			{
				parent->mpLeft = Insert(parent->mpLeft, data);
			}
			else if (data > parent->mData)
			{
				parent->mpRight = Insert(parent->mpRight, data);
			}

			return parent;
		}
	public:
		void Visit(Node* node) { std::cout << node->mData << " "; }
		void InOrder(Node* node)
		{
			if (node == nullptr) return;

			InOrder(node->mpLeft);
			Visit(node);
			InOrder(node->mpRight);
		}
	};
}

void BSTest()
{
	using namespace BST;

	BinarySearchTree bst;

	auto root = bst.Insert(nullptr, 8);

	bst.Insert(root, 3);
	bst.Insert(root, 10);
	bst.Insert(root, 1);
	bst.Insert(root, 6);

	bst.InOrder(root);
}

