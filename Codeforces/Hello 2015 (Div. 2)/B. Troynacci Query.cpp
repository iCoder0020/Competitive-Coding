/*
ID: iCoder0020
PROG: Troynacci Query
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

#define MOD 1000*1000*1000+7

using namespace std;

int main()
{
	int N,Q;
	cin>>N>>Q;
	li F[N+1];
	cin>>F[1]>>F[2];
	li A,B;
	cin>>A>>B;
	for(int n = 3; n<=N; n++)
	{
		F[n] = ((A*F[n-2])%MOD + (B*F[n-1])%MOD)%MOD;
	}
	li seq[N];
	for(int n = 0; n<N; n++)
	{
		cin>>seq[n];
	}
	int L,R;
	while(Q--)
	{
		cin>>L>>R;
	}
	return 0;
}