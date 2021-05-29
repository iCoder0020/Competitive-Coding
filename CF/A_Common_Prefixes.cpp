#include <bits/stdc++.h>
using namespace std;
#define int long long

string create(int N)
{
    string s(N, 'a');
    return s;
}

int32_t main()
{
    int TC;
    cin>>TC;
    while(TC--)
    {
        int N;
        cin>>N;
        int A[N];
        string S[N+1];
        for(int n = 0; n<N; n++)
            cin>>A[n];
        S[0] = create(200);
        for(int n = 1; n<=N; n++)
        {
            S[n] = S[n-1];
            int x = A[n-1];
            S[n][x] = (S[n][x] == 'a')?'b':'a';
        }
        for(int n = 0; n<=N; n++)
            cout<<S[n]<<endl;
    }
    return 0;
}