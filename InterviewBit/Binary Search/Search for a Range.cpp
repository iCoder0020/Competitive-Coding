/*
ID: ishan-sang
PROG: Search for a Range
LANG: C++                  
*/

vector<int> Solution::searchRange(const vector<int> &A, int B) 
{
    int lo,mid,hi;
    int N = A.size();
    int start,end;
    vector<int>ans;
    
    lo = 0;
    hi = N-1;
    while(lo<hi)
    {
        mid = lo + (hi-lo)/2;
        if(A[mid] < B)
            lo = mid+1;
        else
            hi = mid;
    }
    start = lo;
    
    lo = 0;
    hi = N-1;
    while(lo<hi)
    {
        mid = lo + (hi-lo+1)/2;
        if(A[mid] > B)
            hi = mid-1;
        else
            lo = mid;
    }
    end = lo;
    if(A[start] != B && A[end] != B)
        start = end = -1;
    ans.insert(ans.end(), {start, end});
    return ans;
}
