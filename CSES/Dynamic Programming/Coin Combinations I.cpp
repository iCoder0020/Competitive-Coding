#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main()
{
	int N,X;
	cin>>N>>X;
	vector<int>C(N);
	for(int n = 0; n<N; n++)
		cin>>C[n];
	sort(C.begin(), C.end());
	vector<int>DP(X+1, 0);
	DP[0] = 1;
	for(int x = 1; x<=X; x++)
	{
		for(int n = 0; n<N; n++)
		{
			if(x>=C[n])
				DP[x] = (DP[x] + DP[x-C[n]])%MOD;
			else
				break;
		}
	}
	cout<<DP[X]<<endl;
	return 0;
}
