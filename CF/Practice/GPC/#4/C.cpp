#include <bits/stdc++.h>

using namespace std;

#define int long long

int shortest_distance_sum(vector<vector<int>>&g, int N)
{
	int u,v,w;
	cin>>u>>v>>w;

	if(w<g[u][v])
	{

		g[u][v] = w;
		g[v][u] = w;

		for(int n = 1; n<=N; n++)
			for(int m = 1; m<=N; m++)
				g[n][m] = min({g[n][m], g[n][u]+g[v][m]+w, g[n][v]+g[u][m]+w});

	}
	int sum = 0;
	for(int n = 1; n<=N; n++)
		for(int m = 1; m<=N; m++)
			sum += g[n][m];
	return sum/2;
}

int32_t main()
{
	int N;
	cin>>N;
	vector<vector<int>>g(N+1, vector<int>(N+1));
	for(int n = 1; n<=N; n++)
		for(int m = 1; m<=N; m++)
			cin>>g[n][m];
	int M;
	cin>>M;
	while(M--)
		cout<<shortest_distance_sum(g,N)<<" ";
	cout<<endl;
	return 0;
}
