/*
ID: iCoder0020
PROG: Subarray Sum Equals K
LANG: C++                  
*/

class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int sum = 0;
        int cnt = 0;
        unordered_map<int,int>M;
        M[0] = 1;
        for(int n = 0; n<nums.size(); n++)
        {
            sum += nums[n];
            cnt+=M[sum-k];
            M[sum]++;
        }
        return cnt;
    }
};