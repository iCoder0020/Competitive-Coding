#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,M,K,W;
	cin>>N>>M>>K>>W;
	int ans = 0;
	vector<vector<vector<char>>>lvl(K, vector<vector<char>>(N, vector<char>(M)));
	vector<pair<int,int>>choices;
	for(int k = 0; k<K; k++)
	{
		for(int n = 0; n<N; n++)	
			for(int m = 0; m<M; m++)
				cin>>lvl[k][n][m];
	}
	vector<vector<pair<int,int>>>edges(K+1, vector<pair<int,int>>(K+1));
	for(int j = 1; j<=K; j++)
		edges[0][j] = {N*M, j};
	for(int i = 1; i<=K; i++)
	{
		for(int j = 1; j<i; j++)
		{
			int transit = 0;
			for(int n = 0; n<N; n++)
				for(int m = 0; m<M; m++)
					if(lvl[i-1][n][m]!=lvl[j-1][n][m])
						transit++;
			if(transit*W < N*M)
			{
				edges[i][j] = {transit*W, j};
				edges[j][i] = {transit*W, i};
			}
		}
	}
	vector<bool>vis(K+1, false);
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
	for(pair<int,int>p: edges[0])
		pq.push({p.first, {p.second,0}});
	vis[0] = true;
	while(!pq.empty())
	{
		int u = pq.top().second.second;
		int v = pq.top().second.first;
		int w = pq.top().first;
		pq.pop();
		if(vis[v])
			continue;
		ans += w;
		if(w == N*M)
			choices.push_back({v,0});
		else
			choices.push_back({v,u});
		vis[v] = true;
		for(pair<int,int>p: edges[v])
		{
			if(vis[p.second])
				continue;
			pq.push({p.first,{p.second,v}});
		}
	}
	cout<<ans<<endl;
	for(pair<int,int>p: choices)
		cout<<p.first<<" "<<p.second<<endl;
	return 0;
}
