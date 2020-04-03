#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;

		int N = S.length();
		int sum = 0;

		for(int n = 0; n<N-1; n++)
			if(S[n] == S[n+1])
				sum++;

		int ans = (N*(N+1))/2;
		ans *= sum;
		int l, r;

		for(int n = 0; n<N; n++)
		{
			if(n == 0)
				l = 0;
			else if(S[n] == S[n-1])
				l = -1;
			else
				l = 1;

			if(n == N-1)
				r = 0;
			else if(S[n] == S[n+1])
				r = -1;
			else
				r = 1;

			ans += l*(N-n) + r*(n+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}