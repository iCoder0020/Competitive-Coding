#include <bits/stdc++.h>
using namespace std;
#define int long long

struct car
{
    double x;
    double v;
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    while(TC--)
    {
        int N,M;
        cin>>N>>M;
        vector<int>p(M);
        vector<car>c(N);
        for(int m = 0; m<M; m++)
            cin>>p[m];
        for(int n = 0; n<N; n++)
            cin>>c[n].x;
        for(int n = 0; n<N; n++)
            cin>>c[n].v;
        
    }
    return 0;
}