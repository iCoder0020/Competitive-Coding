#include <bits/stdc++.h>

using namespace std;

#define MAX2 19
#define int long long

struct node
{
	int depth;
	vector<int>lift;
	vector<int>adj;
	node()
	{
		depth = -1;
		lift.resize(MAX2, 0);
	}
};

vector<node>g;
vector<int>vis;
vector<int>pow2(MAX2, 1);

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void input()
{
	int N;
	cin>>N;
	g.resize(N+1);
	vis.resize(N+1, false);
	for(int n = 0; n<N-1; n++)
	{
		int u,v;
		cin>>u>>v;
		g[u].adj.push_back(v);
		g[v].adj.push_back(u);
	}
}

void depth_and_parent(int u, int parent)
{
	if(vis[u])
		return;
	vis[u] = true;
	g[u].depth = g[parent].depth+1;
	g[u].lift[0] = parent;
	for(auto it: g[u].adj)
	{
		if(vis[it])
			continue;
		depth_and_parent(it,u);
	}
}

void fill_aux()
{
	for(int n = 1; n<MAX2; n++)
		pow2[n] = 2*pow2[n-1];
	for(int p = 1; p<MAX2; p++)
	{
		for(int n = 1; n<g.size(); n++)
		{
			if((1<<p)<=g[n].depth)
				g[n].lift[p] = g[g[n].lift[p-1]].lift[p-1];
		}
	}
}

int go_up(int u, int h)
{
	for(int i = MAX2; i>=0; i--)
	{
		int p = (1<<i);
		if(h>=p)
		{
			h-=p;
			u = g[u].lift[i];
		}
	}
	return u;
}

int lca(int a, int b)
{
	if(g[a].depth!=g[b].depth)
		a = go_up(a,g[a].depth-g[b].depth);
	if(a == b)
		return a;
	int lo = 1, mid, hi = max(g[a].depth, g[b].depth);
	while(lo<hi)
	{
		mid = lo+(hi-lo)/2;
		if(go_up(a,mid) == go_up(b,mid))
			hi = mid;
		else
			lo = mid+1;
	}
	return go_up(a,lo);
}

int query(int a, int b, int c)
{
	int l;
	if(g[a].depth >= g[b].depth)
		l = lca(a,b);
	else
		l = lca(b,a);
	if(c>=g[a].depth+g[b].depth-2*g[l].depth)
		return b;
	if(g[a].depth - g[l].depth >= c)
		return go_up(a,c);
	return go_up(b, g[b].depth-c+g[a].depth-2*g[l].depth);
}

void answer()
{
	int Q;
	cin>>Q;
	while(Q--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		cout<<query(a,b,c)<<endl;
	}
}

int32_t main()
{	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	input();
	depth_and_parent(1, 0);
	fill_aux();
	answer();
	return 0;
}