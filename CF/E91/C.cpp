#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check(vector<int>&A, int K, int X)
{
	int N = A.size();
	int cnt = 0;
	for(int n = 0; n<N; n++)
	{
		if(A[n]>=X)
			cnt++;
		else
		{
			int start = n; 
			while(n<N)
			{
				if(A[n]*(n-start+1)>=X)
				{
					cnt++;
					break;
				}
				n++;
			}
		}
	}
	return cnt>=K;
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,X;
		cin>>N>>X;
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		sort(A.begin(), A.end(), greater<int>());
		int lo=0, hi=N, mid;
		while(lo<hi)
		{
			mid = lo+(hi-lo+1)/2;
			if(check(A, mid, X))
				lo = mid;
			else
				hi = mid-1;
		}
		cout<<lo<<endl;
	}
	return 0;
}
