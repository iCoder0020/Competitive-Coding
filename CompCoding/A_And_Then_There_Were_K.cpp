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
        int x = log2(N);
        cout<<(int)(pow(2,x)-1)<<endl;
    }
    return 0;
}