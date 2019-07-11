/*
ID: ishan-sang
PROG: Tushar's Birthday Party
LANG: C++                  
*/

int Solution::solve(const vector<int> &friend_cap, const vector<int> &food_cap, const vector<int> &food_cost) 
{
    int max_cap = *max_element(friend_cap.begin(), friend_cap.end());
    vector<long long int> dp(max_cap+1, 0);
    
    for(int i = 1; i<=max_cap; i++)
    {
        for(int j = 0; j<food_cap.size(); j++)
        {
            if(i >= food_cap[j])
            {
                if(dp[i] == 0)
                    dp[i] = food_cost[j] + dp[i-food_cap[j]];
                else
                    dp[i] = min(dp[i], food_cost[j] + dp[i-food_cap[j]]);
            }
        }
    }
    int ans = 0;
    for(auto it: friend_cap)
        ans += dp[it];
    return ans;
}
