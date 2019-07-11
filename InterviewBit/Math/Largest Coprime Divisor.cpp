/*
ID: ishan-sang
PROG: Largest Coprime Divisor
LANG: C++                  
*/

int Solution::cpFact(int A, int B) 
{
    while(1)
    {
        int d = __gcd(A,B);
        if(d == 1)
            break;
        A/=d;
    }
    return A;
}

