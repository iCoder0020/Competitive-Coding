/*
ID: iCoder0020
PROG: Array Splitting
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N,K;
	cin>>N>>K;
	int A[N];
	pair<int,int> pre[N];
	for(int n = 0; n<N; n++)
		cin>>A[n];
	pre[0] = {0, 0};
	for(int n = 1; n<N; n++)
		pre[n] = {A[n] - A[n-1], n};
	sort(pre, pre+N, greater<pair<int,int>>());
	vector<int> div;
	for(int i = 0; i<K-1; i++)
		div.push_back(pre[i].second);
	sort(div.begin(), div.end());
	div.push_back(N);
	int idx = 0;
	int ans = 0;
	for(auto it: div)
	{
		ans += A[it-1] - A[idx];
		idx = it;
	}
	cout<<ans<<endl;
	return 0;
}