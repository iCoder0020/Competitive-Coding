/*
ID: ishan-sang
PROG: MAXSPPROD
LANG: C++                  
*/

#define MOD 1000000007
int Solution:: maxSpecialProduct(vector<int> &A) 
{
    int N = A.size();
    long long int pge[N];
    long long int nge[N];
    stack<int>S;
    for(int n = 0; n<N; n++)
    {
        while(!S.empty() && A[n] >= A[S.top()])
            S.pop();
        if(S.empty())
            pge[n] = -1;
        else
            pge[n] = S.top();
        S.push(n);
    }
    while(!S.empty())
        S.pop();
    for(int n = N-1; n>=0; n--)
    {
        while(!S.empty() && A[n] >= A[S.top()])
            S.pop();
        if(S.empty())
            nge[n] = -1;
        else
            nge[n] = S.top();
        S.push(n);
    }
    long long int maxm = 0;
    for(int n = 0; n<N; n++)
        if(nge[n] != -1 && pge[n] != -1)
            maxm = max(maxm, (nge[n])*(pge[n]));    
    return maxm%MOD;
}