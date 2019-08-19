/*
ID: ishan-sang
PROG: Roman To Integer
LANG: C++                  
*/

int value(char a)
{
    if(a=='I')
        return 1;
    if(a=='V')
        return 5;
    if(a=='X')
        return 10;
    if(a=='L')
        return 50;
    if(a=='C')
        return 100;
    if(a=='D')
        return 500;
    if(a=='M')
        return 1000;
}
int Solution::romanToInt(string A) 
{
    int ans = 0;
    int N = A.length();
    for(int n = 0; n<N-1; n++)
    {
        if(value(A[n]) < value(A[n+1]))
            ans -= value(A[n]);
        else
            ans += value(A[n]);
    }
    ans += value(A[N-1]);
    return ans;
}
