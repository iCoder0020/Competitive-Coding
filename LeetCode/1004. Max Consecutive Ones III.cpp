/*
ID: iCoder0020
PROG: Max Consecutive Ones III
LANG: C++                  
*/

class Solution 
{
public:

    int maxm = 0;

    void fn(int i, int j)
    {
        maxm = max(maxm, j-i);
    }

    int longestOnes(vector<int>& A, int K) 
    {
        int N = A.size();
        int i = 0, j = 0;
        while(1)
        {
            if(A[j] == 1)
            {
                j++;
                fn(i, j);
            }
            else
            {
                if(K>0)
                {
                    j++;
                    fn(i, j);
                    K--;
                }
                else
                {
                    if(A[i] == 0)
                        K++;
                    i++;
                }
            }
            if(j >= N)
                break;
        }
        return maxm;
    }
};