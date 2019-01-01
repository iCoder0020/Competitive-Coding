/*
ID: iCoder0020
PROG: New Year and the Permutation Concatenation
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

#define MOD 998244353

using namespace std;

int main()
{
	li N;
	cin>>N;
	li fact[N+1];
	fact[0] = 1;
	for(int n = 1; n<=N; n++)
	{
		fact[n] = (n*fact[n-1])%MOD;
	}
	li dp[N+1];
	dp[1] = 1;
	for(int n = 2; n<=N; n++)
	{
		dp[n] = ((n*(dp[n-1]))%MOD + fact[n] - n)%MOD;
	}
	cout<<dp[N]<<endl;
	return 0;
}