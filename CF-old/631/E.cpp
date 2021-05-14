#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,Q;
	cin>>N>>Q;
	vector<vector<int>> g(N);
	for(int n = 0; n<N-1; n++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	while(Q--)
	{
		int K;
		cin>>K;
		int vertices[K];
		for(int k = 0; k<K; k++)
			cin>>vertices[k];
	}
	return 0;
}
