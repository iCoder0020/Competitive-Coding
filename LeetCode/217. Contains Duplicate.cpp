/*
ID: iCoder0020
PROG: Contains Duplicate
LANG: C++                  
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        map<int,int>M;
        for(auto it: nums)
        {
            auto it1 = M.find(it);
            if(it1 == M.end())
                M[it] = 1;
            else
                return true;
        }
        return false;
    }
};