#ifndef LINKTREE_H
#define LINKTREE_H

#include "Node.h"
class LinkTree
{
public:
	LinkTree(arguments);
	~LinkTree();
	Node *SearchNode(int nodeIndex);
	bool AddNode(int nodeIndex, int direction, Node *pNode);
	bool DeleteNode(int nodeIndex, Node *pNode);
	void Preorder();
	void Inorder();
	void Postorder();
	/* data */
private:
	Node *m_pRoot;
};
#endif