#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node(arguments);
	Node *SearchNode(int nodeIndex);
	int index;
	int data;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;
	/* data */
};

#endif