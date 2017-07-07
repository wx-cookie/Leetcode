#include "iostream"
#include <stack>
using namespace std;

bool isValid(string s) {
        int length = s.length();
        stack <char> stac ;
        for (int i = 0; i < length; ++i)
        {
        	if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        	{
        		if (stac.empty() == true)
        		{
        			return false;
        		}
        		else if (s[i] == ')' && stac.top() == '(')
        		{
        			stac.pop();
        		}
        		else if (s[i] == ']' && stac.top() == '[')
        		{
        			stac.pop();
        		}
        		else if (s[i] == '}' && stac.top() == '{')
        		{
        			stac.pop();
        		}
        		else
        		{
        			return false;
        		}
        	}
        	else
        	{
        		stac.push(s[i]);
        	}
        }
        return stac.empty();
    }


int main ()
{
	cout<<isValid("()");
	return 0;
}