#include <bits/stdc++.h>

using namespace std;

#define int long long

void query(int l, int r)
{
	cout<<"? "<<l<<" "<<r<<endl;
	fflush(stdout);
}

void answer(int x)
{
	cout<<"! "<<x<<endl;
	fflush(stdout);
}

int32_t main()
{
	int N,T;
	cin>>N>>T;
	int K;
	cin>>K;
	int lo = 1;
	int hi = N;
	int mid;
	int sum;
	while(lo<hi)
	{
		mid = (lo+hi)/2;
		query(1, mid);
		cin>>sum;
		if(sum > mid-K)
			lo = mid+1;
		else
			hi = mid;
	}
	answer(lo);
	return 0;
}
