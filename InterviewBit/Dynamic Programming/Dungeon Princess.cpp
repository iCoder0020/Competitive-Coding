/*
ID: ishan-sang
PROG: Dungeon Princess
LANG: C++                  
*/

int Solution::calculateMinimumHP(vector<vector<int> > &A) 
{
    int N = A.size();
    int M = A[0].size();
    vector<vector<int>>dp(N, vector<int>(M, 0));
    
    dp[N-1][M-1] = (A[N-1][M-1]<=0)?-1*A[N-1][M-1] + 1:1;
    for(int i = N-1; i>=0; i--)
    {
        for(int j = M-1; j>=0; j--)
        {
            if(i == N-1 && j == M-1)
                continue;
            int p1 = (i+1<N)?dp[i+1][j]:INT_MAX;
            int p2 = (j+1<M)?dp[i][j+1]:INT_MAX;
            int t = min(p1,p2);
            int need = t-A[i][j];
            dp[i][j] = need<=0?1:need;
        }
    }
    return dp[0][0];
}

