/*
ID: ishan-sang
PROG: Distribute Candy
LANG: C++                  
*/

int Solution::candy(vector<int> &A) 
{
    int N = A.size();
    vector<int>B (N, 1);
    
    for(int n = 1; n<N; n++)
    {
        if(A[n]>A[n-1])
            B[n] = max(B[n], B[n-1]+1);
    }
    for(int n = N-2; n>=0; n--)
    {
        if(A[n]>A[n+1])
            B[n] = max(B[n], B[n+1]+1);
    }
    int s = accumulate(B.begin(), B.end(), 0);
    return s;
}

