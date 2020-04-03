#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N, X;
		cin>>N>>X;
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		sort(A, A+N);
		int i = lower_bound(A, A+N, X)-A;
		if(i == N)
			i = N-1;
		int ans;
		if(A[i] > X)
			ans = 2;
		else if(A[i] == X)
			ans = 1;
		else
		{
			ans = X/A[i];
			if(X%A[i] != 0)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
