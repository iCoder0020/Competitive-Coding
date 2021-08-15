#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int TC;
    cin>>TC;
    while(TC--)
    {
        int N;
        cin>>N;
        int A[2*N];
        for(int n = 0; n<2*N; n++)
            cin>>A[n];
        sort(A, A+2*N);
        int start = 0, end = 2*N-1;
        for(int n = 0; n<2*N; n++)
        {
            if(n&1)
                cout<<A[start++]<<" ";
            else
                cout<<A[end--]<<" ";
        }
        cout<<endl;
    }
    return 0;
}