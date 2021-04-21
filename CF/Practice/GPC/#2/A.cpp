#include <bits/stdc++.h>

using namespace std;

#define int long long

bool mysort(pair<int,int>&A, pair<int,int>&B)
{
	if(A.second == B.second)
		return A.first < B.first;
	return A.second > B.second;
}

int32_t main()
{
	int N,K;
	cin>>N>>K;
	int A[N];
	int tyre = 0, ans = 0, curr = 0;
	bool first = true;
	vector<pair<int,int>>seg;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(A[n]<0)
		{
			if(tyre == 0)
			{
				tyre = 1;
				ans++;
				if(!first)
					seg.push_back({curr, 2});
				first = false;
				curr = 0;
			}
			K--;
		}
		else
		{
			if(tyre == 1)
			{
				tyre = 0;
				ans++;
			}
			curr++;
		}
	}
	if(curr>0 && !first)
		seg.push_back({curr, 1});
	if(K<0)
		cout<<-1;
	else
	{
		sort(seg.begin(), seg.end(), mysort);
		for(auto it: seg)
		{
			if(K>=it.first)
			{
				K-=it.first;
				ans-=it.second;
			}
		}
		cout<<ans;
	}
	cout<<endl;
	return 0;
}
