#include <bits/stdc++.h>

using namespace std;

#define int long long



int32_t main()
{
	int N;
	cin>>N;
	vector<vector<int>>g(N+1);
	for(int n = 1; n<N; n++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	return 0;
}
