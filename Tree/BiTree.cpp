#include "iostream"
using namespace std;

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree &T)
{
	int data;
	cin>>data;
	if (data==0)
	{
		T=NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data=data;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

void PreOrder(BiTree T)
{
	BiTree p;
	BiTree s[20];
	int i;
	if (T==NULL)
	{
		return;
	}
	else
	{
		i=0;
		p=T;
	}
	do
	{
		while(p!=NULL)
		{
			cout<<p->data<<" ";//打印数据
			if (p->rchild!=NULL)
			{
				i++;
				s[i] = p->rchild;//右儿子进栈
			}
			p = p->lchild;//指向左儿子
		}
		if (i!=0)
		{
			p = s[i];
			i--;
		}
		
	} while (i!=0||p!=NULL);
}
//中序遍历
void PreOrder1(BiTree T)
{
	BiTree p;
	BiTree s[20];
	int i;
	if (T==NULL)
	{
		return;
	}
	else
	{
		i = 0;
		p = T;
	}
	do
	{
		while(p!=NULL)
		{
			s[++i]=p;
			p=p->lchild;
		}
		if (i!=0)
		{
			cout<<s[i]->data<<" ";
			p=s[i]->rchild;
			i--;

		}
	} while (i!=0||p!=NULL);
}

void numNode (BiTree T, int & num)
{
	if (T!=NULL)
	{
		if (T->lchild==NULL&&T->rchild==NULL)
		{
			num++;
		}
		else
		{
			numNode(T->lchild, num);
			numNode(T->rchild, num);
		}
	}
}

void Swap(BiTree &T)
{
	if (T!=NULL)
	{
		if (T->lchild!=NULL||T->rchild!=NULL)
		{
			BiTree p;
			p=T->lchild;
			T->lchild=T->rchild;
			T->rchild=p;
		}
		if (T->lchild!=NULL)
		{
			Swap(T->lchild);
		}
		if (T->rchild!=NULL)
		{
			Swap(T->rchild);
		}
	}
}	

bool Locate(BiTree T, int x, BiTree &p)
{
	if (T==NULL)
	{
		p=NULL;
		return false;
	}
	else
	{
		if (T->data==x)
		{
			p=T;
			return true;
		}
		else
		{
			if (Locate(T->lchild, x, p) == true)
			{
				return true;
			}
			else
			{
				return Locate(T->rchild, x, p);
			}
		}
	}
}

int GetNumNodes(BiTree T)
{
	if (T==NULL)
	{
		return 0;
	}
	return GetNumNodes(T->lchild)+GetNumNodes(T->rchild)+1;
}
int GetDepth(BiTree T)
{
	if (T==NULL)
	{
		return 0;
	}
	int depthL = GetDepth(T->lchild);
	int depthR = GetDepth(T->rchild);
	return depthL > depthR ? (depthL+1):(depthR+1);
}
int main()
{
	BiTree T;
	BiTree p;
	CreateBiTree(T);
	cout<<GetNumNodes(T)<<endl;
	if (Locate(T, 5, p)==true)
	{
		cout<<"Yes"<<endl;
	}
	cout<<"深度为："<<GetDepth(T)<<endl;
	//bool flag = Locate(T, 6, p);
	//cout<<flag<<endl;
	cout<<p->data<<endl;
	//Swap(T);
	PreOrder(T);
	cout<<endl;
	PreOrder1(T);
	cout<<endl;
	int num = 0;
	numNode(T, num);
	cout<<num;
	return 0;
}







