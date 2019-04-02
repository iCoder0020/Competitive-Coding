/*
ID: ishan_sang
PROG: NBONACCI
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N,Q;
	cin>>N>>Q;
	int F[N];
	int prefixF[N];
	for(int n = 0; n<N; n++)
	{
		cin>>F[n];
		if(n)
			prefixF[n] = prefixF[n-1]^F[n];
		else
			prefixF[n] = F[n];
	}
	while(Q--)
	{
		int K;
		cin>>K;
		if(K%(N+1) == 0)
			cout<<0;
		else
			cout<<prefixF[K%(N+1)-1];
		cout<<endl;
	}
	return 0;
}