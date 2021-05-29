#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int TC;
    cin>>TC;
    while(TC--)
    {
        int N;
        cin>>N;
        int d = __gcd(N, 100LL);
        cout<<100/d<<endl;
    }
    return 0;
}