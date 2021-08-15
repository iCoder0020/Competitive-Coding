#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vertex pair<int,pair<int,int>>


int32_t main()
{
    int N,M,K;
    cin>>N>>M>>K;
    vector<vector<int>>g(N+1);
    set<vector<int>>bad;
    for(int m = 0; m<M; m++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int k = 0; k<K; k++) {
        int a,b,c;
        cin>>a>>b>>c;
        bad.insert({a,b,c});
    }
    vector<pair<int,int>>dist(N+1, {INT_MAX, -1});
    vector<bool>vis(N+1, false);
    priority_queue<vertex, vector<vertex>, greater<vertex>>pq;

    pq.push({0, {1,-1}});

    while(!pq.empty()) {
        vertex z = pq.top();
        pq.pop();
        bool done = true;
        for(bool x: vis)
            done = done&x;
        if(done)
            break;
        
        int d = z.first, u = z.second.first, p = z.second.second;
        if(d < dist[u].first)
            vis[u] = true, dist[u] = {d,p};
        for(int v: g[u]) {
            if(bad.find({p,u,v}) == bad.end())
                pq.push({d+1, {v, u}});
        }
    }

    if(dist[N].first == INT_MAX) {
        cout<<-1<<endl;
    } else {
        cout<<dist[N].first<<endl;
        int node = N;
        vector<int> path;
        while(node != -1) {
            path.push_back(node);
            int par = dist[node].second;
            node = par;
        }
        reverse(path.begin(), path.end());
        for(int x: path) {
            cout<<x<<" ";
        }
    }
    return 0;
}