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
    vector<vector<int>>dp(N, vector<int>(N,INT_MAX));
    for(int i = 0; i<N; i++)
        dp[i][i] = 0;
    for(int i = 0; i<N-1; i++)
        dp[i][i+1] = (A[i] == A[i+1])?0:1;
    int a,b,c;
    for(int len = 3; len<=N; len++)
    {
        for(int i = 0; i<=N-len; i++)
        {
            int j = i+len-1;
            a = dp[i+1][j];
            a = (A[i] == A[i+1])?a:a+1;
            b = dp[i][j-1];
            b = (A[j] == A[j-1])?b:b+1;
            c = dp[i+1][j-1];
            c = (A[i] == A[j])?c+1:c+2;
            dp[i][j] = min({a,b,c});
        }
    }
    cout<<dp[0][N-1]<<endl;
    return 0;
}