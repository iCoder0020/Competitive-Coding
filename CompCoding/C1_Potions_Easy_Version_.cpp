#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int N;
    cin>>N;
    vector<int>A(N);
    for(int n = 0; n<N; n++)
        cin>>A[n];
    //  dp[i][j] -> max health if on ith bottle and consumed j bottles till
    vector<vector<int>>dp(N, vector<int>(N+1, INT_MIN));
    for(int n = 0; n<N; n++)
        dp[n][0] = 0;
    for(int n = 0; n<N; n++)
    {
        for(int m = 1; m<=n+1; m++)
        {
            if(n>0)
            {
                if(dp[n-1][m-1] + A[n] >= 0)
                    dp[n][m] = dp[n-1][m-1] + A[n];
                if(dp[n-1][m] >= 0)
                    dp[n][m] = max({dp[n][m], dp[n-1][m]});
            }
            else
            {
                if(A[n]>=0)
                    dp[n][m] = A[n];
            }
        }
    }
    int ans;
    for(int m = N; m>=0; m--)
    {
        if(dp[N-1][m]>=0)
        {
            ans = m;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}