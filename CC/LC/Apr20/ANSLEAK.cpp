#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int N,M,K;
		cin>>N>>M>>K;
		int C[N][K];
		for(int n = 0; n<N; n++)
		{
			for(int k = 0; k<K; k++)
				cin>>C[n][k];
		}
		int freq[N][M+1];
		int max_freq[N];
		for(int n = 0; n<N; n++)
		{
			int mf = 0, mfans;
			for(int k = 0; k<K; k++)
			{
				freq[n][C[n][k]]++;
				if(mf<freq[n][C[n][k]])
				{
					mf = freq[n][C[n][k]];
					mfans = C[n][k];
				}
			}
			max_freq[n] = mfans;
		}
		for(int n = 0; n<N; n++)
			cout<<max_freq[n]<<" ";
		cout<<endl;
	}
	return 0;
}