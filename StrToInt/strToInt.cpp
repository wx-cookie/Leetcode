#include"iostream"
using namespace std;

int StrToInt(const char *string)
{
	int number =0;
	while(*string != '\0')
	{
		number=number*10 + *string-'0';
		string++;
		//cout<<*string;
	}
	return number;
}

int main()
{
	const char * str;
	str = "1202";
	//cout<<*str<<endl;
	cout<<StrToInt(str);
	//cout<<str[3]<<endl;
	//cout<<str[4]<<endl;
	if (str[4]==0)
	{
		cout<<"yes";
	}
	char a []="123";
	cout<<"........"<<endl;

	char str1[] = "hello";
	const char *str3="hello";
	cout<<*(str1+1);
	cout<<*(str3+1);
	cout<<endl;
	cout<<"------";
	int num =2;
	//int a = 44;
	int * charNum = &num;
	cout<<charNum<<endl;
	cout<<*charNum<<endl;
	/**charNum =1;
	int * num1 =&num;
	*num1=4;
	cout<<num<<endl;

	num1 = &a;
	cout<<*num1<<endl;*/
	return 0;
}