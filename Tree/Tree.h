#ifndef TREE_H
#define TREE_H

class Tree
{
public:
	Tree(int size, int *pRoot);
	~Tree();
	int *SearchNode(int nodeIndex);
	bool AddNode(int nodeIndex, int direction, int *pNode);
	bool DeleteNode(int nodeIndex, int *pNode);
	void TreeTraverse();
	/* data */
private:
	int *m_tree;
	int m_size;
};
#endif