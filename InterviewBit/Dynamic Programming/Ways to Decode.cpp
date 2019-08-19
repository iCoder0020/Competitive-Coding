/*
ID: ishan-sang
PROG: Ways to Decode
LANG: C++                  
*/

int Solution::numDecodings(string A) 
{
    if(A[0] == '0')
        return 0;
    int N = A.size();
    vector<int> dp(N+1, 1);
    for(int n = 2; n<=N; n++)
    {
        string temp = A.substr(n-2, 2);
        if(temp == "00" || (temp >= "27" && temp[1] == '0'))
            return 0;
        if(temp[1] == '0')
            dp[n] = dp[n-2];
        else if(temp[0] == '0' || temp >="27")
            dp[n] = dp[n-1];
        else
            dp[n] = dp[n-2] + dp[n-1];
        // cout<<A.substr(0, n)<<" "<<dp[n]<<endl;
    }
    return dp[N];
}
