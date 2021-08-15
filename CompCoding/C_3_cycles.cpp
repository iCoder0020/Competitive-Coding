#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int N;
    cin>>N;
    set<pair<int,int>>S;
    for(int i = 1; i<=N; i++)
    {
        if(i<N)
            S.insert({i, i+1});
        for(int j = i+3; j<=N; j+=2)
            S.insert({i, j});
    }
    cout<<S.size()<<endl;
    for(auto it: S)
        cout<<it.first<<" "<<it.second<<endl;
    return 0;
}