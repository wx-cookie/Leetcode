#include<iostream>
using namespace std;


double myPow(double x, int n)
{
	if (n==0)
	{
		return 1;
	}
	if (n<0)
	{
		if (n == INT_MIN)
			return 1.0 / (myPow(x,INT_MAX)*x);
		else
			return 1.0 / myPow(x, -n);
	}
	return x*myPow(x, n-1);
}
double myPow_2(double x, int n)
{
	double res=1;
	if (n==0)
		return 1;
	if (n<0)
	{
		if (n == INT_MIN)
			return 1.0 / (myPow_2(x,INT_MAX)*x);
		else
			return 1.0 / myPow_2(x, -n);
	}
	if (n==1)
		return x;
	double half = myPow_2(x, n/2);
	if (n%2==0)
		return half*half;
	else
		return half*half*x;
}

int fibonacci(int num)
{
	if (num==0||num==1)
	{
		return 1;
	}
	else
	{
		return fibonacci(num-1)+fibonacci(num-2);
	}
}

int main ()
{
	cout<<fibonacci(5)<<endl;
	cout<< myPow_2(2,5);
	return 0;
}