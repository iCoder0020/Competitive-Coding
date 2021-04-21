#include <bits/stdc++.h>

using namespace std;

#define int long long

struct tree
{
    int p;
    int h;
};

bool comp(tree &A, tree &B)
{
    return A.p<B.p;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin>>TC;
    for(int tc = 0; tc<TC; tc++)
    {
        int N;
        cin>>N;
        vector<tree>T(N);
        for(int n = 0; n<N; n++)
            cin>>T[n].p>>T[n].h;
        sort(T.begin(), T.end(), comp);
        unordered_map<int,int>MAP;
        int ans = 0;
        for(int n = 0; n<N; n++)
        {
            MAP[T[n].p+T[n].h] = max(MAP[T[n].p] + T[n].h, MAP[T[n].p+T[n].h]);
            MAP[T[n].p] = max(MAP[T[n].p], MAP[T[n].p-T[n].h] + T[n].h);
        }
        for(auto it: MAP)
            ans = max(ans, it.second);
        cout<<"Case #"<<tc+1<<": "<<ans<<endl;
    }
    return 0;
}