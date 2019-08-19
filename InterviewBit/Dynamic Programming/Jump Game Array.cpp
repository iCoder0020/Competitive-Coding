/*
ID: ishan-sang
PROG: Jump Game Array
LANG: C++                  
*/

int Solution::canJump(vector<int> &A) 
{
    int N = A.size();
    vector<int>dp(N,0);
    dp[N-1] = 1;
    for(int n = N-2; n>=0; n--)
    {
        for(int m = 0; m<=A[n] && !dp[n]; m++)
        {
            if(n+m <N)
                dp[n]|=dp[n+m];
            else
                break;
        }
    }
    return dp[0];
}
