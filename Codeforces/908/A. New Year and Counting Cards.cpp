/*
ID: iCoder0020
PROG: New Year and Counting Cards
LANG: C++                  
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int count = 0;
	char arr[10] = {'1', '3', '5', '7', '9', 'a', 'e', 'i', 'o', 'u'};
	cin>>s;
	for(int i = 0; i<s.length(); i++)
	{
		for(int j = 0; j<10; j++)
		{
			if(s[i] == arr[j])
			{
				count++;
				break;
			}
		}
	}
	cout<<count<<"\n";
	return 0;
}