#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int TC;
    cin>>TC;
    while(TC--)
    {
        int N, M, K;
        cin>>N>>M>>K;
        vector<pair<int,int>>P(N);
        map<int,int>minm, maxm;
        for(int n = 0; n<N; n++)
        {
            cin>>P[n].first;
            P[n].second = n;
        }
        sort(P.begin(), P.end());
        int pos;
        for(int n = 0; n<N; n++)
        {
            int x = P[n].first;
            int y = P[n].second;
            if(y==0)
                pos = x;
            if(minm.find(x) == minm.end())
                minm[x] = n;
            maxm[x] = n;
        }
        // for(auto it: minm)
        //     cout<<it.first<<" "<<it.second<<endl;
        // for(auto it: maxm)
        //     cout<<it.first<<" "<<it.second<<endl;
        string ans;
        // cout<<pos<<" "<<minm[pos]<<" "<<M<<endl;
        if(minm[pos]>=M)
            ans = "NO";
        else if(maxm[pos]<M)
            ans = "YES";
        else
            ans = "MAYBE";
        cout<<ans<<endl;
    }
    return 0;
}