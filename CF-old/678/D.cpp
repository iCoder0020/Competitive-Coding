#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<set<int>>g;
vector<int>people;
vector<set<int>>rev_g;

void root(int u)
{
	for(int v: rev_g[u])
	{
		g[u].insert(v);
		g[v].erase(u);
	}
	for(int v: g[u])
		root(v);
}

vector<int> dfs(int root)
{
	vector<int>ans(3, 0);
	int num = g[root].size();
	if(num == 0)
	{
		ans = {people[root], 1, people[root]};
		return ans;
	}
	for(int v: g[root])
	{
		vector<int>p = dfs(v);
		ans[0] = max(ans[0], p[0]);
		ans[1] += p[1];
		ans[2] += p[2];
	}
	ans[2] += people[root];
	ans[0] = max(ans[0], (ans[2] + ans[1]-1)/ans[1]);
	// cout<<root<<" "<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
	return ans;
}

int32_t main()
{
	int N;
	cin>>N;
	g.resize(N+1);
	rev_g.resize(N+1);
	people.resize(N+1, 0);
	for(int n = 2; n<=N; n++)
	{
		int v;
		cin>>v;
		g[n].insert(v);
		rev_g[v].insert(n);
	}
	int total = 0;
	for(int n = 1; n<=N; n++)
	{
		cin>>people[n];
		total += people[n];
	}
	root(1);
	cout<<dfs(1)[0]<<endl;
	return 0;
}