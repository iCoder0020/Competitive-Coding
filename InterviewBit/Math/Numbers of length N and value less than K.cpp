/*
ID: ishan-sang
PROG: Numbers of length N and value less than K
LANG: C++                  
*/

long long int power(long long int a, long long int b)
{
    long long int result = 1;
    while(b > 0)
    {
        if(b&1)
            result = result*a;
        b/=2;
        a = a*a;
    }
    return result;
}

int Solution::solve(vector<int> &A, int B, int C) 
{
    string s = to_string(C);
    int N = s.length();
    int M = A.size();
    vector<int>present(10, false);
    bool zero = false;
    if(M == 0)
        return 0;
    for(auto it: A)
    {
        if(it == 0)
            zero = true;
        present[it] = true;
    }
    if(N < B)
        return 0;
    if(N > B)
    {
        if(zero && B!=1)
            return (M-1)*power(M, B-1);
        else
            return power(M, B);
    }
    vector<int>dp(B, 0);
    int lesser[10] = {0};
    for(int n = 1; n<10; n++)
        lesser[n] = lower_bound(A.begin(), A.end(), n) - A.begin();
    bool poss = true;
    for (int i = 0; i < B; i++) 
    {
        int dig = s[i]-48;
        int d = lesser[dig]; 
        if(i == 0)
        {
            if(present[0] && B != 1)
                d--;
            dp[i] = d;
        }
        else
        {
            dp[i] = dp[i-1]*M;
            if(poss && present[s[i-1]-48]){
                dp[i] += d;
            }
            else{
                poss = false;
            }
        }
    } 
    return dp[B-1];
}
