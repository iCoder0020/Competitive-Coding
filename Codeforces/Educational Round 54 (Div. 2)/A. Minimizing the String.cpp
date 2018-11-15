/*
ID: iCoder0020
PROG: Minimizing the String
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	char str[N];
	int max = 0;
	int index = N-1;
	for(int n = 0; n<N; n++)
	{
		cin>>str[n];
		if(n>0)
		{
			if(str[n]<str[n-1] && index == N-1)
			{
				index = n-1;
			}
		}
	}
	for(int n = 0; n<N; n++)
	{
		if(index != n)
		{
			cout<<str[n];
		}
	}
	cout<<endl;
	return 0;
}