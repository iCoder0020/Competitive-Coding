#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353 

int32_t main()
{
    int N;
    cin>>N;
    vector<int>dp(N+1, 1);
    vector<int>pre(N+1, 1);
    vector<int>div(N+1, 0);
    dp[1] = pre[1] = 1;
    for(int n = 1; n<=N; n++)
    {
        for(int m = 1; m*n<=N; m++)
            div[m*n]++;
    }
    for(int n = 2; n<=N; n++)
    {
        dp[n] = (pre[n-1] + div[n])%MOD;
        pre[n] = (pre[n-1] + dp[n])%MOD;
    }
    cout<<dp[N]<<endl;
    return 0;
}