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
		Node* Find(Node* node, int data)
		{
			if (node == nullptr) { return nullptr; }

			if (data < node->mData) {
               return Find(node->mpLeft, data);

			}
			
			else if (node->mData == data)
			{
				std::cout << node->mData;
				return node;
			}
			
			else if (data > node->mData) {
				return Find(node->mpRight, data);
			}
		}

		void Erase(Node* &node, int data)
		{
			if (node == nullptr)
			{
				return;
			}
			if (data < node->mData) {
				Erase(node->mpLeft, data);
			}
			else if (data > node->mData)
			{
				Erase(node->mpRight, data);
			}

			else {
			if (node->mpLeft == nullptr && node->mpRight == nullptr)
			{
				delete node;
				node = nullptr;
			}
			else if (node->mpLeft != nullptr && node->mpRight != nullptr)
			{
				auto temp = node->mpLeft;
				while (temp->mpRight != nullptr)
				{
					temp = temp->mpRight;
				}
				temp->mpRight = node->mpRight;
				delete node;
				node = nullptr;
			}
			else {
				Node* temp = node;
				if (temp->mpLeft != nullptr)
				{
					node = node->mpLeft;
				}
				else if (temp->mpRight != nullptr)
				{
					node = node->mpRight;
				}
				delete temp;

			}
			}
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

	bst.Find(root, 10);
	bst.Find(root, 6);
	bst.InOrder(root);
}

