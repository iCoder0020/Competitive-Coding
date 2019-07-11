/*
ID: ishan-sang
PROG: Sorted Permutation Rank
LANG: C++                  
*/

#define MOD 1000003
vector<int>fact(100, 1);
int findsmaller(string &A, int start)
{
    int N = A.size();
    int cnt = 0;
    for(int n = start+1; n<N; n++)
        if(A[start] > A[n])
            cnt++;
    return cnt;
}
int Solution::findRank(string A) 
{
    int rank = 1;
    int N = A.size();
    for(int n = 2; n<=100; n++)
        fact[n] = (n*fact[n-1])%MOD;
    for(int n = 0; n<N; n++)
        rank = (rank + (fact[N-n-1]*findsmaller(A, n))%MOD)%MOD;
    return rank;
}
