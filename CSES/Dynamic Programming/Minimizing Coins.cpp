#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e9

int32_t main()
{
	int N,X;
	cin>>N>>X;
	vector<int>C(N);
	for(int n = 0; n<N; n++)
		cin>>C[n];
	sort(C.begin(), C.end());
	vector<int>DP(X+1, INF);
	DP[0] = 0;
	for(int x = 1; x<=X; x++)
	{
		for(int n = 0; n<N; n++)
		{
			if(x>=C[n])
				DP[x] = min(DP[x], DP[x-C[n]]+1);
			else
				break;
		}
	}
	if(DP[X] == INF)
		cout<<-1;
	else
		cout<<DP[X];
	cout<<endl;
	return 0;
}
