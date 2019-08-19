/*
ID: iCoder0020
PROG: Shortest Cycle
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;	
	cin>>N;
	vector<int>A;
	vector<int>arr(64, 0);
	vector<int>pow(64, 1);
	for(int n = 1; n<64; n++)
		pow[n] = 2*pow[n-1];
	int k = 0, temp;
	for(int n = 0; n<N; n++)
	{
		cin>>temp;
		if(temp == 0)
		{
			k++;
			continue;
		}
		A.push_back(temp);
		for(int i = 0; i<64; i++)
		{
			if(A.back() & pow[i])
				arr[i]++;
		}
	}
	N-=k;
	int m = *max_element(arr.begin(), arr.end());
	if(m <= 1)
		cout<<-1;
	else if(m >= 3)
		cout<<3;
	else
	{
		vector<vector<int>>g(N);
		for(int n = 0; n<N-1; n++)
		{
			for(int m = n+1; m<N; m++)
			{
				int x = A[n];
				int y = A[m];
				if((x&y) != 0)
				{
					g[n].push_back(m);
					g[m].push_back(n);
				}
			}
		}
		int ans = N+1;
		for(int n = 0; n<N; n++)
		{
			if(g[n].size() < 2)
				continue;
			queue<pair<int, set<int>>>Q;
			Q.push({n, set<int>{}});
			while(!Q.empty())
			{
				int u = Q.front().first;
				set<int> S = Q.front().second;
				Q.pop();
				if(S.find(u) == S.end())
				{
					S.insert(u);
					for(auto v: g[u])
					{
						if(S.find(v) == S.end() || v == n)
							Q.push({v, S});
					}
				}
				else
				{
					int sz = S.size();
					if(sz>2 && u == n)
					{
						ans = min(ans, sz);
						break;
					}
				}
			}
		}
		if(ans == N+1)
			ans = -1;
		cout<<ans;
	}
	cout<<endl;
	return 0;
}