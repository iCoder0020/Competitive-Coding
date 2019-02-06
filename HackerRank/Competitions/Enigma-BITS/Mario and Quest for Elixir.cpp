/*
ID: iCoder0020
PROG: Mario and Quest for Elixir
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N_MAX 1000005

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
    li T,N;
    cin>>T;
    li product = 1;
    factorials[0] = 1;
    for(li i = 1; i<N_MAX; i++)
    {
    	product = (product * i)%MOD;
    	factorials[i] = product;
    }
    while(T--)
    {
        cin>>N;
        cout<<factcalc(2*N, N, N+1, MOD)<<endl;    
    }
    return 0;
}