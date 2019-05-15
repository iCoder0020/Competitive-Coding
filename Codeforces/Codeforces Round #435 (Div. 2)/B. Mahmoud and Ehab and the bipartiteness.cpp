/*
ID: iCoder0020
PROG: Mahmoud and Ehab and the bipartiteness
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long
#define pb(x) push_back(x);

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	vector<pair<vector<int>,char>>g;
	g.clear();
	g.resize(N+1);
	for(int n = 0; n<N-1; n++)
	{
		int u,v;
		cin>>u>>v;
		g[u].first.pb(v);
		g[v].first.pb(u);
	}
	int red = 0;
	int black = 0;
	queue<int>Q;
	vector<bool>visited(N+1, false);
	Q.push(1);
	visited[1] = true;
	g[1].second = 'r';
	while(!Q.empty())
	{
		int temp = Q.front();
		Q.pop();
		for(auto it: g[temp].first)
			if(!visited[it])
			{
				g[it].second = (g[temp].second == 'r') ? 'b' : 'r';
				visited[it] = true;
				Q.push(it);
			}
	}
	for(auto it: g)
		(it.second == 'r')? red++ : black++;

	black--;
	cout<<red*black-(N-1)<<endl;
	return 0;
}