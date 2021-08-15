#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int N;
    cin>>N;
    vector<int>people;
    vector<int>seats;
    for(int n = 0; n<N; n++)
    {
        int x;
        cin>>x;
        if(x == 1)
            people.push_back(n);
        else    
            seats.push_back(n);
    }
    int P = people.size();
    int S = seats.size();
    int ans = 0;
    if(P)
    {
        // dp[i][j] = min cost if ith person sits on jth seat
        vector<vector<int>>dp(P, vector<int>(S, INT_MAX));
        vector<vector<int>>pre(P, vector<int>(S,INT_MAX));
        for(int j = 0; j<S; j++)
        {
            dp[0][j] = abs(people[0]-seats[j]);
            pre[0][j] = dp[0][j];
            if(j)
                pre[0][j] = min(pre[0][j-1], pre[0][j]);
        }
        for(int i = 1; i<P; i++)
        {
            for(int j = i; j<S; j++)
            {
                dp[i][j] = min(dp[i][j], pre[i-1][j-1] + abs(people[i]-seats[j]));
                pre[i][j] = min(pre[i][j-1], dp[i][j]);
            }
        }
        ans = pre[P-1][S-1];
    }
    cout<<ans<<endl;
    return 0;
}