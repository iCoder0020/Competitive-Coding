/*
ID: iCoder0020
PROG: Shekhar and his laziness
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
        long long int N,M;
        cin>>N>>M;
        long long int A[N] = {0};
        while(M--)
        {
            long long int K,L,R;
            cin>>K>>L>>R;
            A[L-1] += K;
            if(R<N)
            {
                A[R] -= K; 
            }
        }
        for(int n = 0; n<N; n++)
        {
            if(n != 0)
            {
                A[n] += A[n-1];
            }
            cout<<A[n]<<" ";
        }
        cout<<endl;
    }
    return 0;
}