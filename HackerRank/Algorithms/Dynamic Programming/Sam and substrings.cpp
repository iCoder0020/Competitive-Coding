/*
ID: iCoder0020
PROG: Sam and substrings
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int lli;

#define MOD 1000000007

using namespace std;

int main()
{
	string N;	
	cin>>N;
	lli dp[N.length()];
	lli ans;
	dp[0] = ((int)(N[0])-48);
	ans = dp[0];
	for(int n = 1; n<N.length(); n++)
	{
		dp[n] = ((10*(dp[n-1]%MOD))%MOD + ((n+1)*((int)(N[n])-48))%MOD)%MOD;
		ans = (ans%MOD + dp[n]%MOD)%MOD;
	}
	cout<<ans<<"\n";
	return 0;
}