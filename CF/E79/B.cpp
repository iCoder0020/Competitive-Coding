#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,S;
		cin>>N>>S;
		int A[N];
		int prefix[N];
		int maxm_index[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(n == 0)
			{
				prefix[n] = A[n];
				maxm_index[n] = 0;
			}
			else
			{
				prefix[n] = A[n] + prefix[n-1];
				if(A[n] > A[maxm_index[n-1]])
					maxm_index[n] = n;
				else
					maxm_index[n] = maxm_index[n-1];
			}
		}
		int ans = 0;
		for(int n = 0; n<N; n++)
		{
			if(prefix[n] > S)
			{
				if(prefix[n] - A[maxm_index[n]] <= S)
					ans = maxm_index[n]+1;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}

