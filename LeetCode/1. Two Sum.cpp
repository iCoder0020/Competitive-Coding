/*
ID: iCoder0020
PROG: Two Sum
LANG: C++                  
*/

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int,int> M;
        int N = nums.size();
        int x = -1;
        int y = -1;
        vector<int> v;
        for(int n = 0; n<N; n++)
        {
            if(M.find(nums[n]) == M.end())
            {
                M[nums[n]] = n;
            }
            if(M.find(target - nums[n]) != M.end() && M[target-nums[n]] != n)
            {
                x = M[target-nums[n]];
                y = n;
                break;
            }
        }    
        v.push_back(x);
        v.push_back(y);
        return v;  
    }
};