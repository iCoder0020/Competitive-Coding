/*
ID: iCoder0020
PROG: Best Time to Buy and Sell Stock II
LANG: C++                  
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int N = prices.size();
        int B,S,P = 0;
        for(int n = 0; n<N-1; n++)
        {
            while(n+1<N && prices[n]>prices[n+1])
                n++;
            B = prices[n];
            while(n+1<N && prices[n]<prices[n+1])
                n++;
            S = prices[n];
            P += S-B;
        }
        return P;
    }
};