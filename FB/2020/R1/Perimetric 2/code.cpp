#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin>>TC;
    for(int tc = 0; tc<TC; tc++)
    {
        int N,K;
        cin>>N>>K;
        int A,B,C,D;
        vector<int>L(N+1,0);
        vector<int>W(N+1, 0);
        vector<int>H(N+1,0);
        vector<int>R(N+1,0);
        vector<int>P(N+1,0);

        for(int k = 1; k<=K; k++)
        	cin>>L[k];
        cin>>A>>B>>C>>D;
        for(int k = K+1; k<=N; k++)
        	L[k] = ((A*L[k-2])%D + (B*L[k-1])%D + C)%D + 1;

        for(int k = 1; k<=K; k++)
        	cin>>W[k];
        cin>>A>>B>>C>>D;
        for(int k = K+1; k<=N; k++)
        	W[k] = ((A*W[k-2])%D + (B*W[k-1])%D + C)%D + 1;

        for(int k = 1; k<=K; k++)
            cin>>H[k];
        cin>>A>>B>>C>>D;
        for(int k = K+1; k<=N; k++)
            H[k] = ((A*H[k-2])%D + (B*H[k-1])%D + C)%D + 1;
        
        int ans = 1;

        vector<int>v;

        for(int n = 1; n<=N; n++)
        {
        	R[n] = 2*(H[n]+W[n]);
        	P[n] = (P[n-1] + R[n])%MOD;
            if(n>1)
            {
                int i = lower_bound(v.begin(), v.end(), L[n])-v.begin();
                if(i != v.size())
                {
                    if(v[i])
                }
            }

            v.push_back(L[n]);
            v.push_back(L[n]+W[n]);            
        	ans = (ans*P[n])%MOD;
        }
        cout<<"Case #"<<tc+1<<": "<<ans<<endl;
    }
    return 0;
}