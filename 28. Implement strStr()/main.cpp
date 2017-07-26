#include"iostream"
#include"string"
using namespace std;

int strStr(string haystack, string needle) 
{
	if (needle=="")
	{
		return 0;
	}
    int m = haystack.length();
    int n = needle.length();
    for (int i = 0; i < m-n+1; ++i)
    {
    	int ii=i;
    	for (int j = 0; j < n; ++j)
    	{
    		if (haystack[ii]!=needle[j])
    		{
    			//不相等退出needle的循环，进行haystack下一位判断
    			break;
    		}
    		else
    		{
    			//相等则匹配haystack下一位
    			ii++;
    			if (j==n-1)
    			{
    				return i;
    			}
    		}
    	}
    }
    return -1;
}
//获取next数组
void GetNext(string s, int next[])
{
	int k=-1;//前缀
	int j=0;//后缀
	next[0] = -1;
	int n = s.length();
	while(j<n)//后缀扫描一边结束
	{
		//第一次循环，k的初始值为-1，直接进入if语句，k和j加1使得k=0，j=1，从第二位开始比较
		if (k==-1||s[k]==s[j])
		{
			k++;
			j++;
			//如果相等，就将next[k]赋值给next[j]，避免重复
			if (s[j]==s[k])
			{
				next[j]=next[k];
			}
			//不相等则next[j]为l=k
			else
			{
				next[j] = k;
			}
		}
		//如果k！=-1并且s[k]与s[j]不相等，将k赋值为next[j]
		else
		{
			k = next[j];
		}
	}
}

//s为要被匹配的文本，p为匹配文本
int kmpSearch(string s, string p)
{
	int i=0;
	int j=0;
	int plength = p.length();
	int slength = p.length();
	int next[plength];
	GetNext(p, next);
	while(i<slength && j<plength)
	{
		if (s[i]==p[j]||j==-1)
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j==plength)
	{
		return i-j;
	}
	else
	{
		return -1;
	}
}
int main()
{
	cout<<kmpSearch("abcdqcdwe", "cdqcd");
	return 0;
}