/*
ID: iCoder0020
PROG: Grid expansion
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N_MAX 1000

typedef long long int li;

li factorials[N_MAX];

li modular_exponentiation(li a, li b, li c)
{
	li result = 1;
	a = a%c;
	while(b>0)
	{
		if(b&1)
		{
			result = (result * a)%c;
		}
		b = b>>1;
		a = (a*a)%c;
	}
	return result;
}

li inversemod(li a, li p)
{
	return modular_exponentiation(a, p-2, p);
}

li factcalc(li n, li r1, li r2, li p)
{	
	return((((factorials[n] * inversemod(factorials[r1], p)%p)%p) * inversemod(factorials[r2], p)%p)%p);
}

int main() 
{
    li T,K;
    cin>>T>>K;
    li product = 1;
    factorials[0] = 1;
    for(li i = 1; i<N_MAX; i++)
    {
    	product = (product * i)%MOD;
    	factorials[i] = product;
    }
    li dp[T+1][K+1];
    li P[4*T+2][K+1];

    for(li t = 0; t<=4*T+1; t++)
    {
    	for(li k = 0; k<=K; k++)
    	{
    		if(t == 0)
    		{
    			P[t][k] = 1;
    		}
    		else 
    		{
    			P[t][k] = 0;
    		}
    	}
    }

    for(li t = 0; t<=T; t++)
    {
    	for(li k = 0; k<=K; k++)
    	{
    		if(t == 0 && k == 1)
	    	{
	    		dp[0][k] = 1;	
	    	}
	    	else 
	    	{
    			dp[t][k] = 0;
    		}
    	}
    }
    
    for(li t = 1; t<=T; t++)
    {
    	for(li k = 1; k<=K; k++)
    	{
    		for(li i = 1; i<=min(4*t, k); i++)
    		{
    			dp[t][k] += (((factcalc(k, i, k-i, MOD) * dp[t-1][k-i])%MOD)*P[4*t][i])%MOD;
    		}
    	}
    }
    cout<<dp[T][K]<<endl;
    return 0;
}