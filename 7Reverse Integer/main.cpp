#include<iostream>
using namespace std;

#define MAXNum 2147483647

int reverse(int x)
{
	int flag = 1;
	if (x < 0)
	{
		flag = -1;
		x = -x;
	}
	int res=0;
	int z=0;
	while(x>0)
	{
		z = x % 10;//求得余数
		if (res * 10.0 + z > 2147483647)
		{
			return 0;
		}
		res = res * 10 + z;
		x=x/10;//去掉最后一位剩下的数
	}
	return res*flag;
}
int main()
{
	//cout<<"hello world";
	int a = reverse(1534236469);
	cout<<a;
	return 0;
	//system("pause");
}