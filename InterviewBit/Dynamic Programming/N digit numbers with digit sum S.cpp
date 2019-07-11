/*
ID: ishan-sang
PROG: N digit numbers with digit sum S
LANG: C++                  
*/

#define MOD 1000000007
int Solution::solve(int A, int B) 
{
    vector<vector<long long int>> dp(A+1, vector<long long int>(B+1, 0));
    if(A == 1 && B == 0)
        return 1;
    for(int j = 1; j<=min(B,9); j++)
        dp[1][j] = 1;
    for(int i = 2; i<=A; i++)
    {
        for(int j = 1; j<=B; j++)
        {
            for(int k = 0; k<10; k++)
            {
                if(j-k>0)
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k])%MOD;
            }
        }
    }
    return dp[A][B];
}

