#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	vector<int>A(N+1), B(N+1), C(N+1);
	for(int n = 0; n<N; n++)
		cin>>A[n]>>B[n]>>C[n];
	vector<vector<int>>g(N+1);
	for(int i = 0; i<N-1; i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	return 0;
}
