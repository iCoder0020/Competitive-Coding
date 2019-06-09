/*
ID: iCoder0020
PROG: Koko Eating Bananas
LANG: C++                  
*/

class Solution 
{
public:
    bool check(vector<int>& piles, int K, int H)
    {
        int hours = 0;
        for(auto it: piles)
            hours += (int)ceil((double)it/(double)K);
        return hours<=H;
    }

    int minEatingSpeed(vector<int>& piles, int H) 
    {
        int lo = 1, hi = INT_MAX, mid;
        while(lo < hi)
        {
            mid = lo + (hi-lo)/2;
            if(check(piles, mid, H))
                hi = mid;
            else
                lo = mid+1;
        }    
        return lo;
    }
};