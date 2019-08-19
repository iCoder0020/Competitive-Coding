/*
ID: ishan-sang
PROG: Ways to color a 3xN Board
LANG: C++                  
*/

#define MOD 1000000007
int Solution::solve(int A) 
{
    if(A == 0)
        return 0;
    vector<long long>s(A, 0);
    vector<long long>d(A, 0);
    s[0] = 12, d[0] = 24;
    for(int n = 1; n<A; n++)
    {
        s[n] = ((7*s[n-1])%MOD + (5*d[n-1])%MOD)%MOD;
        d[n] = ((10*s[n-1])%MOD + (11*d[n-1])%MOD)%MOD;
    }
    return (s[A-1] + d[A-1])%MOD;
}
