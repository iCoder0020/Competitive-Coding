/*
ID: ishan-sang
PROG: Matrix Median
LANG: C++                  
*/

bool med(vector<vector<int> > &A, int x, int median)
{
    int sum = 0;
    for(auto it: A)
        sum += lower_bound(it.begin(), it.end(), x) - it.begin();
    if(sum <= median)
        return true;
    return false;
}
int Solution::findMedian(vector<vector<int> > &A) 
{
    int N = A.size();
    int M = A[0].size();
    int median = (N*M)/2;
    int lo = INT_MAX, hi = INT_MIN, mid;
    for(auto it: A)
    {
        for(auto jt: it)
        {
            lo = min(lo, jt);
            hi = max(hi, jt);
        }
    }
    int r;
    while(lo<hi)
    {
        mid = lo + (hi-lo+1)/2;
        if(med(A, mid, median))
            lo = mid;
        else
            hi = mid-1;
    }
    return lo;
}
