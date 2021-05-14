#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e12

bool mysort(pair<int,int>&A, pair<int,int>&B)
{
	if(A.second == B.second)
		return A.first>B.first;
	return A.second>B.second;
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N, M;
		cin>>N>>M;
		vector<pair<int,int>>v(M);
		for(int m = 0; m<M; m++)
			cin>>v[m].first;
		for(int m = 0; m<M; m++)
			cin>>v[m].second;
		sort(v.begin(), v.end(), mysort);
		int maxpack = v[0].first + v[0].second;
		int m = 0;
		while(m != maxpack)
		{
			
		}
	}
	return 0;
}