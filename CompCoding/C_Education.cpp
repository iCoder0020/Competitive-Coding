#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int TC;
    cin>>TC;
    while(TC--)
    {
        int N,C;
        cin>>N>>C;
        vector<int>A(N);
        vector<int>B(N, 0);
        vector<int>D(N, 0);
        for(int n = 0; n<N; n++)
            cin>>A[n];
        for(int n = 0; n<N-1; n++)
        {
            cin>>B[n];
            // B[n] += B[n-1];
        }
        int min_days = (C+A[0]-1)/A[0];
        int rem = 0;
        for(int n = 1; n<N; n++)
        {
            // cout<<B(-1(-1[n-1]<<" "<<rem<<endl;
            if(B[n-1]<=rem)
                D[n] = 1;
            else
                D[n] = (B[n-1]-rem+A[n-1]-1)/A[n-1] + 1;
            rem = (D[n]-1)*A[n-1]+rem-B[n-1];
            D[n] += D[n-1];
            int days =  D[n] + (C-rem + A[n]-1)/A[n];
            // cout<<"Rank: "<<n<<", days to reach: "<<D[n]<<", rem: "<<rem<<", total days: "<<days<<endl;
            min_days = min(min_days, days);
        }
        cout<<min_days<<endl;
    }
    return 0;
}