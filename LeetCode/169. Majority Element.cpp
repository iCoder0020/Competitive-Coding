/*
ID: iCoder0020
PROG: Majority Element
LANG: C++                  
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0;
        int cnt = 1;
        for(int n = 1; n<nums.size(); n++)
        {
            if(nums[maj] == nums[n])
                cnt++;
            else
                cnt--;
            if(cnt == 0)
            {
                maj = n;
                cnt = 1;
            }
        }
        return nums[maj];
    }
};