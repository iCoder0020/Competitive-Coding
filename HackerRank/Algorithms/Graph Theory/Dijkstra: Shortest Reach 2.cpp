/*
ID: iCoder0020
PROG: Dijkstra: Shortest Reach 2
LANG: C++                  
*/

#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        int N,M;
        cin>>N>>M;
        int start;
        vector<pair<int,int>>adj[N+1];
        map<pair<int,int>, int> MAP;
        for(int m = 0; m<M; m++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            if(MAP.find({u,v}) == MAP.end())
                MAP[{u,v}] = w;
            else
                MAP[{u,v}] = min(MAP[{u,v}], w);
        }
        for(auto it: MAP)
        {
            int u = it.first.first;
            int v = it.first.second;
            int w = it.second;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        cin>>start;
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
                    cout<<-1<<" ";
                else
                    cout<<dis[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
