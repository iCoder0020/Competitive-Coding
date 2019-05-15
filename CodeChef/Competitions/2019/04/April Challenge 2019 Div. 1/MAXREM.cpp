/*
ID: ishan_sang
PROG: MAXREM
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    int N;
    cin>>N;
    int A[N];
    for(int n = 0; n<N; n++)
        cin>>A[n];
    sort(A, A+N);
    int maxm = 0;
    for(int n = N-2; n>=0; n--)
    {
        if(maxm > A[n])
            break;
        if(A[n] == A[n+1])
            continue;
        for(int j = 2*A[n]; j<=A[N-1]+A[n]; j+=A[n])
        {
            int i = lower_bound(A, A+N, j) - A;
            maxm = max(maxm, A[i-1]%A[n]);
        }
    }
    int i = lower_bound(A, A+N, A[N-1]) - A;
    if(i)
    	maxm = max(maxm, A[i-1]);
    cout<<maxm<<endl;    
}