/*
ID: icoder_0020
PROG: Friendless Dr. Sheldon Cooper
LANG: C++                  
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e16
#define pii pair<int,int>

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int T;
    cin>>T;
    while(T--)
    {
        int A,B;
        cin>>A>>B;
        vector<int>adj[A+1];
        vector<int>dis(A+1, INF);
        vector<bool>vis(A+1, false);
        for(int i = 0; i<B; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int total = -1;
        dis[1] = 0;
        pq.push({0,1});
        while(!pq.empty())
        {
            pii temp = pq.top();
            pq.pop();
            total++;
            int u = temp.second;
            vis[u] = true;
            for(auto v: adj[u])
            {
                if(!vis[v] && dis[v] > dis[u]+1)
                {
                    dis[v] = dis[u] + 1;
                    pq.push({dis[v], v});
                }
            }
        }
        cout<<total<<endl;
    }
    return 0;
}