/*
ID: iCoder0020
PROG: Longest Increasing Subsequence
LANG: C++                  
*/

class Solution 
{
public:
    int lengthOfLIS(vector<int>& arr) 
    {
        int N = arr.size();
        if(N == 0)
            return 0;
        int lis[N];
        lis[0] = 1;
        for(int i = 1; i<N; i++)
        {
            lis[i] = 1;
            for(int j = 0; j<i; j++)
                if(arr[i] > arr[j] && lis[j]+1>lis[i])
                    lis[i] = lis[j]+1;
        }
        return *max_element(lis, lis+N);
    }
};