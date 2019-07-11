/*
ID: ishan-sang
PROG: Rotated Sorted Array Search
LANG: C++                  
*/

int Solution::search(const vector<int> &A, int B) 
{
    int lo,mid,hi;
    int N = A.size();
    lo = 0;
    hi = N-1;
    if(B>=A[0])
    {
        while(lo<hi)
        {
            mid = lo + (hi-lo)/2;
            if(A[mid]<A[0])
                hi = mid-1;
            else
            {
                if(A[mid] >= B)
                    hi = mid;
                else
                    lo = mid+1;
            }
        }
        if(A[lo] == B)
            return lo;
    }
    else
    {
        while(lo<hi)
        {
            mid = lo + (hi-lo)/2;
            if(A[mid]>A[0])
                lo = mid+1;
            else
            {
                if(A[mid] >= B)
                    hi = mid;
                else
                    lo = mid+1;
            }
        }
        if(A[lo] == B)
            return lo;
    }
    return -1;
}
