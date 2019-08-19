/*
ID: iCoder0020
PROG: Path through Himalaya
LANG: C++                  
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
   
int32_t main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int n = 0; n<N; n++)
            cin>>A[n];
        int dp[N][N][2] = {0};          //dp[i][j][0] - max points obtained from range i-j if starting from left
        for(int i = 0; i<N; i++)
            dp[i][i][0] = dp[i][i][1] = A[i];
        for(int i = 0; i<N-1; i++)
        {
            dp[i][i+1][0] = A[i];
            dp[i][i+1][1] = A[i+1];
        }
        for(int k = 2; k<=N; k++)
        {
            for(int l = 0; l+k<N; l++)
            {
                int i = l;
                int j = l+k;
                dp[i][j][0] = A[i] + min(max(dp[i+2][j][0], dp[i+2][j][1]), max(dp[i+1][j-1][0], dp[i+1][j-1][1]));
                dp[i][j][1] = A[j] + min(max(dp[i][j-2][0], dp[i][j-2][1]), max(dp[i+1][j-1][0], dp[i+1][j-1][1]));
            }
        }
        cout<<max(dp[0][N-1][0],dp[0][N-1][1])<<endl;
    }
    return 0;
}
