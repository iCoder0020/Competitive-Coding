/*
ID: iCoder0020
PROG: Cover it!
LANG: C++                  
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

int N,M;
vector<vector<int>>g;
vector<bool>vis;
vector<int>ans;
set<int>S;

bool my_sort(pair<int,vector<int>> &A, pair<int,vector<int>> &B)
{
    return A.second.size() > B.second.size();
}

void f(int s, int d)
{
    if(vis[s])
        return;
    vector<int> v = g[s];
    vis[s] = true;
    if(d == 0)
    {
        ans.push_back(s);
        S.erase(s);
    }
    for(auto it: v)
        f(it, d^1);
}

int32_t main()
{
    int Q;
    cin>>Q;
    while(Q--)
    {
        cin>>N>>M;
        g.clear();
        g.resize(N+1);
        vis.clear();
        vis.resize(N+1, false);
        ans.clear();
        S.clear();
        for(int n = 1; n<=N; n++)
            S.insert(n);
        for(int m = 0; m<M; m++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        f(1, 0);
        if(ans.size() > N/2)
        {
            cout<<S.size()<<endl;
            for(auto it: S)
                cout<<it<<" ";
            cout<<endl;
        }
        else
        {
            cout<<ans.size()<<endl;
            for(auto it: ans)
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0; 
}