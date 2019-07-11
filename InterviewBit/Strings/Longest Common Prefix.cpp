/*
ID: ishan-sang
PROG: Longest Common Prefix
LANG: C++                  
*/

string Solution::longestCommonPrefix(vector<string> &A) 
{
    int N = A.size();
    int min_len = INT_MAX;
    string ans = "";
    for(auto it: A)
        min_len = min(min_len, (int)it.length());
    bool flag = 0;
    for(int idx = 0; idx<min_len; idx++)
    {
        char ch = A[0][idx];
        for(int n = 1; n<N; n++)
        {
            if(A[n][idx] != ch)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
        ans += ch;
    }
    return ans;
}
