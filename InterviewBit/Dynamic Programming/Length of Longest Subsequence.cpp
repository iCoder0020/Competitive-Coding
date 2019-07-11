/*
ID: ishan-sang
PROG: Length of Longest Subsequence
LANG: C++                  
*/

int Solution::longestSubsequenceLength(const vector<int> &arr) 
{
    int N = arr.size();
    vector<int>lis(N, 1);
    vector<int>lds(N, 1);
    for(int i = 1; i<N; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(arr[i] > arr[j] && lis[j]+1 > lis[i])
                lis[i] = lis[j]+1;
        }
    }
    for(int i = N-2; i>=0; i--)
    {
        for(int j = i+1; j<N; j++)
        {
            if(arr[i] > arr[j] && lds[j]+1 > lds[i])
                lds[i] = lds[j]+1;
        }
    }
    int maxm = 0;
    for(int n = 0; n<N; n++)
        maxm = max(maxm, lis[n] + lds[n] -1);
    return maxm;
}
