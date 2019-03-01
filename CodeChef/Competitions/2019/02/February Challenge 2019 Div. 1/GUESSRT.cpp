/*
ID: ishan_sang
PROG: GUESSRT
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

li MOD = 1000000007;

li power(li a, li b)
{
	if(b == 0)
	{
		return 1;
	}
	else
	{
		li c = power(a, b/2) % MOD;
		if(b%2 == 0)
		{
			return (c*c)%MOD;
		}
		else
		{
			return (a*((c*c)%MOD))%MOD;
		}
	}
}

li inv_mod(li a)
{
	return power(a, MOD-2);
}

int main()
{
	int T;
	cin>>T;
	//cout<<(4*inv_mod(5))%MOD<<endl;
	while(T--)
	{
		li N,K,M;
		cin>>N>>K>>M;
		li num = 1;
		li den = 1;
		li prob;
		if(N == 1)
		{
			prob = 1;
		}
		else
		{
			if(M%2 == 0)
			{
				li a = power(N,M/2);
				li b = power(N-1,M/2);
				//cout<<a<<" "<<b<<endl;
				num = (a-b+MOD)%MOD;
				den = a;

				num = ((N+K-1)*num + den)%MOD;
				den = (a*(N+K))%MOD;
			}
			else
			{
				li a = power(N,(M+1)/2);
				li b = power(N-1,(M+1)/2);
				//cout<<a<<" "<<b<<endl;
				num = (a-b+MOD)%MOD;
				den = a;
			}
		}
		prob = (num*inv_mod(den))%MOD;
		cout<<prob<<endl;
	}
	return 0;
}