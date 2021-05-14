#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>

int32_t main()
{
	int N;
	cin>>N;
	vector<vector<int>> ans(N, vector<int>(N, -1));
	int cnt[N+1];
	for(int n = 0; n<N; n++)
	{
		cin>>ans[n][n];
		cnt[ans[n][n]] = 1;
	}

	vector<set<pii>> poss(N+1);
	for(int i = 0; i<N; i++)
	{
		int x = ans[i][i];
		if(cnt[x] < x)
		{
			if(i>0 && ans[i][i-1] == -1)
				poss[x].insert({i, i-1});
			if(i<N-1 && ans[i+1][i] == -1)
				poss[x].insert({i+1, i});
		}
	}
	
	priority_queue<pii, vector<pii>, greater<pii>> min_heap;

	for(int i = 1; i<=N; i++)
		if(poss[i].size())
			min_heap.push({poss[i].size(), i});

	while(!min_heap.empty())
	{

		// for(int i = 1; i<=N; i++)
		// {
		// 	cout<<"Possible cells for "<<i<<": "<<endl;
		// 	for(pii cell: poss[i])
		// 		cout<<cell.first<<", "<<cell.second<<endl;
		// }

		pii top = min_heap.top();
		min_heap.pop();

		int val = top.second;
		pii pos = *(poss[val].begin());
		int x = pos.first;
		int y = pos.second;

		if(poss[val].size() != top.first)
		{
			min_heap.push({poss[val].size(), val});
			continue;
		}

		cout<<"!!Setting ("<<x<<", "<<y<<") to "<<val<<endl;

		// 	set (x,y) = val
		ans[x][y] = val;
		cnt[val]++;

		// 	remove (x,y) as a possible cell from all regions
		for(int i = 1; i<=N; i++)
			if(poss[i].find(pos) != poss[i].end())
				poss[i].erase(pos);

		//	add next possible cells for the current region if count not reached
		if(cnt[val] < val)
		{
			// cout<<"val: "<<val<<", cnt: "<<cnt[val]<<endl;
			if(x>0 && ans[x-1][y] == -1)
				poss[val].insert({x-1, y});
			if(x<N-1 && ans[x+1][y] == -1)
				poss[val].insert({x+1, y});
			if(y>0 && ans[x][y-1] == -1)
				poss[val].insert({x, y-1});
			if(y<x-1 && ans[x][y+1] == -1)
				poss[val].insert({x, y+1});
			min_heap.push({poss[val].size(), val});
		}
	}

	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<=i; j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}