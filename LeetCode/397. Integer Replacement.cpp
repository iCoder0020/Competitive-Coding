/*
ID: iCoder0020
PROG: Integer Replacement
LANG: C++                  
*/

class Solution 
{
public:
    map<int,int>M;
    int integerReplacement(long n) 
    {
        if(n == 1)
            return 0;
        if(n&1)
            return 1 + min(integerReplacement(n-1), integerReplacement(n+1));
        else
            return 1 + integerReplacement(n/2);
    }
};