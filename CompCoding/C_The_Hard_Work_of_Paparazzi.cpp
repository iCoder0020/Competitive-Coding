#include <bits/stdc++.h>
using namespace std;
#define int long long

int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1-x2) + abs(y1-y2);
}

int32_t main()
{
    int R,N;
    cin>>R>>N;
    int X[N+1], Y[N+1], T[N+1];
    for(int n = 1; n<=N; n++)
        cin>>T[n]>>X[n]>>Y[n];
    vector<int>dp(N+1, INT_MIN);
    vector<int>maxdp(N+1, 0);
    X[0] = 1, Y[0] = 1, T[0] = 0, dp[0] = 0;
    for(int i = 1; i<=N; i++)
    {
        for(int j = i-1; j>=0; j--)
        {
            if(T[i]-T[j]>2*R)
            {
                dp[i] = max(dp[i], maxdp[j]+1);
                break;
            }
            if(T[i]-T[j]>=dist(X[i],Y[i],X[j],Y[j]))
                dp[i] = max(dp[i], dp[j]+1);
        }
        maxdp[i] = max(maxdp[i-1], dp[i]);
    }
    cout<<maxdp[N]<<endl;
    return 0;
}