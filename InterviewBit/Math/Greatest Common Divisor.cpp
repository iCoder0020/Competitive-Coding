/*
ID: ishan-sang
PROG: Greatest Common Divisor
LANG: C++                  
*/

int Solution::gcd(int A, int B) {
    if(A == 0)
        return B;
    if(B == 0)
        return A;
    if(A>B)
        return gcd(B, A%B);
    else
        return gcd(A, B%A);
}

