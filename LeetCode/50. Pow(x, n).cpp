/*
ID: iCoder0020
PROG: Pow(x, n)
LANG: C++                  
*/

class Solution 
{
public:
    double myPow(double x, int n) 
    {
        if(n == INT_MIN)
            return x*myPow(x, n+1);
        if(n<0)
            return myPow(1/x, -1*n);
        if(n == 0)
            return 1;
        if(n%2 == 0)
            return myPow(x*x, n/2);
        return x*myPow(x*x, (n-1)/2);
    }
};