#include <iostream>
#include "Tree.h"
using namespace std;

Tree::Tree(int size, int *pRoot)
{
	m_tree = new int[size];
	m_size = size;
	for (int i = 0; i < size; ++i)
	{
		m_tree[i] = 0;
	}
	m_tree[0] = *pRoot;
}

Tree::~Tree()
{
	delete []m_tree;
	m_tree = NULL;
}

int *Tree::SearchNode(int nodeIndex)
{
	if (nodeIndex<0||nodeIndex>m_size||m_tree[nodeIndex]==0)
	{
		return NULL;
	}
	return & m_tree[nodeIndex];
}

bool Tree::AddNode(int nodeIndex, int direction, int * pNode)
{
	if (nodeIndex<0||nodeIndex>m_size||m_tree[nodeIndex]==0)
	{
		return false;
	}
	if (direction==0)
	{
		int index = nodeIndex*2+1;
		if (index >= m_size||m_tree[index]!=0)
		{
			return false;
		}
		m_tree[index] = *pNode;
	}
	if (direction==1)
	{
		int index = nodeIndex*2+2;
		if (index >= m_size||m_tree[index]!=0)
		{
			return false;
		}
		m_tree[index] = *pNode;	
	}
}
bool Tree::DeleteNode(int nodeIndex, int * pNode)
{
	if (nodeIndex<0||nodeIndex>m_size||m_tree[nodeIndex]==0)
	{
		return false;
	}
	*pNode = m_tree[nodeIndex];
	m_tree[nodeIndex]=0;
	return true;
}

void Tree::TreeTraverse()
{
	for (int i = 0; i < m_size; ++i)
	{
		cout<<m_tree[i]<<" ";
	}
}


