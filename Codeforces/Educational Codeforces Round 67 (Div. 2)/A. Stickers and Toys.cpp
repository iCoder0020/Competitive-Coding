/*
ID: iCoder0020
PROG: Stickers and Toys
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,S,T;
		cin>>N>>S>>T;
		cout<<N-min(S,T)+1<<endl;
	}
	return 0;
}