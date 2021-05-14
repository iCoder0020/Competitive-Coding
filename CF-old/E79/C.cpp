#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		unordered_map<int,int> MAP;
		int A[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			MAP[A[n]] = n;
		}
		int B[M];
		for(int m = 0; m<M; m++)
			cin>>B[m];
		int i = 0, j = 0;
		int ans = 0;
		for(j = 0; j<M;)
		{
			i = MAP[B[j]];
			ans += 2*(i-j)+1;
			j++;
			while(j<M && i>=MAP[B[j]])
			{
				ans++;		
				j++;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}

