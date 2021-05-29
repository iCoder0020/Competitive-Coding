#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int N)
{
    return (N*(N-1))/2;
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
        for(int n = 0; n<N; n++)
            cin>>A[n];
        map<int,int>mapX, mapTotal;
        int cnt = 0;
        for(int n = 0; n<N; n++)
        {
            mapTotal[A[n]]++;
        }
        for(int n = N-1; n>=0; n--)
        {
            mapX[A[n]]++;
            cnt += cnt + f(mapX[A[n]]-1);
            cout<<n<<" "<<cnt<<endl;
        }
        cout<<cnt<<endl;
        
    }
    return 0;
}