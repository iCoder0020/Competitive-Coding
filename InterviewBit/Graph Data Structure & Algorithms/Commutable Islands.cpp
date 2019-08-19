/*
ID: ishan-sang
PROG: Commutable Islands
LANG: C++                  
*/

int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<vector<pair<int,int>>>adj_list(A+1);
    for(auto it: B)
    {
        adj_list[it[0]].push_back({it[1], it[2]});
        adj_list[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
    vector<bool>vis(A+1, false);
    pq.push({0, {1,1}});
    int ans = 0;
    while(!pq.empty())
    {
        int w = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        
        // cout<<u<<" "<<v<<" "<<w<<endl; 
        pq.pop();
        if(!vis[v])
        {
            ans+=w;
            vis[v] = true;
            for(auto it: adj_list[v])
            {
                if(!vis[it.first])
                    pq.push({it.second, {v, it.first}});
            }
        }
    }
    return ans;
}
