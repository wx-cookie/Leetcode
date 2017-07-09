#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string countAndSay(int n) 
{
	if (n==1)
	{
		return "1";
	}

	string str = countAndSay(n-1) +"*";
	string s= "";
	int count =1;
	for (int i = 0; i < str.length()-1; i++)
	{
		if (str[i]==str[i+1])
		{
			count++;
		}
		else
		{
			stringstream ss;
    		string str_count;
    		ss<<count;
    		ss>>str_count;
			s = s + str_count + str[i];
			count = 1;
		}
	}
	return s;
}


int main()
{
	/*
	1.    1
	2.    11
	3.    21
	4.    1211
	5.    111221
	*/
	cout<<countAndSay(5);
	cout<<to_string(6);//int 转 string
	return 0;
}