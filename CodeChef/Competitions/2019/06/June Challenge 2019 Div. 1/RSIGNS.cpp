/*
ID: ishan_sang
PROG: RSIGNS
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int modular_exponentiation(int a, int b)
{
    int result = 1;
    a = a%MOD;
    while(b>0)
    {
        if(b&1)
        {
            result = (result * a)%MOD;
        }
        b = b>>1;
        a = (a*a)%MOD;
    }
    return result;
}

int32_t main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int K;
        cin>>K;
        cout<<(5*modular_exponentiation(2, K))%MOD<<endl;
    }
    return 0;
}