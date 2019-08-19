/*
ID: ishan-sang
PROG: Intersecting Chords in a Circle
LANG: C++                  
*/

#define MOD 1000000007
int Solution::chordCnt(int A) 
{
    vector<long long> DP(A+1, 0);
    DP[0] = DP[1] = 1;
    for(int n = 2; n<=A; n++)
    {
        for(int i = 0; i<n; i++)
        {
            DP[n] = (DP[n] + DP[i]*DP[n-1-i])%MOD;
        }
    }
    return DP[A];
}
