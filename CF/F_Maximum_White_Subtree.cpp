#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>>g;
vector<int>c;
vector<int>ans;

void dfs(int u, int p)
{
    int sum = (c[u]==0)?-1:1;
    for(int v: g[u])
    {
        if(v == p)
            continue;
        dfs(v,u);
        if(ans[v]>0)
            sum += ans[v];
    }
    ans[u] = max(ans[u], sum);
}

void dfs2(int u, int p)
{
    if(ans[p] - ans[u]>0)
        ans[u] = ans[p]-ans[u];
    ans[u] += (c[u]==0)?-1:1;
    for(int v: g[u])
    {
        if(v == p)
            continue;
        if(ans[v]>0)
            ans[u] += ans[v];
        dfs2(v,u);
    }
}

int32_t main()
{
    int N;
    cin>>N;
    g.resize(N+1);
    c.resize(N+1);
    ans.resize(N+1);
    for(int n = 1; n<=N; n++)
    {
        cin>>c[n];
        ans[n] = (c[n] == 0)?-1:1;
    }
    for(int n = 0; n<N-1; n++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    dfs2(1,0);
    for(int n = 1; n<=N; n++)
        cout<<ans[n]<<" ";
    cout<<endl;
    return 0;
}