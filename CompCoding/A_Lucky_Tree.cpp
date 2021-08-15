#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>>g;
vector<set<int>>w;
vector<int>stsize;
vector<int>lksize;
int cnt;
int N;

bool checklucky(int N)
{
    while(N)
    {
        int x = N%10;
        if(x!=4 && x!=7)   
            return false;
        N/=10;
    }
    return true;
}

void precompdfs(int u, int p)
{
    stsize[u] = 1;
    lksize[u] = 0; 
    for(int v: g[u])
    {   
        if(v == p)
            continue;
        precompdfs(v, u);
        stsize[u] += stsize[v];
        if(w[u].find(v) != w[u].end())
            lksize[u] += stsize[v];
        else
            lksize[u] += lksize[v];
    }
}

void dfs(int u, int p)
{
    cnt += lksize[u]*(lksize[u]-1);
    bool lucky;
    for(int v: g[u])
    {   
        lucky = false;
        if(v == p)
            continue;
        if(w[u].find(v) != w[u].end())
            lucky = true;
        int z = lksize[v];
        if(lucky)
            lksize[v] += N - stsize[v];
        else
            lksize[v] += lksize[u] - lksize[v];
        dfs(v, u);
        lksize[v] = z;
    }
}

int32_t main()
{
    cin>>N;
    g.resize(N+1);
    w.resize(N+1);
    stsize.resize(N+1);
    lksize.resize(N+1);
    cnt = 0;
    for(int n = 0; n<N-1; n++)
    {
        int u,v,x;
        cin>>u>>v>>x;
        g[u].push_back(v);
        g[v].push_back(u);
        if(checklucky(x))
        {
            w[u].insert(v);
            w[v].insert(u);
        }
    }
    precompdfs(1,0);
    dfs(1,0);
    cout<<cnt<<endl;
    return 0;
}