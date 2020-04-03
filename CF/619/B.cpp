#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1000000000

bool bs(vector<int>B, int K)
{
	if(B.size() == 0)
		return true;
	else
	{
		int x = (B[B.size()-1]-B[0])/2;
		for(auto it: B)
			if(it-x>K)
				return false;
	}
	return true;
}

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int A[N];
		vector<int>B;
		for(int n = 0; n<N; n++)
			cin>>A[n];
		for(int n = 0; n<N; n++)
		{
			if(A[n] != -1)
			{
				if(((n-1)>=0 && A[n-1] == -1) || ((n+1)<N && A[n+1] == -1))
					B.push_back(A[n]);
			}
		}
		sort(B.begin(), B.end());
		int lo = 0, hi = INF, mid;
		for(int n = 0; n<N-1; n++)
		{
			if(A[n]!=-1 && A[n+1]!=-1)
				lo = max(lo, abs(A[n+1]-A[n]));
		}
		while(lo<hi)
		{
			mid = lo + (hi-lo)/2;
			if(bs(B, mid))
				hi = mid;
			else
				lo = mid+1;
		}
		int m = 0;
		for(int n = 0; n<N; n++)
		{
			if(A[n] == -1)
				A[n] = lo;
		}
		for(int n = 0; n<N-1; n++)
			m = max(abs(A[n]-A[n+1]), m);
		cout<<m<<" "<<lo<<endl;
	}
	return 0;
}
