/*
ID: iCoder0020
PROG: Search in Rotated Sorted Array
LANG: C++                  
*/

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int N = nums.size();
        if(N > 0)
        {
            int lo = 0, hi = N-1, mid;
            int index = 0;
            if(nums[lo] > nums[hi])
            {
                while(lo < hi)
                {
                    mid = lo + (hi-lo)/2;
                    if(mid+1 < N && nums[mid]>nums[mid+1])
                    {
                        index = mid+1;
                        break;
                    }
                    if(mid-1 >=0 && nums[mid]<nums[mid-1])
                    {
                        index = mid;
                        break;
                    }
                    if(nums[mid] > nums[0])
                    {
                        lo = mid;
                    }
                    else
                    {
                        hi = mid;
                    }
                }
            }   
            lo = 0;
            hi = index-1;
            while(lo<hi)
            {
                mid = lo + (hi-lo)/2;
                if(nums[mid] >= target)
                {
                    hi = mid;
                }
                else
                {
                        lo = mid+1;
                    }
            }
            if(nums[lo] == target)
                return lo;

            lo = index;
            hi = N-1;
            while(lo<hi)
            {
                mid = lo + (hi-lo)/2;
                if(nums[mid] >= target)
                {
                    hi = mid;
                }
                else
                {
                    lo = mid+1;
                }
            }
            if(nums[lo] == target)
                return lo;
        }
        return -1;
    }
};