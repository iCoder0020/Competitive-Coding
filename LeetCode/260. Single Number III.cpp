/*
ID: iCoder0020
PROG: Single Number III
LANG: C++                  
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        vector<int>ans;
        for(auto it: nums)
            x=x^it;
        int a = 0, b = 0;
        int f = (x & (~(x-1)));
        for(auto it: nums)
        {
            if(it & f)
                a=a^it;
            else
                b = b^it;
        }
        return {a,b};
    }
};