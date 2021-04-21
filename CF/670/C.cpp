#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>>g;
vector<int>subtree_size;
vector<int>lcomp;
vector<bool>vis;

void fill_ss(int root)
{
	int sum = 0;
	vis[root] = true;
	for(int v: g[root])
	{
		if(vis[v])
			continue;
		fill_ss(v);
		sum += subtree_size[v];
	}
	subtree_size[root] += sum;
}

void find_centroid(int root)
{
	vis[root] = true;
	int x = subtree_size[1]-subtree_size[root];
	for(int v: g[root])
	{
		if(vis[v])
			continue;
		x = max(x, subtree_size[v]);
	}
	lcomp[root] = x;
	for(int v: g[root])
	{
		if(vis[v])
			continue;
		find_centroid(v);
	}
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		g.clear();
		g.resize(N+1);
		lcomp.assign(N+1,1);
		subtree_size.assign(N+1,1);
		vis.assign(N+1,false);
		for(int n = 0; n<N-1; n++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		set<int>leaves;
		for(int n = 1; n<=N; n++)
			if(g[n].size() == 1)
				leaves.insert(n);
		fill_ss(1);
		vis.assign(N+1, false);
		find_centroid(1);
		int minm = *min_element(lcomp.begin()+1, lcomp.end());
		vector<int>nodes;
		for(int n = 1; n<=N; n++)
			if(lcomp[n] == minm)
				nodes.push_back(n);
		if(nodes.size()==1)
		{
			for(int i = 0; i<2; i++)
				cout<<nodes[0]<<" "<<g[nodes[0]][0]<<endl;
		}
		else
		{
			bool found = false;
			for(int v: g[nodes[0]])
			{
				if(v!=nodes[1])
				{
					found = true;
					cout<<v<<" "<<nodes[0]<<endl;
					cout<<v<<" "<<nodes[1]<<endl;
					break;
				}
			}
			if(!found)
			{
				for(int v: g[nodes[1]])
				{
					if(v!=nodes[0])
					{
						found = true;
						cout<<v<<" "<<nodes[0]<<endl;
						cout<<v<<" "<<nodes[1]<<endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}