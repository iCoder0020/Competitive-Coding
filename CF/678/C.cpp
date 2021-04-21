#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main()
{
	int N,X,P;
	cin>>N>>X>>P;
	vector<int>fact(N+1,1);
	for(int n = 1; n<=N; n++)
		fact[n] = (n*fact[n-1])%MOD;
	int lo = 0, mid, hi = N;
	int big = N-X;
	int small = X-1;
	int ans = 1;
	while(lo<hi)
	{
		mid = (lo+hi)/2;
		// if(mid == P)
		// {
		// 	ans = (ans * fact[small+big])%MOD;
		// 	break;
		// }
		if(mid <= P)
		{
			if(mid != P)
			{
				ans = (ans * small)%MOD;
				small--;
			}
			lo = mid+1;
		}
		else
		{
			ans = (ans * big)%MOD;
			big--;
			hi = mid;
		}
	}
	if (lo>0 && lo-1 == P)
		ans = (ans * fact[small+big])%MOD;
	cout<<ans<<endl;
	return 0;
}