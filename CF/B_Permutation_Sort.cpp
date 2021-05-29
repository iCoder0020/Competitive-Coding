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
        vector<int>A(N);
        bool already = true;
        for(int n = 0; n<N; n++)
        {
            cin>>A[n];
            if(A[n] != n+1)
                already = false;
        }
        if(already)
            cout<<0<<endl;
        else if(A[0] == 1 || A[N-1] == N)
            cout<<1<<endl;
        else if(A[0] == N && A[N-1] == 1)
            cout<<3<<endl;
        else    
            cout<<2<<endl;
    }
    return 0;
}