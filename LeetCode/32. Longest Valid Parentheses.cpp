/*
ID: iCoder0020
PROG: Longest Valid Parentheses
LANG: C++                  
*/

class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        int N = s.length();
        if(N == 0)
            return 0;
        int dp[N] = {0};
        int maxm = 0;
        for(int i = 1; i<N; i++)
        {
            if(s[i] == '(')
                dp[i] = 0;
            else
            {
                if(i-1 < 0)
                    dp[i] = 0;
                else
                {
                    if(s[i-1] == '(')
                        dp[i] = dp[max(0,i-2)] + 2;
                    else
                    {
                        int j = i-dp[i-1]-1;
                        if(j<0)
                            dp[i] = 0;
                        else
                        {
                            if(s[j] == '(')
                                dp[i] = 2+dp[max(0,j-1)]+dp[i-1];
                            else
                                dp[i] = 0;
                        }
                    }
                }
            }
            maxm = max(maxm, dp[i]);
        }
        return maxm;
    }
};