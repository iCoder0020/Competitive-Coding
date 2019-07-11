/*
ID: iCoder0020
PROG: Longest Arithmetic Sequence
LANG: C++                  
*/

class Solution 
{
public:
    int longestArithSeqLength(vector<int>& A) 
    {
        int N = A.size();
        if(N == 0)
            return 0;
        vector<vector<int>> las(N, vector<int>(20001, 1));
        for(int i = 1; i<N; i++)
        {
            for(int j = 0; j<i; j++)
            {
                int idx = A[i]-A[j]+10000;
                las[i][idx] = las[j][idx]+1;
            }
        }
        int maxm = 0;
        for(auto it: las)
            for(auto jt: it)
                maxm = max(maxm, jt);
        return maxm;
    }
};