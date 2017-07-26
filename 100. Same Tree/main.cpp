#include "iostream"
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) 
{
	if(p==NULL&&q==NULL)
    {return true;}  
    else if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL))
    {return false;}
    if(p->val==q->val)
    {return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);}
    else
    {return false;}
}

//使用广度优先搜索的方法进行对比，广度优先搜索使用队列
bool isSameTree1(TreeNode *p, TreeNode *q)
{
	if(p==NULL&&q==NULL)
    {return true;} 
	if (!isSameNode(p, q))
	{
		return false;
	}
	queue<TreeNode*> lqueue;
	queue<TreeNode*> rqueue;
	lqueue.push(p);
	rqueue.push(q);
	while(!lqueue.empty()||!lqueue.empty())
	{

		TreeNode * lp = lqueue.front();
		TreeNode * rp = rqueue.front();
		lqueue.pop();
		rqueue.pop();
		if (!isSameNode(lp->left, rp->left))
		{
			return false;
		}
		else
		{
			if (lp->left!=NULL&&rp->left!=NULL)
			{
				lqueue.push(lp->left);
				rqueue.push(rp->left);
			}
		}
		if (!isSameNode(lp->right, rp->right))
		{
			return false;
		}
		else
		{
			if (lp->right!=NULL&&rp->right!=NULL)
			{
				lqueue.push(lp->right);
				rqueue.push(rp->right);
			}
		}
	}
	return true;
}

bool isSameNode(TreeNode *p, TreeNode *q)
{
	if(p==NULL&&q==NULL)
    {return true;}  
    else if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL))
    {return false;}
    if(p->val==q->val)
    {return true;}
    else
    {return false;}
}