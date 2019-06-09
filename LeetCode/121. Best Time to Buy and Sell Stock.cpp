/*
ID: iCoder0020
PROG: Best Time to Buy and Sell Stock
LANG: C++                  
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = INT_MAX;
        int maxp = 0;
        for(auto it: prices)
        {
            if(it< minp)
                minp = it;
            else if(it - minp > maxp)
                maxp = it - minp;
        }
        return maxp;
    }
};