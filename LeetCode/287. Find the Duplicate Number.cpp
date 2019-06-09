/*
ID: iCoder0020
PROG: Find the Duplicate Number
LANG: C++                  
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int N = nums.size();
        vector<bool> arr(N+1, false);
        for(auto it: nums)
        {
            if(arr[it])
                return it;
            else 
                arr[it] = true;
        }
        return -1;
    }
};