/*
ID: iCoder0020
PROG: Fence
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,K;
	cin>>N>>K;
	int height[N];
	int sum = 0;
	int ans = INT_MAX;
	int index = -1;
	for(int n = 0; n<N; n++)
	{
		cin>>height[n];
		if(n<K)
		{
			sum += height[n];
		}
	}
	ans = min(ans, sum);
	index = 1;
	for(int n = K; n<N; n++)
	{
		sum += height[n] - height[n-K];
		if(ans > sum)
		{
			ans = sum;
			index = n+2-K;
		}
	}
	cout<<index<<endl;
	return 0;
}