#include <bits/stdc++.h>

using namespace std;

#define int long long

int phi(int N)
{
	int ans = N;
	for(int i = 2; i*i<=N; i++)
	{
		if(N%i != 0)
			continue;
		while(N%i == 0)
			N/=i;
		ans -= ans/i;
	}
	if(N>1)
		ans -= ans/N;
	return ans;
}

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int A,M;
		cin>>A>>M;
		int g = __gcd(A, M);
		int ans = phi(M/g);
		cout<<ans<<endl;
	}
	return 0;
}

