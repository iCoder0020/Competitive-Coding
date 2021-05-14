#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,X;
		cin>>N>>X;
		vector<vector<int>>g(N+1);
		vector<int>deg(N+1,0);
		for(int i = 0; i<N-1; i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			deg[u]++;
			deg[v]++;
		}
		if(deg[X] <= 1)
		{
			cout<<"Ayush"<<endl;
			continue;
		}
		else
		{
			if(N&1)
				cout<<"Ashish";
			else
				cout<<"Ayush";
			cout<<endl;
		}
	}
	return 0;
}
