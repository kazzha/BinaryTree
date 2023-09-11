#include <iostream>
#include "binarytree.h"
#include "bst.h"
#include "quadtree.h"

using namespace mytree;
using namespace BST;
using namespace quad;

void BT_Tets()
{
	BinaryTree myTree;

	auto pRoot = myTree.GetRoot();
	pRoot->mData = 1;

	auto pNode = myTree.InsertLeft(pRoot, 2);
	myTree.InsertLeft(pNode, 4);
	myTree.InsertRight(pNode, 5);

	pNode = myTree.InsertRight(pRoot, 3);
	myTree.InsertLeft(pNode, 6);
	myTree.InsertRight(pNode, 7);


	// myTree.BreadthFirstSearch();
	// myTree.DFSRecursive(myTree.GetRoot());

	std::cout << myTree.Sum();
}

int main()
{
	QTTest();
}