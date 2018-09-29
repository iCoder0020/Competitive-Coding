/*
ID: iCoder0020
PROG: Equal
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,N;
    long long int minm;
    long long int dp[1006];
    long long int min_dp;
    dp[0] = 0;
    for(int j = 1; j<1006; j++)
    {
        dp[j] = dp[j-1]+1;
        if(j>=2)
        {
            dp[j] = min(dp[j], dp[j-2]+1);
        }
        if(j>=5)
        {
            dp[j] = min(dp[j], dp[j-5]+1);
        }
    }
    cin>>T;
    long long int sum;
    for(int t = 0; t<T; t++)
    {
        cin>>N;
        int A[N];
        for(int i = 0; i<N; i++)
        {
            cin>>A[i];
            if(i == 0)
            {
                minm = A[i];
            }
            minm = (minm<A[i])?minm:A[i];
        }
        min_dp = 100000000;
        for(int j = minm; j>=minm-5; j--)
        {
            sum = 0;
            for(int i = 0; i<N; i++)
            {
                A[i] -= j;
                sum += dp[A[i]];
            }
            for(int i = 0; i<N; i++)
            {
                A[i] += j;
            }
            min_dp = min(min_dp, sum);
        }
         cout<<min_dp<<endl;
    }
}
