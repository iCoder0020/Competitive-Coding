#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int K;
	cin>>K;
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		if(K == 1)
		{
			int A[N]={0};
			int sum = (N*(N+1))/2;
			int S = 0;
			for(int n = N-1; n>=0; n--)
			{
				if(S+n+1 <= sum/2)
				{
					S+=n+1;
					A[n] = 1;
				}
			}
			cout<<abs(S-(sum-S))<<endl;
			for(int n = 0; n<N; n++)
				cout<<A[n];
			cout<<endl;
		}
		else
		{
			int A[N]={0};
			int sum = (N*(N+1)*(2*N+1))/6;
			int S = 0;
			for(int n = N-1; n>=0; n--)
			{
				if(S+(n+1)*(n+1) <= sum/2)
				{
					S+=(n+1)*(n+1);
					A[n] = 1;
				}
			}
			cout<<abs(S-(sum-S))<<endl;
			for(int n = 0; n<N; n++)
				cout<<A[n];
			cout<<endl;

		}
	}
	return 0;
}