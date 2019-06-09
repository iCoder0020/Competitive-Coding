/*
ID: ishan_sang
PROG: ABDTOLL
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>>g;

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,X,K;
		cin>>N>>X>>K;
		int TL[N+1];
		for(int n = 1; n<=N; n++)
			cin>>TL[i];
		g.clear();
		g.resize(N+1);
		for(int n = 0; n<N-1; n++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		
	}
    return 0;
}