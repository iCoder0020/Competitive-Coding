/*
ID: iCoder0020
PROG: The Coin Change Problem
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int ll;

int N,M;
ll C[51];
ll dp[251][51];

using namespace std;

ll DP(int n, int m)
{
    if(m == M)
    {
        if(n == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    else
    {
        dp[n][m] = 0;
        int count = 0;
        while(count*C[m] <= n)
        {
            dp[n][m] += DP(n-count*C[m], m+1);
            count++;
        }
        return dp[n][m];
    }
}

int main()
{
    cin>>N>>M;
    for(int m = 0; m<M; m++)
    {
        cin>>C[m];
    }
    sort(C, C+M);
    for(int i = 0; i<N+1; i++)
    {
        for(int j = 0; j<M+1; j++)
        {
            dp[i][j] = -1;
        }
    }
    ll ans = DP(N,0);
    cout<<ans<<endl;
    return 0;
}