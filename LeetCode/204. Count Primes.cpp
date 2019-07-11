/*
ID: iCoder0020
PROG: Count Primes
LANG: C++                  
*/

class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
            return 0;
        bool primes[n] ={0};
        for(int i = 2; i*i<n; i++)
        {
            if(primes[i] == false)
            {
                for(int j = i*i; j<n; j+=i)
                    primes[j] = true;
            }
        }
        int cnt  = 0;
        for(int i = 2; i<n; i++)
            if(primes[i] == false)
                cnt++;
        return cnt;
    }
};