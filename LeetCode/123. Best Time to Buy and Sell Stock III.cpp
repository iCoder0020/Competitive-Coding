/*
ID: iCoder0020
PROG: Best Time to Buy and Sell Stock III
LANG: C++                  
*/

class Solution {
public:
    vector<vector<bool>> vis;

    int f(vector<int> &p, vector<vector<int>> &v, int day, int status)
    {
        if(vis[day][status])
            return v[day][status];
        vis[day][status] = true;
        if(status == 0)
            v[day][status] = max(f(p, v, day+1, 0), -1*p[day] + f(p, v, day+1, 1));
        else if(status == 1)
            v[day][status] = max(f(p, v, day+1, 1), p[day] + f(p, v, day+1, 2));
        else if(status == 2)
            v[day][status] = max(f(p, v, day+1, 2), -1*p[day] + f(p, v, day+1, 3));
        else
            v[day][status] = max(f(p, v, day+1, 3), p[day]);
        return v[day][status];
    }
    
    int maxProfit(vector<int>& prices) 
    {
        int N = prices.size();
        if(N == 0)
            return 0;
        vis.resize(N, vector<bool>(4, false));
        vector<vector<int>> dp(N, vector<int>(4,-1));
        for(int n = 0; n<4; n++)
            vis[N-1][n] = true;
        dp[N-1][0] = INT_MIN;
        dp[N-1][1] = prices[N-1];
        dp[N-1][2] = 0;
        dp[N-1][3] = prices[N-1];
        return max(0,f(prices, dp, 0, 0));
    }
};