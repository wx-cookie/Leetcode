#include "Tree.h"
#include <iostream>
using namespace std;

int main ()
{
	int root =3;
	Tree *pTree = new Tree(10, &root);
	//添加节点
	int node1 = 5;
	int node2 = 8;
	pTree->AddNode(0,0,&node1);
	pTree->AddNode(0,1,&node2);

	int node3 = 2;
	int node4 = 6;
	pTree->AddNode(1,0,&node3);
	pTree->AddNode(1,1,&node4);

	int node5 = 9;
	int node6 = 7;
	pTree->AddNode(2,0,&node5);
	pTree->AddNode(2,1,&node6);

	//删除
	int p = 0;
	pTree->DeleteNode(6, &p);
	cout<<p<<endl;

	//遍历一遍
	pTree->TreeTraverse();
	cout<<endl;
	//查找
	int *num = pTree->SearchNode(2);
	cout<< *num<<endl;
	//
	delete pTree;
	return 0;
}