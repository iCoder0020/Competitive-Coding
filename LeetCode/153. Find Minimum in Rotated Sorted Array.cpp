/*
ID: iCoder0020
PROG: Find Minimum in Rotated Sorted Array
LANG: C++                  
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size();
        int lo = 0, hi = N-1, mid = 0;
        if(nums[lo] > nums[hi])
        {
            while(lo<hi)
            {
                mid = lo + (hi-lo)/2;
                if(nums[lo] > nums[mid])
                {
                    hi = mid;
                }           
                else
                {
                    lo = mid+1;
                }
            }
            return nums[lo];
        }
        else
        {
            return nums[lo];
        }
    }
};