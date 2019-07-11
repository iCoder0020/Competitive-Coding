/*
ID: iCoder0020
PROG: Single Number
LANG: C++                  
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    
        int x = 0;
        for(auto it: nums)
            x = x^it;
        return x;
    }
};