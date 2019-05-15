/*
ID: icoder_0020
PROG: Shortest Path Problem
LANG: C++                  
*/

#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int N,M;
    cin>>N>>M;
    int start;
    vector<pair<int,int>>adj[N+1];
    for(int m = 0; m<M; m++)
    {
        int u,v,w;
        cin>>u>>v>>w;
    	adj[u].push_back({v, w});
    }
    start = 1;
    vector<int>dis(N+1, INT_MAX);
    vector<bool>vis(N+1,false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, start});
    dis[start] = 0;

    while(!pq.empty())
    {
        int u  = pq.top().second;
        pq.pop();
        vis[u] = true;
        for(auto it: adj[u])
        {
            int v = it.first;
            int w = it.second;
            
            if(vis[v] == false && dis[v] > dis[u]+w)
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    for(int i = 1; i<=N; i++)
    {
        if(i != start)
        {
            if(dis[i] == INT_MAX)
                cout<<1000000000<<" ";
            else
                cout<<dis[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}