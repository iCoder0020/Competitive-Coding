#include <bits/stdc++.h>

using namespace std;

#define int long long

map<int,pair<int,int>>dmap;

#define INF 1e12
#define pipi pair<int,pair<pair<int,int>,int>>

int pqfs(vector<vector<char>>&g, int x, int y, int N, int M)
{
	vector<vector<bool>>vis(N, vector<bool>(M, false));
	priority_queue<pipi, vector<pipi>, greater<pipi>>q;
	q.push({-1,{{x,y},0}});
	int ans = INF;
	while(!q.empty())
	{
		int d = q.top().first;
		x = q.top().second.first.first;
		y = q.top().second.first.second;
		int dir = q.top().second.second;
		q.pop();
		if(g[x][y] == 'S')
			ans = min(ans, d);
		vis[x][y] = true;
		for(int i = 1; i<=4; i++)
		{
			int X = x+dmap[i].first, Y = y+dmap[i].second;
			if(X == N || Y == M || X == -1 || Y == -1 || vis[X][Y] || g[X][Y] == '*')
				continue;
			if(i == dir)
				q.push({d,{{X,Y},i}});
			else
				q.push({d+1,{{X,Y},i}});
		}
	}
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N,M;
	cin>>N>>M;
	dmap[1] = {-1,0};
	dmap[2] = {0,1};
	dmap[3] = {1, 0};
	dmap[4] = {0, -1};
	vector<vector<char>>g(N, vector<char>(M));
	int x, y, a, b;
	for(int n = 0; n<N; n++)
	{
		for(int m = 0; m<M; m++)
		{
			cin>>g[n][m];
			if(g[n][m] == 'T')
				x = n, y = m;
			if(g[n][m] == 'S')
				a = n, b = m;
		}
	}
	int ans = pqfs(g, x, y, N, M);
	if(ans <= 2)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
