/*
ID: iCoder0020
PROG: Breadth First Search: Shortest Reach
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

#define N_MAX 1001

vector<int> adj_list [N_MAX];
vector<int> visited;
vector<int> dist;

void bfs(int s)
{
    queue<pair<int,int>>Q;
    int x = 0;
    Q.push({s, x});

    while(!Q.empty())
    {
        pair<int,int> top = Q.front();
        if(!visited[top.first])
        {
            for(auto it: adj_list[top.first])
                Q.push({it, top.second+1});
            visited[top.first] = true;
            dist[top.first] = top.second;
        }
        Q.pop();
    }
}

int32_t main()
{
    int T;
    cin>>T;
    for(int t = 0; t<T; t++)
    {
        int N,M;
        cin>>N>>M;
        for(int n = 1; n<=N; n++)
            adj_list[n].clear();
        visited.clear();
        dist.clear();
        visited.resize(N+1, false);
        dist.resize(N+1, -1);
        int u,v;
        for(int m = 0; m<M; m++)
        {
            cin>>u>>v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        int s;
        cin>>s;
        bfs(s);
        for(int n = 1; n<=N; n++)
        {
            if(n!=s)
            {
                if(dist[n] == -1)
                    cout<<-1<<" ";
                else
                    cout<<6*dist[n]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
