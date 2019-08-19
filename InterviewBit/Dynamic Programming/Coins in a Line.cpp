/*
ID: ishan-sang
PROG: Coins in a Line
LANG: C++                  
*/

int Solution::maxcoin(vector<int> &A) 
{
    int N = A.size();
    vector<int>s(N, 0);
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, 0)));
    for(int i = 0; i<N; i++)
        dp[i][i][0] = A[i];
    for(int l = 2; l<=N; l++)
    {
        for(int i = 0; i<=N-l; i++)
        {
            dp[i][i+l-1][0] = max(A[i]+dp[i+1][i+l-1][1], A[i+l-1]+dp[i][i+l-2][1]);
            dp[i][i+l-1][1] = min(dp[i+1][i+l-1][0], dp[i][i+l-2][0]);
            // cout<<i<<" "<<i+l-1<<": "<<dp[i][i+l-1][0]<<" "<<dp[i][i+l-1][1]<<endl;
        }
    }
    return dp[0][N-1][0];
}
