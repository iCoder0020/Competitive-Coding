/*
ID: ishan_sang
PROG: NMNMX
LANG: C++                  
*/
 
#include <bits/stdc++.h>

using namespace std;
 
typedef long long int li;

#define N_MAX 5000
li MOD = 1000000007;
 
li fact[N_MAX+1];

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

li calculate_nCr_mod_p(li n, li r, li p)
{
    if(r == 0)
    {
        return 1;
    }
    else if(n<=0 || n<r)
    {
        return 0;
    }
    else
    {
        return((((fact[n]%p * inversemod(fact[r], p)%p)%p) * inversemod(fact[n-r], p)%p)%p);
    }
}
 
int main()
{
	int T;
	int N,K;
	li product, m1, m2;
	cin>>T;
    fact[0] = 1;
    for(int n = 1; n<=N_MAX; n++)
    {
        fact[n] = fact[n-1]*n;
    }
	for(int t = 0; t<T; t++)
	{	
		cin>>N>>K;
		li A[N];
		product = fact[0];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
		}
		sort(A, A+N);
		for(int i = 1; i<N-1; i++)
		{
			if(N-K-i>=0)
			{
				m1 = calculate_nCr_mod_p(N-i-1,K-1,MOD);
			}
			else
			{
				m1 = fact[0] - 1;
			}
			if(i+1-K>=0)
			{
				m2 = calculate_nCr_mod_p(i,K-1,MOD);
			}
			else
			{
				m2 = fact[0] - 1;
			}
			product = ((product%MOD)*(modular_exponentiation(A[i],(calculate_nCr_mod_p(N-1,K-1,MOD) - m1 - m2),MOD)))%MOD;
		}
		cout<<product<<"\n";
	}
	return 0;
} 