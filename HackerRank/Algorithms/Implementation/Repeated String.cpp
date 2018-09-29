/*
ID: iCoder0020
PROG: Repeated String
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	long int N;
	cin>>S;
	cin>>N;
	long int count = 0;
	long int total = 0;
	long int upto_this = 0;
	for(int i = 0; i<S.length(); i++)
	{
		if(S[i] == 'a')
		{
			if(i<N%S.length())
			{
				upto_this++;
			}	
			total++;
		}
	}	
	count = total*(N/S.length()) + upto_this;
	cout<<count<<"\n";
	return 0;
}
