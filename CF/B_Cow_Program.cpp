#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;
vector<int>A;
vector<vector<pair<int,int>>>g;
vector<vector<pair<int,int>>>revg;
map<pair<int,int>,int>ans;

void bfs(int u, bool sign)
{
    queue<pair<int,int>>Q;
    Q.push({u, sign});
    while(!Q.empty())
    {
        int u = Q.front().first;
        bool sign = Q.front().second;
        Q.pop();
        for(pair<int,int>p : revg[u])
        {
            int v = p.first;
            int w = p.second;
            //  sign -> true if +edge, false if -edge
            bool next_sign = (w>0);
            if(sign == next_sign)
                continue;
            int x = A[v], y = A[u];
            if(!next_sign)
                x *= -1;
            if(!sign)
                y *= -1;
            ans[{v, x}] = ans[{u, y}] + abs(x);
            Q.push({v, next_sign});
        }
    }
}

int32_t main()
{
    cin>>N;
    A.resize(N+2);
    for(int n = 2; n<=N; n++)
        cin>>A[n];
    //  nodes -> values of x; 0 denotes dead node
    //  edges -> 1->all; i->i-A[i]; i->i+A[i]
    g.resize(N+2);
    revg.resize(N+2);
    for(int i = 2; i<=N; i++)
    {
        g[1].push_back({i, i-1});
        int x = min(i+A[i], N+1);
        int y = max(i-A[i], 0LL);
        g[i].push_back({x, A[i]});
        g[i].push_back({y, -A[i]});
    }
    for(int i = 0; i<=N+1; i++)
        for(pair<int,int>p: g[i])
            revg[p.first].push_back({i, p.second});
    bfs(0, true);
    bfs(N+1, false);
    for(auto p: ans)
        cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<endl;
    // for(int i = 1; i<=N-1; i++)
        // cout<<ans[{1,i}]<<endl;
    return 0;
}