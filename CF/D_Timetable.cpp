#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int N,M,K;
    cin>>N>>M>>K;
    string S[N];
    vector<int> first(N+1, -1), last(N+1, -1);
    vector<vector<int>> classes(N+1);
    for(int n = 0; n<N; n++)
    {
        cin>>S[n];
        for(int m = 0; m<M; m++)
        {
            if(S[n][m] == '1')
                classes[n+1].push_back(m);
        }
    }
    // dp[i][j] -> answer if by ith day, exactly j lessons skipped
    vector<vector<int>>dp(N+1, vector<int>(K+1, INT_MAX));

    // B[i][j] -> min #hours to attend if exactly j lessons are skipped
    vector<vector<int>>B(N+1, vector<int>(M+1, INT_MAX));

    for(int i = 1; i<=N; i++)
    {
        int m = classes[i].size();
        for(int j = 1; j<m; j++)
        {
            for(int k = 0; k<m-j; k++)
                B[i][j] = min(B[i][j], classes[i][k+j-1] - classes[i][k] + 1);
        }
    }

    // for(int i = 1; i<=N; i++)
    // {
    //     for(int j = 1; j<classes[i].size(); j++)
    //         cout<<B[i][j]<<" ";
    //     cout<<endl;
    // }

    dp[0][0] = 0;
    for(int n = 1; n<=N; n++)
    {
        dp[n][0] = dp[n-1][0];
        if(classes[n].size() == 0)
            continue;
        first[n] = classes[n][0];
        last[n] = classes[n][classes[n].size()-1];
        dp[n][0] += last[n]-first[n]+1;
    }
    for(int i = 1; i<=N; i++)
    {
        int total = last[i]-first[i]+1;
        int m = classes[i].size();
        if(m == 0)
            total = 0;
        
        // took j classes off
        for(int j = 0; j<=m; j++)
        {
            
            // attend no class
            if(j == m)
            {
                for(int k = m; k<=K; k++)
                    dp[i][k] = min(dp[i][k], dp[i-1][k-j]);
            }

            // attend all classes
            else if(j == 0)
            {
                for(int k = 0; k<=K; k++)
                    dp[i][k] = min(dp[i][k], dp[i-1][k]+total);
            }

            // attend some classes
            else
            {
                for(int k = j; k<=K; k++)
                    dp[i][k] = min(dp[i][k], dp[i-1][k-j]+B[i][m-j]);
            }
        }
        
    }

    // for(int i = 0; i<=N; i++)
    // {
    //     for(int k = 0; k<=K; k++)
    //     {
    //         cout<<dp[i][k]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<*min_element(dp[N].begin(), dp[N].end())<<endl;
    return 0;
}