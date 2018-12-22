/*
ID: iCoder0020
PROG: nCr table
LANG: C++                  
*/

#include <iostream>

using namespace std;

typedef long long int li;

#define MOD 1000000000
li fact[1005];

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
    else
    {
        return((((fact[n] * inversemod(fact[r], p))%p) * inversemod(fact[n-r], p))%p);
    }
}

int main()
{
    int T;
    cin>>T;
    li nCr[1005][1005];
    fact[0] = 1;
    for(int n = 1; n<1005; n++)
    {
        fact[n] = (fact[n-1] * n)%MOD;
    }
    for(int n = 1; n<1005; n++)
    {
        for(int m = 0; m<=n; m++)
        {
            nCr[n][m] = calculate_nCr_mod_p(n,m,MOD);
        }
    }
    for(int t = 0; t<T; t++)
    {
        int N;
        cin>>N;
        for(int n = 0; n<=N; n++)
        {
            cout<<nCr[N][n]<<" ";
        }
        cout<<endl;
    }
    return 0;
}