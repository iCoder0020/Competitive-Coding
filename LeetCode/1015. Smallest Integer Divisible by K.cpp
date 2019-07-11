/*
ID: iCoder0020
PROG: Smallest Integer Divisible by K
LANG: C++                  
*/

class Solution {
public:
    
    int smallestRepunitDivByK(int K) {
        if(K%2 == 0 || K%5 == 0)
            return -1;
        int m = 1;
        int n = 0;
        while(n<=K)
        {
            m = m%K;
            n++;
            if(m == 0)
                return n;
            m = (10*m + 1)%K;
        }
        return -1;
    }
};