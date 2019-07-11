/*
ID: ishan-sang
PROG: Sorted Permutation Rank with Repeats
LANG: C++                  
*/

#define MOD 1000003
vector<long long int>fact(MOD, 1);
long long int modular_exponentiation(long long int a, long long int b)
{
    int result = 1;
    while(b>0)
    {
        if(b&1)
            result = (result*a)%MOD;
        b/=2;
        a = (a*a)%MOD;
    }
    return result;
}

long long int inversemod(long long int a)
{
    return modular_exponentiation(a, MOD-2);
}
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
    long long int rank = 1;
    int N = A.size();
    for(int n = 2; n<MOD; n++)
        fact[n] = (n*fact[n-1])%MOD;
    for(int n = 0; n<N; n++)
    {
        map<char,int>M;
        for(int m = n; m<N; m++)
            M[A[m]]++;
        long long int p = 1;
        for(auto it: M)
            p = (p*fact[it.second])%MOD; 
        // cout<<fact[N-n-1]<<" "<<findsmaller(A,n)<<" "<<p<<" "<<inversemod(p)<<endl;
        int d = fact[N-n-1];
        d = (d*findsmaller(A,n))%MOD;
        d = (d*inversemod(p))%MOD;
        rank = (rank + d)%MOD;
    }
    return rank;
}
