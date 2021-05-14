#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout, depth;
vector<vector<int>> up;

void dfs(int v, int p, int d)
{
    tin[v] = ++timer;
    depth[v] = d;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (int u : adj[v])
    {
        if (u != p)
            dfs(u, v, d + 1);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i)
    {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int dist(int u, int v)
{
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

bool check(int d1, int d2)
{
    return (d1<=d2 && ((d1&1) == (d2&1)));
}

void preprocess(int root)
{
    tin.resize(n);
    tout.resize(n);
    depth.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root, 0);
}

int32_t main()
{
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    preprocess(0);
    int Q;
    cin >> Q;
    while (Q--)
    {
        int X, Y, A, B, K;
        cin >> X >> Y >> A >> B >> K;
        X--, Y--, A--, B--;
        int xy = 1;
        int ax = dist(A, X);
        int yb = dist(Y, B);
        int ay = dist(A, Y);
        int xb = dist(X, B);
        int ab = dist(A, B);
        if(check(ab, K) || check(ax+xy+yb, K) || check(ay+xy+xb, K))
            cout<<"YES";
        else    
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}
