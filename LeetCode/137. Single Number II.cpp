/*
ID: iCoder0020
PROG: Single Number II
LANG: C++                  
*/

class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int mask;
        int count;
        int result = 0;
        for(int i = 0; i<32; i++)
        {
            count = 0;
            mask = 1<<i;
            for(auto it: nums)
            {
                if(it&mask)
                    count++;
            }
            if(count%3 != 0)
                result |= mask;
        }    
        return result;
    }
};