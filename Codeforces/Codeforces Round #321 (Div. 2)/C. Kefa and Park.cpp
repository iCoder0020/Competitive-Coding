/*
ID: iCoder0020
PROG: Kefa and Park
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long
#define pb(x) push_back(x) 

using namespace std;

int N,M;
vector<pair<vector<int>, int>> g;

int dfs(int x, int cats, int p)
{
	if(cats > M)
		return 0;
	if(g[x].first.size() == 1 && x != 1)
		return 1;
	int cnt = 0;
	for(auto y: g[x].first)
		if(y != p)
			cnt += dfs(y, g[y].second?cats+1:0, x);
	return cnt;
}

int32_t main()
{
	cin>>N>>M;
	g.clear();
	g.resize(N+1);
	for(int n = 1; n<=N; n++)
		cin>>g[n].second;
	for(int m = 0; m<N-1; m++)
	{
		int x,y;
		cin>>x>>y;
		g[x].first.pb(y);
		g[y].first.pb(x);
	}
	cout<<dfs(1, g[1].second, -1)<<endl;
	return 0;
}