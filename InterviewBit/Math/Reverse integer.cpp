/*
ID: ishan-sang
PROG: Reverse integer
LANG: C++                  
*/

int Solution::reverse(int A) 
{
    int sign = 0;
    if(A<0)
        sign = 1;
    A = abs(A);
    long long int N = 0;
    while(A)
    {
        N = N*10 + A%10;
        A/=10;
    }
    if(sign == 0)
    {
        if(N>INT_MAX)
            return 0;
        return N;
    }
    if(sign == 1)
    {
        N *= -1;
        if(N < INT_MIN)
            return 0;
        return N;
    }
}