#include <bits/stdc++.h>
using namespace std;
#define int long long

int N,K;
int cnt;
vector<vector<int>>d;
vector<vector<int>>g;

void dfs(int u, int p)
{
    d[u][0] = 1;
    vector<int>D(K+1, 0);
    for(int v: g[u])
    {
        if(v == p)
            continue;
        dfs(v, u);
        // if there are x nodes at a distance of k-1 from v; there 
        // will be x nodes at a distance of k from u in that subtree
        for(int k = 1; k<=K; k++)
            d[u][k] += d[v][k-1];
        // choose nodes at distance k passing through current child
        // and at distance K-k passing through children seen so far
        for(int k = 1; k<=K-1; k++)
            cnt += d[v][k-1] * D[K-k-1];
        // update D to accomodate for the new children
        for(int k = 0; k<=K; k++)
            D[k] += d[v][k];
    }
    // add nodes which are directly at a distance of K from u
    cnt += d[u][K];
}

int32_t main()
{
    cin>>N>>K;
    cnt = 0;
    g.resize(N+1);
    d.resize(N+1, vector<int>(K+1, 0));
    for(int n = 0; n<N-1; n++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<cnt;
    return 0;
}