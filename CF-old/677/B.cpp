#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		int ans = 0;
		int next[N];
		next[N-1] = N;
		for(int n = N-2; n>=0; n--)
		{
			if(A[n+1] == 1)
				next[n] = n+1;
			else
				next[n] = next[n+1];
		}
		for(int n = 0; n<N; n++)
		{
			if(A[n] == 1)
			{
				if(next[n] == N)
					continue;
				// cout<<n<<" "<<next[n]<<endl;
				ans += (next[n]-n)-1;
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
}
