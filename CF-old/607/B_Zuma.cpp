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
    vector<vector<int>>dp(N, vector<int>(N,1));
    // dp[i][j] = min. #moves to clear i...j
    
    for(int i = 1; i<N; i++)
        dp[i-1][i] = (A[i-1] == A[i])?1:2;
    
    for(int l = 3; l<=N; l++)
    {
        for(int i = 0; i<=N-l; i++)
        {
            int j = i+l-1;
            dp[i][j] = min(dp[i+1][j], dp[i][j-1])+1;
            if(A[i] == A[j])
                dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
            for(int k = j-1; k>i; k--)
                if(A[k] == A[j])
                    dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j]);
        }
    }
    cout<<dp[0][N-1]<<endl;
}