/*
ID: ishan_sang
PROG: CLIQUED
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long
#define INF 1e16
using namespace std;

int32_t main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int N,K,X,M,S;
        cin>>N>>K>>X>>M>>S;
        vector<pair<int,int>> adj[N+2];
        for(int m = 0; m<M; m++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            w *= 2;
            if(u )
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        for(int i = 1; i<=K; i++)
        {
            adj[i].push_back({N+1, X});
            adj[N+1].push_back({i, X});
        }

        vector<int>dis(N+2, INF);
        vector<bool>vis(N+2, false);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,S});
        dis[S] = 0;

        while(!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            int u = temp.second;
            vis[u] = true;
            for(auto it: adj[u])
            {
                int v = it.first;
                int w = it.second;
                if(vis[v] == false && dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u]+w;
                    pq.push({dis[v], v});
                }
            }
        }
        for(int i = 1; i<=N; i++)
            cout<<dis[i]/2<<" ";
        cout<<endl;
    }
    return 0;
}
