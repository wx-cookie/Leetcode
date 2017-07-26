#include "Tree.h"

Tree::Tree()
{
	m_pRoot = new Node();
}
Node *Tree::SearchNode(int nodeIndex)
{
	return m_pRoot->SearchNode(nodeIndex);
}