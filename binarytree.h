#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <cmath>

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

	public:
		void Visit(Node* node) { std::cout << node->mData << " "; }

		void BreadthFirstSearch()
		{
			std::queue<Node*> q;
			q.push(mpRoot);

			while (!q.empty())
			{
				auto node = q.front();
				Visit(node);
				q.pop();

				if (node->mpLeft)
				{
					q.push(node->mpLeft);
					
				}
				if (node->mpRight != nullptr)
				{
					q.push(node->mpRight);
				}

			}
		}

		void DepthFirstSearch()
		{
			std::stack<Node*> s;

			s.push(mpRoot);

			while (!s.empty())
			{
				auto node = s.top();
				Visit(node);
				s.pop();

				if (node->mpRight) s.push(node->mpRight);
				if (node->mpLeft) s.push(node->mpLeft);
			}
		}

		void DFSRecursive(Node* node)
		{
			//base case
			if (!node)
			{
				return;
			}

			Visit(node);
			//recursive case

			DFSRecursive(node->mpLeft);
			DFSRecursive(node->mpRight);
		}

		void PreOrder(Node* node)
		{
			//base case
			if (!node)
			{
				return;
			}

			Visit(node);
			//recursive case

			DFSRecursive(node->mpLeft);
			DFSRecursive(node->mpRight);
		}

		void InOrder(Node* node)
		{
			//base case
			if (!node)
			{
				return;
			}

			DFSRecursive(node->mpLeft);
			Visit(node);
			DFSRecursive(node->mpRight);
		}

		void PostOrder(Node* node)
		{
			//base case
			if (!node)
			{
				return;
			}

			DFSRecursive(node->mpLeft);
			DFSRecursive(node->mpRight);
			Visit(node);
		}

		int Sum()
		{
			std::queue<Node*> q;
			q.push(mpRoot);
			int sum{};

			while (!q.empty())
			{
				auto node = q.front();
				sum += node->mData;
			
				if (node->mpLeft) { q.push(node->mpLeft); }
				if (node->mpRight) { q.push(node->mpRight); }

				q.pop();
			}

			return sum;

		}
		bool Search(Node* root, int value)
		{
			if(root == nullptr)
			{
				return false;
			}

			return (root->mData == value) || Search(root->mpLeft, value) || Search(root->mpRight, value);
		}

		int height(Node* root)
		{
			static int level{};
			if(!root)
			{
				return 0;
			}

			level++;
			height(root->mpLeft);
			height(root->mpRight);

			return 1+static_cast<int>(log2(level));
		}

	};

}
