#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int L;
    int R;
    int ansL;
    int ansR;
};

void dfs(int u, int p, vector<vector<int>>&g, vector<node>&val)
{
    for(int v: g[u])
    {
        if(v == p)
            continue;
        dfs(v, u, g, val);
        int LL = abs(val[u].L-val[v].L) + val[v].ansL;
        int LR = abs(val[u].L-val[v].R) + val[v].ansR;
        int RL = abs(val[u].R-val[v].L) + val[v].ansL;
        int RR = abs(val[u].R-val[v].R) + val[v].ansR;
        val[u].ansL += max(LL, LR);
        val[u].ansR += max(RL, RR);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin>>TC;
    while(TC--)
    {
        int N;
        cin>>N;
        vector<vector<int>>g(N+1);
        vector<node>val(N+1);
        for(int i = 1; i<=N; i++)
        {
            cin>>val[i].L>>val[i].R;
            val[i].ansL = val[i].ansR = 0;
        }
        for(int i = 1; i<N; i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 1, g, val);
        cout<<max(val[1].ansL, val[1].ansR)<<endl;
    }
    return 0;
}