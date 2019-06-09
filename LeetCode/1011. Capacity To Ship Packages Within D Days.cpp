/*
ID: iCoder0020
PROG: Capacity To Ship Packages Within D Days
LANG: C++                  
*/

class Solution 
{
public:
    bool check(vector<int>& weights, int mid, int D)
    {
        int days = 1;
        int sum = 0;
        int N = weights.size();
        for(int n = 0; n<N; n++)
        {
            if(sum+weights[n] > mid)
            {
                sum = 0;
                days++;
            }
            sum += weights[n];
        }
        return days<=D;
    }

    int shipWithinDays(vector<int>& weights, int D) 
    {
        int N = weights.size();
        int maxm = 0;
        for(int n = 0; n<N; n++)
            maxm = max(maxm, weights[n]);
        int lo = maxm, hi = INT_MAX, mid;
        while(lo < hi)
        {
            mid = lo + (hi-lo)/2;
            if(check(weights, mid, D))
                hi = mid;
            else
                lo = mid+1;
        }
        return lo;
    }
};