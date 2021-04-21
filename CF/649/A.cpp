#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,X;
		cin>>N>>X;
		int A[N];
		bool y = false;
		int sum = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n]%X != 0)
				y = true;
			sum += A[n];
		}
		if(sum%X != 0)
			cout<<N<<endl;
		else if(!y)
			cout<<-1<<endl;
		else
		{
			int prefix[N], suffix[N];
			prefix[0] = A[0];
			suffix[N-1] = A[N-1];
			int ans = 0;
			for(int n = 1; n<N; n++)
				prefix[n] = prefix[n-1]+A[n];
			for(int n = N-2; n>=0; n--)
				suffix[n] = suffix[n+1]+A[n];
			for(int n = 0; n<N; n++)
			{
				if(prefix[n]%X != 0)
					ans = max(ans, N-n-1);
				if(suffix[n]%X != 0)
					ans = max(ans, n);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
