/*
ID: iCoder0020
PROG: Maximum Product Subarray
LANG: C++                  
*/

class Solution 
{
public:
    int min3(int a, int b, int c)
    {
        return min(a, min(b,c));
    }
    int max3(int a, int b, int c)
    {
        return max(a, max(b,c));
    }
    int maxProduct(vector<int>& nums) 
    {
        int N = nums.size();
        vector<int>dp_min(N);
        vector<int>dp_max(N);
        int maxm;
        dp_min[0] = dp_max[0] = maxm = nums[0];
        for(int n = 1; n<N; n++)
        {
            dp_min[n] = min3(nums[n], dp_min[n-1]*nums[n], dp_max[n-1]*nums[n]);
            dp_max[n] = max3(nums[n], dp_min[n-1]*nums[n], dp_max[n-1]*nums[n]);
            maxm = max(maxm, dp_max[n]);
        }
        return maxm;
    }
};