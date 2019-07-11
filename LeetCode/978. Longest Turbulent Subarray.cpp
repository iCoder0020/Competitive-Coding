/*
ID: iCoder0020
PROG: Longest Turbulent Subarray
LANG: C++                  
*/

class Solution 
{
public:
    int maxTurbulenceSize(vector<int>& A) 
    {
        int N = A.size();
        int max_diff = 0;
        int t1 = 0;
        int t2 = 0;
        for(int i = 0; i<N-1; i++)
        {
            if(A[i] > A[i+1])
            {
                if(t1%2 == 0)
                    t1++;
                else
                    t1 = 1;
                if(t2%2 == 1)
                    t2++;
                else
                    t2 = 0;
            }
            else if(A[i] < A[i+1])
            {
                if(t1%2 == 1)
                    t1++;
                else
                    t1 = 0;
                if(t2%2 == 0)
                    t2++;
                else
                    t2 = 1;
            }
            else
            {
                t1 = 0;
                t2 = 0;
            }
            max_diff = max(max_diff, max(t1,t2));
        }
        return max_diff+1;    
    }
};