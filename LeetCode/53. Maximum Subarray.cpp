/*
ID: iCoder0020
PROG: Maximum Subarray
LANG: C++                  
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int N = nums.size();
        int dp[N];
        dp[0] = nums[0];
        int maxm = dp[0];
        for(int n = 1; n<N; n++)
            dp[n] = max(nums[n], dp[n-1]+nums[n]);
        for(int n = 0; n<N; n++)
            maxm = max(maxm, dp[n]);
        return maxm;
    }
};