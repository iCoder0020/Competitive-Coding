#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e16

int N,M;
vector<int>C;
vector<int>NEXT;
vector<int>CURR;

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin>>TC;
    for(int tc = 0; tc<TC; tc++)
    {
        cin>>N>>M;
        C.clear();
        C.resize(N);
        NEXT.clear();
        NEXT.resize(M+1,0);
        CURR.clear();
        CURR.resize(M+1,INF);
        for(int n = 0; n<N; n++)
            cin>>C[n];
        int ans = INF;
        for(int n = N-2; n>=0; n--)
        {
            for(int m = 0; m<=M; m++)
            {
                int x = INF;
                if(m>=1)
                    x = NEXT[m-1];
                if(C[n] == 0)
                    CURR[m] = x;
                else
                    CURR[m] = min(x, NEXT[M-1]+C[n]);
            }
            NEXT = CURR;
        }
        for(int m = 1; m<=M; m++)
            ans = min(ans, CURR[m]);
        if(ans == INF)
            ans = -1;
        cout<<"Case #"<<tc+1<<": "<<ans<<endl;
    }
    return 0;
}