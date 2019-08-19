/*
ID: ishan-sang
PROG: Longest Substring Without Repeat
LANG: C++                  
*/

int Solution::lengthOfLongestSubstring(string A) 
{
    int N = A.length();
    unordered_map<char,int>M;
    int start = 0;
    int maxm = 0;
    for(int n = 0; n<N; n++)
    {
        if(M.find(A[n]) != M.end())
            start = max(start, M[A[n]] + 1); 
        M[A[n]] = n;
        maxm = max(maxm, n-start+1);
    }
    return maxm;
}
