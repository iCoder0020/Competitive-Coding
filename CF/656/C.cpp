#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e12

bool bs(vector<int>&A, int k)
{
	int l = k;
	int r = A.size()-1;
	int prev = -1;
	while(l<=r)
	{
		if(A[l] <= A[r])
		{
			if(A[l]<prev)
				return false;
			prev = A[l];
			l++;
		}
		else
		{
			if(A[r]<prev)
				return false;
			prev = A[r];
			r--;
		}
	}
	return true;
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		int lo=0,hi=N-1,mid;
		while(lo<hi)
		{
			mid = lo + (hi-lo)/2;
			if(bs(A,mid))
				hi = mid;
			else
				lo = mid+1;
		}
		cout<<lo<<endl;
	}
	return 0;
}