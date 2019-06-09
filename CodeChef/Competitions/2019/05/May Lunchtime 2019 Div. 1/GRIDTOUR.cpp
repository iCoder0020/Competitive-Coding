/*
ID: ishan_sang
PROG: GRIDTOUR
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,M,K;
		cin>>N>>M>>K;
		if(__gcd(N,K) == 1 && __gcd(M,K) == 1)
			cout<<N*M;
		else 
			cout<<-1;
		cout<<endl;
	}
    return 0;
}