#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int power(int a, int b)
{
	if(a == 1 || b == 0)
		return 1;
	int c = power(a,b/2);
	int d = (c*c)%MOD;
	if(b&1)
		return (a*d)%MOD;
	return d;
}

int invmod(int a)
{
	return power(a,MOD-2);
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int C[N];
		int maxm = 0, maxcnt = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>C[n];
			if(C[n]>maxm)
				maxm = C[n], maxcnt = 0;
			if(C[n] == maxm)
				maxcnt++;
		}
		int winner = 0;
		int p = 1;
		int d1 = (maxcnt+2)/2-1;
		int ncr = 1;
		for(int i = 1; i<=maxcnt; i++)
		{
			p = (p*i)%MOD;
			ncr = (ncr*(maxcnt-i+1))%MOD;
			ncr = (ncr*(invmod(i)))%MOD;
			if(i>=(maxcnt+2)/2)
				winner = (winner + (power(2, N-maxcnt)*ncr))%MOD;
			// cout<<maxcnt<<" "<<i<<" "<<ncr<<endl;
		}
		int ans = (2*winner)%MOD;
		cout<<ans<<endl;
	}
	return 0;
}