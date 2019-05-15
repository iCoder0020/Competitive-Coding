/*
ID: iCoder0020
PROG: Graph Without Long Directed Paths
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long 
#define pb(x) push_back(x)

using namespace std;

vector<vector<int>> g;

int32_t main()
{
	int N.M;
	cin>>N>>M;
	g.clear();
	g.resize(N+1);
	for(int m = 0; m<M; m++)
	{
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	return 0;
}