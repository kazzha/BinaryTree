#pragma once
#include <memory>


namespace quad
{
	struct Point
	{
		int x;
		int y;

		Point() : x(0), y(0) {}
		Point(int x, int y) {
			this->x = x;
			this->y = y;
		}
	};

	struct Node
	{
		Point pos;
		int data;

		Node() : pos(), data(0) {}
		Node(Point p, int data)
		{
			this->pos = p;
			this->data = data;
		}
	};

	class QuadTree
	{
		Point topLeft;
		Point bottomRight;

		Node* node;

		std::unique_ptr<QuadTree> nw;
		std::unique_ptr<QuadTree> ne;
		std::unique_ptr<QuadTree> sw;
		std::unique_ptr<QuadTree> se;

	public:
		QuadTree();

		QuadTree(Point tl, Point br);

		void Insert(Node* node);

		bool IsInBound(Point pt);

	};
	void QTTest();
}

