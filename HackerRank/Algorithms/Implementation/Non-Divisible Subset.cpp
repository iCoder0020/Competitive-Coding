/*
ID: iCoder0020
PROG: Non-Divisible Subset
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
	return (a>b)?a:b;
}

int main()
{
	int N,K;
	cin>>N>>K;
	int A[N];
	int B[K]={0};
	int ans;
	for(int i = 0; i<N; i++)
	{
		cin>>A[i];
		B[A[i]%K]++;
	}
	if(B[0] > 1)
	{
		B[0] = 1;
	}
	ans = B[0];
	if(K%2 == 0)
	{
		if(B[K/2] > 1)
		{
			B[K/2] = 1;
		}
		ans+=B[K/2];
	}
	for(int i = 1; i<(K+1)/2; i++)
	{
		ans+=max(B[i], B[K-i]);
	}
	cout<<ans<<"\n";
	return 0;
}
