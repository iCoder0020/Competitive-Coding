#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e18
#define NMAX 33

int32_t main()
{
	int N, L;
	cin>>N>>L;
	int C[N];
	for(int n = 0; n<N; n++)
		cin>>C[n];
	vector<int>DP(NMAX, INF);
	for(int i = 0; i<NMAX; i++)
	{
		if(i<N)
			DP[i] = C[i];
		for(int j = 0; j<N; j++)
		{
			if(i-j>0)
				DP[i] = min(DP[i], (1LL<<(i-j))*DP[j]);
			else
				DP[i] = min(DP[i], C[j]);
		}
		// cout<<(1LL<<i)<<" "<<DP[i]<<endl;
	}
	vector<int>cand;
	cand.push_back(L);
	for(int i = 0; i<NMAX; i++)
		if((L&(1LL<<i)) == 0)
			cand.push_back(((L>>i)+1)<<i);

	int min_ans = INF;

	for(auto it: cand)
	{
		int ans = 0;
		for(int i = 0; i<NMAX; i++)
			if(it&(1LL<<i))
				ans += DP[i];
		min_ans = min(min_ans, ans);
	}
	cout<<min_ans<<endl;
	return 0;
}
