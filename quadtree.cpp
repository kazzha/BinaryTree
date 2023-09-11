#include "quadtree.h"
#include <memory>

using namespace quad;

quad::QuadTree::QuadTree() : 
    topLeft{ Point{} }, bottomRight{ Point{} },
    node{nullptr},
    nw{}, ne{}, sw{}, se{}
{

}

quad::QuadTree::QuadTree(Point tl, Point br) : QuadTree()
{
    topLeft = tl;
    bottomRight = br;
}

bool quad::QuadTree::IsInBound(Point pt)
{
    return pt.x >= topLeft.x && pt.x <= bottomRight.x &&
        pt.y >= topLeft.y && pt.y <= bottomRight.y;
}

void quad::QuadTree::Insert(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    if (!IsInBound(node->pos))
    {
        return;
    }

    if (std::abs(topLeft.x - bottomRight.x) <= 1 &&
        std::abs(topLeft.y - bottomRight.y) <= 1)
    {
        if (this->node == nullptr)
        {
            this->node = node;
        }
        return;
    }

    // recursive
    // 辑率
    if (node->pos.x <= (topLeft.x + bottomRight.x) / 2)
    {
        // 合辑
        if (node->pos.y <= (topLeft.y + bottomRight.y) / 2)
        {
            if (nw == nullptr)
            {
                nw = std::make_unique<QuadTree>(topLeft,
                    Point((topLeft.x + bottomRight.x) / 2, (topLeft.y + bottomRight.y) / 2));
            }
            nw->Insert(node);
        }
        else  // 巢辑
        {
            if (sw == nullptr)
            {
                sw = std::make_unique<QuadTree>(Point(topLeft.x, (topLeft.y + bottomRight.y) / 2),
                    Point((topLeft.x + bottomRight.x) / 2, bottomRight.y));
            }
            sw->Insert(node);
        }
    }
   
    // 悼率
    else
    {
        // 合悼
        if (node->pos.y <= (topLeft.y + bottomRight.y) / 2)
        {
            if (ne == nullptr)
            {
                ne = std::make_unique<QuadTree>(Point((topLeft.x+bottomRight.x) / 2 , topLeft.y),
                     Point(bottomRight.x, (topLeft.y+bottomRight.y)/2));
            }
            ne->Insert(node);
        }
        else
        {
            if (se == nullptr)
            {
                se = std::make_unique<QuadTree>(
                    Point((topLeft.x + bottomRight.x) / 2, (topLeft.y + bottomRight.y) / 2), 
                    bottomRight);
            }
            se->Insert(node);
        }
    }
}

void quad::QTTest()
{
    QuadTree q(Point(0, 0), Point(8, 8));

    std::unique_ptr<Node> a = std::make_unique<Node>(Point(1, 1), 1);
    std::unique_ptr<Node> b = std::make_unique<Node>(Point(2, 2), 2);
    std::unique_ptr<Node> c = std::make_unique<Node>(Point(3, 3), 3);
    std::unique_ptr<Node> d = std::make_unique<Node>(Point(4, 4), 4);

    q.Insert(a.get());
    q.Insert(b.get());
    q.Insert(c.get());
    q.Insert(d.get());
}
