/*
ID: iCoder0020
PROG: Kruskal (MST): Really Special Subtree
LANG: C++                  
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int>rep;

int set_find(int x)
{
    while(rep[x] != x)
    {
        rep[x] = rep[rep[x]];
        x = rep[x];
    }
    return x;
}

void set_union(int x, int y)
{
    int a = set_find(x);
    int b = set_find(y);

    if(a!=b)
        rep[a] = b;
}


bool mysort(pair<pair<int,int>,int> &A, pair<pair<int,int>,int> &B)
{
    return A.second<B.second;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int N,M;
    cin>>N>>M;
    vector<pair<pair<int,int>,int>> edges;
    map<pair<int,int>,int>MAP;
    rep.resize(N+1);
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

        edges.push_back({{u,v},w});
    }

    for(int n = 0; n<=N; n++)
        rep[n] = n;

    sort(edges.begin(), edges.end(), mysort);

    int sum = 0;

    for(auto it: edges)
    {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;

        if(set_find(u) != set_find(v))
        {
            sum += w;
            set_union(u,v);
        }
    }

    cout<<sum<<endl;

    return 0;
}