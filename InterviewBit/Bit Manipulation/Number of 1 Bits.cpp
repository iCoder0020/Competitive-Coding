/*
ID: ishan-sang
PROG: Number of 1 Bits
LANG: C++                  
*/

int Solution::numSetBits(unsigned int A) 
{
    int cnt = 0;
    while(A)
    {
        cnt += A%2;
        A/=2;
    }
    return cnt;
}

