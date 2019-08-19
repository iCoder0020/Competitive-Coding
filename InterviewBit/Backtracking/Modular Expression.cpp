/*
ID: ishan-sang
PROG: Modular Expression
LANG: C++                  
*/

int Solution::Mod(int a, int b, int c) 
{
    long long int A = a;
    long long int B = b;
    long long int C = c;
    if(A == 0)
        return 0;
    if(B == 0)
        return 1;
    while(A<0)
        A+=C;
    A = A%C;
    if(B == 1)
        return A;
    if(B&1)
        return (A*Mod(A,B-1,C))%C;
    long long int P = Mod(A, B/2, C);
    return (P*P)%C;
}
