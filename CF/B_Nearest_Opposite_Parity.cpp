#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int N;
    cin>>N;
    int A[N];
    for(int n = 0; n<N; n++)
        cin>>A[n];
    vector<vector<int>>g(N);
    vector<vector<int>>revg(N);
    for(int n = 0; n<N; n++)
    {
        if(n+A[n]<N)
        {
            g[n].push_back(n+A[n]);
            revg[n+A[n]].push_back(n);
        }
        if(n-A[n]>=0)
        {
            g[n].push_back(n-A[n]);
            revg[n-A[n]].push_back(n);
        }
    }
    vector<int>ans(N,-1);
    bool bad = true;
    queue<int>more;
    for(int u = 0; u<N; u++)
    {
        int p = 1 - (A[u]&1);
        for(int v: g[u])
        {
            if((A[v]&1) == p)
            {
                ans[u] = 1;
                bad = false;
                more.push(u);
            }
        }
    }
    if(!bad)
    {
        while(!more.empty())
        {
            int u = more.front();
            more.pop();
            for(int v: revg[u])
            {
                if(ans[v] == -1)
                {
                    ans[v] = ans[u]+1;
                    more.push(v);
                }
            }
        }
    }
    for(int n: ans)
        cout<<n<<" ";
    cout<<endl;
    return 0;
}