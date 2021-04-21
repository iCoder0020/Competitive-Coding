#include <bits/stdc++.h>

using namespace std;

#define int long long

void bfs(vector<vector<int>>&g, vector<bool>&vis, int u, int t)
{
	queue<pair<int,int>>Q;
	Q.push({u, 0});
	while(!Q.empty())
	{
		int v = Q.front().first;
		int l = Q.front().second;
		Q.pop();
		if(l>v/2 || vis[v])
			continue;
		vis[v] = true;
		for(auto it: g[v])
		{
			if(!vis[it])
				Q.push({it,l+1});
		}
	}
}

int32_t main()
{
	int N,k;
	cin>>N>>k;
	char A[N+k],B[N+k];
	for(int n = 0; n<N; n++)
		cin>>A[n];
	for(int n = 0; n<N; n++)
		cin>>B[n];
	for(int n = N; n<N+k; n++)
		A[n] = B[n] = '-';
	vector<vector<int>>g(2*N+2*k);
	for(int n = 0; n<N; n++)
	{
		//2*n   -> A 
		//2*n+1 -> B

		if(n+1<N+k && A[n]!='X' && A[n+1] != 'X')
		{
			g[2*n].push_back(2*n+2);
			g[2*n+2].push_back(2*n);
		}
		if(n+1<N+k && B[n]!='X' && B[n+1] != 'X')
		{
			g[2*n+1].push_back(2*n+3);
			g[2*n+3].push_back(2*n+1);
		}
		if(A[n]!='X' && B[n+k] != 'X')
			g[2*n].push_back(2*n+2*k+1);
		if(B[n]!='X' && A[n+k] != 'X')
			g[2*n+1].push_back(2*n+2*k);
	}

	vector<bool>vis(2*N+2*k, false);

	bfs(g,vis,0,0);

	bool poss = false;
	for(int n = 2*N; n<2*N+2*k; n++)
		if(vis[n])
			poss = true;
	if(poss)
		cout<<"YES";
	else
		cout<<"NO";
	cout<<endl;
	return 0;
}
