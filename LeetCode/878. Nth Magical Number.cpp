/*
ID: iCoder0020
PROG: Nth Magical Number
LANG: C++                  
*/

class Solution 
{
public:
    bool check(long A, long B, long N, long num)
    {
        long d = (A*B)/(__gcd(A,B));
        long K = num/A + num/B - num/d;        
        cout<<num<<" "<<K<<endl;
        return K>=N;
    }
    int nthMagicalNumber(long N, long A, long B) 
    {
        long lo = 1, hi = 1e18, mid;
        while(lo < hi)
        {
            mid = lo + (hi-lo)/2;
            if(check(A,B,N,mid))
                hi = mid;
            else
                lo = mid+1;
        }
        return lo%1000000007;
    }
};