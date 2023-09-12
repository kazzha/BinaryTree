#pragma once

namespace Practice
{
	struct Node
	{
		int mData;
		Node* mRight;
		Node* mLeft;

		Node(int data = 0, Node* right = nullptr, Node* left = nullptr)
		{
			mData = data;
			mRight = right;
			mLeft = left;
		}
	};

	class BST : public Node
	{
	public:
		BST() : Node()
		{
			
		}

		Node* CreateNode(int data = 0, Node* right = nullptr, Node* left = nullptr)
		{
			Node* node = new Node(data, right, left);
			return node;
		}

		Node* Insert(Node* root, int data)
		{
			if (root == nullptr)
			{
				return CreateNode(data);
			}
			if (data < root->mData)
			{
				root->mLeft = Insert(root->mLeft, data);
			}
			if (data > root->mData)
			{
				root->mRight = Insert(root->mRight, data);
			}
		}
	};
}
