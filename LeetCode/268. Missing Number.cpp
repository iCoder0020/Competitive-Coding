/*
ID: iCoder0020
PROG: Missing Number
LANG: C++                  
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        for(auto it: nums)
            s+=it;
        return (n*(n+1))/2 - s;   
    }
};