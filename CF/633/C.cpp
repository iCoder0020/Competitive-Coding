#include <bits/stdc++.h>

using namespace std;

#define int long long


int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		int cnt, maxcnt = 0;
		for(int n = 0; n<N-1; n++)
		{
			if(A[n+1]<A[n])
			{
				int d = A[n]-A[n+1];
				for(int i = 0; i<63; i++)
				{
					if(d & (1LL<<i))
						maxcnt = max(maxcnt,i+1);
				}
				A[n+1] = A[n];
			}
		}	
		cout<<maxcnt<<endl;
	}
	return 0;
}
