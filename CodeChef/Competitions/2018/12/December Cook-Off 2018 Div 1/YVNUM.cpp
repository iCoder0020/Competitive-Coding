/*
ID: ishan_sang
PROG: YVNUM
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

#define MOD 1000000007

li toi(char ch)
{
	li num = 0;
	num = (int)(ch) - 48;
	return num;
}

li expo(li a, li b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b == 1)
	{
		return a;
	}
	else
	{
		li c = (expo(a,b/2)%MOD);
		if(b&1 == 1)
		{
			return (a*((c*c)%MOD))%MOD;
		}
		else
		{
			return (c*c)%MOD;
		}
	}
}

int main()
{
	int T;
	cin>>T;
	string base;
	for(int t = 0; t<T; t++)
	{
		li ans = 0;
		cin>>base;
		int len = base.length();
		li prefix[len+1];
		li suffix[len+1];
		for(int n = 0; n<len+1; n++)
		{
			if(n == 0)
			{
				prefix[n] = 0;
			}
			else
			{
				prefix[n] = ((prefix[n-1]*10)%MOD + toi(base[n-1]))%MOD;
			}
		}
		reverse(base.begin(), base.end());
		for(int n = 0; n<len+1; n++)
		{
			if(n == 0)
			{
				suffix[n] = 0;
			}
			else
			{
				suffix[n] = (suffix[n-1]%MOD + toi(base[n-1])*expo(10,n-1))%MOD;
			}
		}
		for(int i = 0; i<len; i++)
		{
			ans = (ans * expo(10, len))%MOD;
			ans = (ans + (((suffix[len-i]*expo(10,i))%MOD + prefix[i])%MOD))%MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}