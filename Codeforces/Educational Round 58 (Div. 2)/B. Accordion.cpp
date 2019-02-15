/*
ID: iCoder0020
PROG: Accordion
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>>S;
	int len = S.length();
	int count = 0;
	int index0 = -1;
	int index1 = -1;
	int index2 = -1;
	int index3 = -1;
	int ans = 0;
	for(int n = 0; n<len; n++)
	{
		if(S[n] == '[')
		{
			index0 = n;
			break;
		}	
	}

	for(int n = index0+1; n<len; n++)
	{
		if(S[n] == ':')
		{
			index1 = n;
			break;
		}
	}

	for(int n = len-1; n>index1; n--)
	{
		if(S[n] == ']')
		{
			index3 = n;
			break;
		}
	}

	for(int n = index3-1; n>index1; n--)
	{
		if(S[n] == ':')
		{
			index2 = n;
			break;
		}
	}

	for(int n = index1+1; n<index2; n++)
	{
		if(S[n] == '|')
		{
			count++;
		}
	}
	if(index0 != -1 && index1 != -1 && index2 != -1 && index3 != -1)
	{
		cout<<4+count<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	
	return 0;
}