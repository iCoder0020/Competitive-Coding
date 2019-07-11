/*
ID: ishan-sang
PROG: Trailing Zeros in Factorial
LANG: C++                  
*/

int Solution::trailingZeroes(int A) {
    int n = 0;
    int A_copy;
    int d = 1;
    while(1)
    {
        d*=5;
        A_copy = A;
        if(d > A_copy)
            break;
        while(A_copy)
        {
            A_copy /= d;
            n++;
        }
    }
    return n;
}
