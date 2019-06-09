/*
ID: iCoder0020
PROG: Find First and Last Position of Element in Sorted Array
LANG: C++                  
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int N = nums.size();
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        if(N > 0)
        {
            int lo1 = 0, hi1 = N-1, mid1 = 0;
            while(lo1 < hi1)
            {
                mid1 = lo1 + (hi1-lo1)/2;
                if(nums[mid1] < target)
                {
                    lo1 = mid1+1;
                }
                else
                {
                    hi1 = mid1;
                }
            }   
            int lo2 = 0, hi2 = N-1, mid2 = 0;
            while(lo2 < hi2)
            {
                mid2 = lo2 + (hi2-lo2+1)/2;
                if(nums[mid2] > target)
                {
                    hi2 = mid2-1;
                }
                else
                {
                    lo2 = mid2;
                }
            }
            if(nums[lo1] == target)
                ans[0] = lo1;
            if(nums[lo2] == target)
                ans[1] = lo2;
        }
        return ans;
    }
};