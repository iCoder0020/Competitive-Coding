#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;
vector<int>A;
vector<vector<int>>g;
vector<int>subtreeSum;
vector<int>ans;
int fullSum;

void fillSubtreeSum(int u, int p)
{
    int sum = A[u];
    for(int v: g[u])
    {
        if(v ==p )
            continue;
        fillSubtreeSum(v, u);
        sum += subtreeSum[v]; 
    }
    subtreeSum[u] = sum;
}

int rootAns(int u, int p, int d)
{
    int sum = 0;
    for(int v: g[u])
    {
        if(v == p)
            continue;
        sum += rootAns(v, u, d+1);
    }
    return A[u]*d + sum;
}

void getAns(int u, int p)
{
    if(u != p)
        ans[u] = ans[p] + fullSum - 2*subtreeSum[u];
    else
        ans[u] = rootAns(u, p, 0);
    for(int v: g[u])
    {
        if(v == p)
            continue;
        getAns(v, u);
    }
}

int32_t main()
{
    cin>>N;
    A.resize(N+1);
    g.resize(N+1);
    subtreeSum.resize(N+1);
    ans.resize(N+1, 0);
    fullSum = 0;
    for(int n = 1; n<=N; n++)
    {
        cin>>A[n];
        fullSum += A[n];
    }
    for(int n = 0; n<N-1; n++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    fillSubtreeSum(1, 1);
    getAns(1, 1);
    cout<<*max_element(ans.begin(), ans.end())<<endl;
    return 0;
}