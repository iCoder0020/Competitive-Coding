/*
ID: ishan_sang
PROG: PRDRG
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T,N;
	long long int num[26];
	long long int den[26];

	num[1] = 1;
	den[1] = 2;

	num[2] = 1;
	den[2] = 4;

	for(int i = 3; i<=25; i++)
	{
		num[i] = num[i-1] + 2*num[i-2];
		den[i] = den[i-1] + 2*den[i-2];
	}
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		cout<<num[N]<<" "<<den[N]<<" ";
	}
	cout<<"\n";
	return 0;
}