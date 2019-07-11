/*
ID: ishan-sang
PROG: City Tour
LANG: C++                  
*/

#define MOD 1000000007
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
int Solution::solve(int A, vector<int> &B) 
{
    int total = A-B.size();
    long long int fact[1001];
    fact[0] = 1;
    for(int n = 1; n<=1000; n++)
        fact[n] = (fact[n-1]*n)%MOD;
    sort(B.begin(), B.end());
    long long int p1 = (fact[max(1, B[0]-1)] * fact[max(1, A-B[B.size()-1])])%MOD;
    long long int p2 = 1;
    for(int n = 1; n<B.size(); n++)
    {
        p1 = (p1*fact[(B[n] - B[n-1] - 1)])%MOD;
        p2 = (p2*modular_exponentiation(2, max(0, B[n]-B[n-1]-2)))%MOD;
    }
    long long int p = fact[total];
    // cout<<p<<" "<<p1<<" "<<p2<<endl;
    p = (p*inversemod(p1))%MOD;
    p = (p*p2)%MOD;
    return p;
}
