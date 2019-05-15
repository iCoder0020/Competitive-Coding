/*
ID: iCoder0020
PROG: Dijkstra?
LANG: C++                  
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int N,M;
    cin>>N>>M;
    vector<pair<int,int>>adj[N+1];
    map<pair<int,int>, int> MAP;
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

    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }
    vector<int>dis(N+1, INT_MAX);
    vector<bool>vis(N+1,false);
    vector<int>prev(N+1, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 1});
    dis[1] = 0;

    while(!pq.empty())
    {
        int u  = pq.top().second;
        pq.pop();
        vis[u] = true;
        for(auto it: adj[u])
        {
            int v = it.first;
            int w = it.second;
            
            if(vis[v] == false && dis[v] > dis[u]+w)
            {
                dis[v] = dis[u] + w;
                prev[v] = u;
                pq.push({dis[v], v});
            }
        }
    }

    bool possible = true;

    stack<int>S;

    int v = N;

    while(v != 1)
    {
    	S.push(v);
    	v = prev[v];
    	if(v == -1)
    	{
    		possible = false;
    		break;
    	}
    	if(v == 1)
    		S.push(1);
    }
    
    if(possible)
    {
	    while(!S.empty())
	    {
	    	cout<<S.top()<<" ";
	    	S.pop();
	    }	
	}
	else
	{
		cout<<-1;
	}
	cout<<endl;


    return 0;
}