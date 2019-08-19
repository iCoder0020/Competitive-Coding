/*
ID: ishan-sang
PROG: Container With Most Water
LANG: C++                  
*/

int Solution::maxArea(vector<int> &A) 
{
    int N = A.size();
    int maxm = 0;
    int i = 0,j = N-1;
    while(i<j)
    {
        maxm = max(maxm, (j-i)*min(A[j], A[i]));
        if(A[i]<A[j])
            i++;
        else
            j--;
    }
    return maxm;
}
