/*
ID: iCoder0020
PROG: Burst Balloons
LANG: C++                  
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        int N = nums.size();
        int i,j,k;
        vector<vector<int>> dp(N+2, vector<int>(N+2, 0));
        
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        for(i = 1; i<=N; i++)   //length
            for(j = 1; j+i<=N+1; j++)   //start index with length i
                for(k = j; k<=j+i-1; k++)
                    dp[j][j+i-1] = max(dp[j][j+i-1], dp[j][k-1] + dp[k+1][j+i-1] + nums[k]*nums[j-1]*nums[j+i]);
        return dp[1][N];
    }
};