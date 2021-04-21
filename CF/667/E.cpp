#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,K;
		cin>>N>>K;
		map<int,int>Xmap;
		for(int n = 0; n<N; n++)
		{
			int x,y;
			cin>>x>>y;
			Xmap[x]++;
		}
		vector<pair<int,int>>v;
		for(pair<int,int>p: Xmap)
			v.push_back({p.first,p.second});
		int M = v.size();
		int cnt = ;
		int max_cnt = 0;
		int i = 0, j = 0, temp;
		temp = i;
		while(temp<M)
		{
			
		}
		cout<<max_cnt<<endl;
	}
	return 0;
}
