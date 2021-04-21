#include <bits/stdc++.h>

using namespace std;

#define int long long

int N,C;
vector<int>A;
vector<int>B;

#define INF 1e18

int bs(int X)
{
	int days = 0;
	for(int n = 0; n<N; n++)
	{
		if(A[n]>0 && X/B[n]>=C)
			return C+1;
		days += (X/B[n])*A[n] + ((X%B[n])*A[n])/B[n]+1;
		if(days>C || days<0)
			return C+1;
	}
	return days;
}

int32_t main()
{
	cin>>N>>C;
	A.resize(N,0);
	B.resize(N,0);
	for(int n = 0; n<N; n++)
		cin>>A[n]>>B[n];
	int lo = 1, hi = INF, mid1, mid2;
	while(lo<hi)
	{
		mid1 = lo+(hi-lo)/2;
		if(bs(mid1) < C)
			lo = mid1+1;
		else 
			hi = mid1; 
	}
	mid1 = lo;
	lo = 1, hi = INF;
	while(lo<hi)
	{
		mid2 = lo+(hi-lo+1)/2;
		if(bs(mid2) > C)
			hi = mid2-1;
		else
			lo = mid2;
	}
	mid2 = lo;
	if(mid1 == mid2 && mid1 == lo)
	{
		if(bs(lo) == C)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
	else if(mid2 == INF)
		cout<<-1<<endl;
	else
		cout<<mid2-mid1+1<<endl;
	return 0;
}
