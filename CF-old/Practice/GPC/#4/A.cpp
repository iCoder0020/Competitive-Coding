#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define INF 1e18

void dijkstra(vector<vector<pii>>&g, vector<int>&dist, int start)
{
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push({0, start});
	while(!pq.empty())
	{
		int c = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		dist[u] = min(dist[u],c);
		for(pair<int,int>p: g[u])
		{
			int v = p.first;
			int w = p.second;
			if(c+w<=dist[v])
				pq.push({c+w, v});
		}
	}	
}

int32_t main()
{
	int N,M;
	cin>>N>>M;
	int S,E;
	cin>>S>>E;

	map<pii,int>MAP;

	vector<vector<pii>>g(N+1);

	for(int m = 0; m<M; m++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(MAP.find({u,v}) == MAP.end())
			MAP[{u,v}]=w;
		else
			MAP[{u,v}]=min(MAP[{u,v}], w);
	}

	for(auto it: MAP)
	{
		int u = it.first.first;
		int v = it.first.second;
		int w = it.second;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	vector<int>T(N+1);
	vector<int>C(N+1);

	for(int n = 1; n<=N; n++)
		cin>>T[n]>>C[n];

	vector<vector<int>>APSP(N+1, vector<int>(N+1, INF));

	for(int i = 1; i<=N; i++)
		dijkstra(g,APSP[i],i);

	vector<vector<pii>>newg(N+1);
	vector<int>D(N+1, INF);

	for(int i = 1; i<=N; i++)
		for(int j = 1; j<=N; j++)
			if(i!=j && APSP[i][j]<=T[i])
				newg[i].push_back({j,C[i]});

	dijkstra(newg,D,S);

	if(D[E] == INF)
		cout<<-1;
	else
		cout<<D[E];
	cout<<endl;
	return 0;
}
