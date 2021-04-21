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
        int N,K,W;
        cin>>N>>K>>W;
        int A,B,C,D;
        vector<int>L(N+1,-100);
        vector<int>H(N+1,0);
        vector<int>R(N+1,0);
        vector<int>P(N+1,0);

        for(int k = 1; k<=K; k++)
        	cin>>L[k];
        cin>>A>>B>>C>>D;
        for(int k = K+1; k<=N; k++)
        	L[k] = ((A*L[k-2])%D + (B*L[k-1])%D + C)%D + 1;

        for(int k = 1; k<=K; k++)
        	cin>>H[k];
        cin>>A>>B>>C>>D;
        for(int k = K+1; k<=N; k++)
        	H[k] = ((A*H[k-2])%D + (B*H[k-1])%D + C)%D + 1;
        int ans = 1;

        for(int n = 1; n<=N; n++)
        {
        	R[n] = 2*(H[n]+W);
        	P[n] = (P[n-1] + R[n])%MOD;
    		int hmax = 0;
    		for(int m = n-1; m>=1; m--)
    		{
    			if(L[m]+W>=L[n])
    				hmax = max(H[m], hmax);
    			else
    				break;
    		}
    		if(L[n-1]+W>=L[n])
	    		P[n] = (P[n]-2*(min(hmax, H[n])+(L[n-1]+W-L[n]))+MOD)%MOD;
        	ans = (ans*P[n])%MOD;
        }
        cout<<"Case #"<<tc+1<<": "<<ans<<endl;
    }
    return 0;
}