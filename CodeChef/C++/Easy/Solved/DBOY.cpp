/*
ID: ishan_sang
PROG: DBOY
LANG: C++                  
*/
 
#include <bits/stdc++.h>

#define big 100000000

using namespace std;

int main()
{
	int T, N;
    long long int minm;
    long long int dp[1001];
    long long int sum;
    cin>>T;
    for(int t = 0; t<T; t++)
    {
        cin>>N;
        sum = 0;
        int H[N], K[N];
        dp[0] = 0;
        for(int n = 1; n<=1000; n++)
        {
            dp[n] = big;
        }
        for(int n = 0; n<N; n++)
        {
            cin>>H[n];
        }
        for(int n = 0; n<N; n++)
        {
            cin>>K[n];
            dp[K[n]] = 1;
        }
        sort(K, K+N);
        for(int n = K[0]+1; n<=1000; n++)
        {
            minm = dp[n-K[0]];
            for(int k = 1; k<N; k++)
            {
                if(K[k] <= n)
                {
                    minm = min(minm, dp[n-K[k]]);
                }    
            }
            dp[n] = minm + 1;
        }
        for(int n = 0; n<1001; n++)
        {
            if(dp[n] >= big)
            {
                dp[n] = 0;
            }
        }
        for(int n = 0; n<N; n++)
        {
            sum += dp[2*H[n]];
        }
        cout<<sum<<"\n";
    }
	return 0;
} 