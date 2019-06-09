/*
ID: iCoder0020
PROG: Peak Index in a Mountain Array
LANG: C++                  
*/

class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& A) 
    {
        int N = A.size();
        int lo = 0, hi = N-1, mid;
        while(lo < hi)
        {
            mid = lo + (hi-lo)/2;
            if(A[mid-1]>=A[mid])
                hi = mid;
            else
                lo = mid+1;
        }    
        return hi-1;
    }
};