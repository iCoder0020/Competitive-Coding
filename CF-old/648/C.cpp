#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int A[N], B[N];
	int Ai[N+1], Bi[N+1];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		Ai[A[n]] = n;
	}
	for(int n = 0; n<N; n++)
	{
		cin>>B[n];
		Bi[B[n]] = n;
	}
	map<int,int> M;
	for(int n = 1; n<=N; n++)
		M[(Bi[n]-Ai[n]+N)%N]++;
	int x = 0;
	for(auto it: M)
		x = max(x, it.second);
	cout<<x<<endl;
	return 0;
}
