/*
ID: iCoder0020
PROG: Minimum Size Subarray Sum
LANG: C++                  
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        map<int,int>M;
        int sum = 0;
        int l = INT_MAX;
        M[0] = 0;
        for(int n = 0; n<nums.size(); n++)
        {
            if(nums[n] >= s)
                return 1;
            sum += nums[n];
            if(sum >= s)
            {
                auto it = M.upper_bound(sum - s);
                if(it != M.end())
                {
                    if(it != M.begin())
                    {
                        it--;
                        l = min(l, n+1 - it->second);
                    }
                }
            }
            M[sum] = n+1;
        }
        if(l == INT_MAX)
            return 0;
        else 
            return l;
    }
};