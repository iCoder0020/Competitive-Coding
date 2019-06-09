/*
ID: ishan_sang
PROG: SUBREM
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int N,X;
vector<int>A;
vector<vector<int>>adj;
vector<bool>vis;

int calc(int s)
{
	vis[s] = true;
	int sum = A[s];
	for(auto it: adj[s])
	{
		if(!vis[it])
			sum += calc(it); 
	}
	return max(-X, sum);
}

void reset()
{
	A.clear();
	A.resize(N);
	adj.clear();
	adj.resize(N);
	vis.clear();
	vis.resize(N,false);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
    	cin>>N>>X;
    	reset();
    	for(int n = 0; n<N; n++)
    		cin>>A[n];
    	for(int n = 0; n<N-1; n++)
    	{
    		int u,v;
    		cin>>u>>v;
    		adj[u-1].push_back(v-1);
    		adj[v-1].push_back(u-1);
    	}
    	cout<<calc(0)<<endl;
    }
    return 0;
}	