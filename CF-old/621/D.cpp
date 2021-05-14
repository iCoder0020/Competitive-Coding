#include <bits/stdc++.h>

using namespace std;

#define int long long

void shortest_distance(vector<vector<int>>&g, vector<int> &dist, int start)
{
	queue<pair<int,int>>Q;
	vector<bool> vis(g.size(), false);
	Q.push({start, 0});
	vis[start] = true;
	while(!Q.empty())
	{
		int u = Q.front().first;
		int d = Q.front().second;
		Q.pop();

		dist[u] = d;

		for(auto it: g[u])
		{
			if(!vis[it])
			{
				vis[it] = true;
				Q.push({it, d+1});
			}
		}
	}
}

bool poss(vector<pair<int,int>> &A, vector<pair<int,int>> &B, vector<int> &dist1, vector<int> &distN, int N, int x)
{
	map<pair<int,int>,int>M;
	for(int n = 0; n<N; n++)
	{
		int a = A[n].first;
		int idxa = A[n].second;
		int b, idxb;
		for(int m = N-1; m>=0; m--)
		{
			if(B[m].second != idxa)
			{
				b = B[m].first;
				idxb = B[m].second;
				break;
			}
		}
		if(M.find({min(idxa, idxb), max(idxa, idxb)}) == M.end())
			M[{min(idxa, idxb), max(idxa, idxb)}] = a+min(distN[idxa], b+1);
		else
			M[{min(idxa, idxb), max(idxa, idxb)}] = min(M[{min(idxa, idxb), max(idxa, idxb)}], a+min(distN[idxa], b+1));
	}
	for(auto it: M)
		if(it.second >= x)
			return true;
	return false;
}

int32_t main()
{
	int N,M,K;
	cin>>N>>M>>K;
	vector<int> special(K);
	vector<vector<int>> g(N+1);
	for(int k = 0; k<K; k++)
		cin>>special[k];
	for(int m = 0; m<M; m++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> dist1(N+1, 0);
	vector<int> distN(N+1, 0);
	shortest_distance(g, dist1, 1);
	shortest_distance(g, distN, N);

	vector<pair<int,int>> A;
	vector<pair<int,int>> B;

	for(auto it: special)
	{
		A.push_back({dist1[it], it});
		B.push_back({distN[it], it});
	}

	sort(B.begin(), B.end());

	int lo = 1, hi = dist1[N], mid;
	while(lo < hi)
	{
		mid = lo + (hi-lo+1)/2;
		if(poss(A, B, dist1, distN, K, mid))
			lo = mid;
		else
			hi = mid-1;
	}
	cout<<lo<<endl;

	return 0;
}