/*
ID: ishan-sang
PROG: Allocate Books
LANG: C++                  
*/

bool check(vector<int> &A, int M, int x)
{
    int N = A.size();
    int m = 0;
    int s = 0;
    for(int i = 0; i<N; i++)
    {
        if(s + A[i] <= x)
            s+=A[i];
        else
        {
            m++;
            s = A[i];
        }
    }
    m++;
    return (m>M);
}
int Solution::books(vector<int> &A, int M) 
{
    int N = A.size();
    if(N<M)
        return -1;
    int sum = accumulate(A.begin(), A.end(), 0);
    int lo,mid,hi;
    lo = *max_element(A.begin(), A.end());
    hi = sum;
    while(lo<hi)
    {
        mid = lo + (hi-lo)/2;
        if(check(A, M, mid))
            lo = mid+1;
        else
            hi = mid;
    }
    return lo;
}
