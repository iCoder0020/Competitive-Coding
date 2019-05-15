/*
ID: icoder_0020
PROG: Social Networking Graph
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;

#define int long long
 
int bfs(int n, vector<vector<int>> &adj_list, int s, int k)
{
	int cnt = 0;
	vector<bool>visited(n, false);
	queue<pair<int,int>>Q;
	int x = 0;
	Q.push({s, x});

	while(!Q.empty())
	{
		pair<int,int> top = Q.front();
		if(!visited[top.first])
		{
			for(auto it: adj_list[top.first])
				Q.push({it, top.second+1});
			visited[top.first] = true;
			if(k == top.second)
				cnt++;
		}
		Q.pop();
	}
	return cnt;
}

int32_t main()
{
	int N,M;
	cin>>N>>M;
	vector<vector<int>>adj_list(N);
	int u,v;
	for(int m = 0; m<M; m++)
	{
		cin>>u>>v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int s,k;
		cin>>s>>k;
		cout<<bfs(N, adj_list, s, k)<<endl;
	}
	return 0;
}