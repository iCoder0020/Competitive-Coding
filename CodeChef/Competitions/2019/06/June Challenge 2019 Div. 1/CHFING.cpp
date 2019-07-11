/*
ID: ishan_sang
PROG: CHFING
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007
#define IM_2 500000004

int32_t main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,K;
        cin>>N>>K;
        int A = K, B = K+N-1;
        int n = (K-1)/(N-1);
        int unreachable = ((((n+1)%MOD)*((K-1)%MOD))%MOD - ((((n%MOD)*((n+1)%MOD))%MOD * IM_2)%MOD * ((N-1)%MOD))%MOD + MOD)%MOD;
        cout<<unreachable<<endl;
    }
    return 0;
}