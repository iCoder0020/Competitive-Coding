/*
ID: iCoder0020
PROG: 3Sum
LANG: C++                  
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int N = nums.size();
        for(int n = 0; n<N-2; n++)    
        {
            int target = -nums[n];
            int i = n+1;
            int j = N-1;
            while(i<j)
            {
                if(nums[i] + nums[j] == target && i!=n && j!=n)
                {
                    ans.push_back({nums[i], nums[j], nums[n]});
                    i++;
                    j--;
                    while(i<j && nums[i] == nums[i-1])
                        i++;
                    while(i<j && nums[j] == nums[j+1])
                        j--;
                }
                else if(nums[i] + nums[j] < target)
                    i++;
                else
                    j--;
            }
            while(n+1<N && nums[n] == nums[n+1])
                n++;
        }
        return ans;
    }
};