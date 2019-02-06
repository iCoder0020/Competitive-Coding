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
	while(T--)
	{
		li N,K,M;
		cin>>N>>K>>M;
		li num;
		li den;
		li prob = 0;
		li prev_num = 0;
		li prev_den = 1;
		while(M > 0)
		{
			if(M == 1)
			{
				num = (prev_den - prev_num + MOD)%MOD;
				den = (prev_den * N)%MOD;
				//cout<<num<<"/"<<den<<endl;
				prob = (prob + ((num*inv_mod(den))%MOD))%MOD;
				break;
			}
			else
			{
				num = (prev_den - prev_num + MOD)%MOD;
				den = (prev_den * N)%MOD;
				prob = (prob + ((num*inv_mod(den))%MOD))%MOD;
				//cout<<num<<"/"<<den<<endl;
				prev_num = num;
				prev_den = den;
				if(M%2 == 0)
				{
					num = (prev_den - prev_num + MOD)%MOD;
					den = (prev_den * (N+K))%MOD;
					prob = (prob + ((num*inv_mod(den))%MOD))%MOD;
					//cout<<num<<"/"<<den<<endl;
					prev_num = num;
					prev_den = den;
					M--;
				}
			}
			M-=2;
		}
		cout<<prob<<endl;
	}
	return 0;
}