/*
ID: ishan_sang
PROG: ATM2
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T,N;
	int K;
	int num;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>K;
		for(int n = 0; n<N; n++)
		{
			cin>>num;
			if(num>K)
			{
				cout<<"0";
			}
			else
			{
				cout<<"1";
				K -= num;
			}
		}
		cout<<"\n";
	}
	return 0;
}