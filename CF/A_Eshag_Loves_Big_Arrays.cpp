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
        for(int n = 0; n<N; n++)
            cin>>A[n];
        sort(A.begin(), A.end());
        int cnt = 0;
        for(int n = 0; n<N; n++)
        {
            if(A[n] == A[0])
                cnt++;
            else
                break;
        }
        cout<<N-cnt<<endl;
    }
    return 0;
}