/*
ID: iCoder0020
PROG: Min Cost Climbing Stairs
LANG: C++                  
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int N = cost.size();
        vector<int>dp(N+1, 0);
        for(int n = 2; n<=N; n++)
            dp[n] = min(dp[n-1] + cost[n-1], dp[n-2] + cost[n-2]);
        return dp[N];
    }
};