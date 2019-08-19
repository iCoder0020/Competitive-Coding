/*
ID: iCoder0020
PROG: Largest Sum of Averages
LANG: C++                  
*/

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) 
    {
        int N = A.size();
        vector<double> arr;
        for(auto it: A)
            arr.push_back((double)it);
        vector<vector<double>>dp(N+2, vector<double>(K+1, 0));
        vector<double>suffix(N, arr[N-1]);
        for(int n = N-2; n>=0; n--)
            suffix[n] = suffix[n+1] + arr[n];
        int i,j,k;
        double sum = 0, avg;
        for(i = N; i>=1; i--)
        {
            sum += arr[i-1];
            dp[i][1] = sum/(N-i+1);
        }
        
        for(i = N; i>=1; i--)
        {
            for(int j = 2; j<=K; j++)
            {
                sum = 0;
                for(k = i; k<=N; k++)
                {
                    sum += A[k-1];
                    avg = sum/(k-i+1);
                    dp[i][j] = max(dp[i][j], avg + dp[k+1][j-1]);
                }
            }
        }
        return dp[1][K];
    }
};