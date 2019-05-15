/*
ID: iCoder0020
PROG: Boredom
LANG: C++                  
*/

#include<bits/stdc++.h>

using namespace std;

#define num first
#define cnt second
#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	int count[100001] = {0};
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		count[A[n]]++;
	}
	sort(A, A+N);
	pair<int,int> a[N];
	int m = 0;
	for(int n = 0; n<N; n++)
	{
		a[m].first = A[n];
		a[m].second = count[A[n]];
		while(n+1 < N && A[n] == A[n+1])
			n++;
		m++;
	}
	int dp[m];
	dp[0] = a[0].num*a[0].cnt;
	if(a[1].num == a[0].num+1)
		dp[1] = max(a[1].num*a[1].cnt, dp[0]);
	else
		dp[1] = a[1].num*a[1].cnt + dp[0];

	for(int i = 2; i<m; i++)
	{
		if(a[i].num == a[i-1].num+1)
			dp[i] = max(a[i].num*a[i].cnt+dp[i-2], dp[i-1]);
		else
			dp[i] = a[i].num*a[i].cnt + dp[i-1];
	}

	cout<<dp[m-1]<<endl;
	return 0;
}