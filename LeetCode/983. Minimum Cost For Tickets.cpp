/*
ID: iCoder0020
PROG: Minimum Cost For Tickets
LANG: C++                  
*/

class Solution {
public:
    int min3(int a, int b, int c)
    {
        return min(a, min(b,c));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int N = days.size();
        vector<int>dp(367,0);
        int i,j;
        j = N-1;
        for(i = 365; i>=0; i--)
        {
            if(j<0 || i != days[j])
                dp[i] = dp[i+1];
            else
            {
                dp[i] = min3(dp[i+1] + costs[0], dp[min(i+7, 365)]+ costs[1], dp[min(i+30,365)]+ costs[2]);
                j--;
            }
        }
        return dp[1];
    }
};