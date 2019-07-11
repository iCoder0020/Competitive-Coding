/*
ID: iCoder0020
PROG: Best Time to Buy and Sell Stock IV
LANG: C++                  
*/

class Solution {
public:
    vector<vector<bool>> vis;

    int f(vector<int> &p, vector<vector<int>> &v, int day, int status, int k)
    {
        if(vis[day][status])
            return v[day][status];
        vis[day][status] = true;
        if(status == k-1)
            v[day][status] = max(f(p, v, day+1, status, k), p[day]);
        else if(status%2 == 1)
            v[day][status] = max(f(p, v, day+1, status, k), p[day] + f(p, v, day+1, status+1, k));
        else
            v[day][status] = max(f(p, v, day+1, status, k), -1*p[day] + f(p, v, day+1, status+1, k));
        return v[day][status];
    }
    
    int maxProfit(int k, vector<int>& prices)
    {
        int N = prices.size();
        if(N == 0)
            return 0;
        vis.resize(N, vector<bool>(2*k, false));
        vector<vector<int>> dp(N, vector<int>(2*k,-1));
        for(int n = 0; n<2*k; n++)
            vis[N-1][n] = true;
        for(int n = 0; n<2*k; n++)
        {
        	if(k == 0)
	        	dp[N-1][k] = INT_MIN;
	        else if(k%2 == 1)
	        	dp[N-1][k] = prices[N-1];
	        else
	        	dp[N-1][k] = 0;
	    }
        return max(0,f(prices, dp, 0, 0, k));
    }
};