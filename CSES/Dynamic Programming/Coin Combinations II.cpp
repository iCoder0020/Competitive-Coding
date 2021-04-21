#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

int32_t main()
{
	int N,X;
	cin>>N>>X;
	vector<int>C;
	for(int n = 0; n<N; n++)
	{
		int c;
		cin>>c;
		if(c<=X)
			C.push_back(c);
	}
	sort(C.begin(), C.end());
	vector<int>DP(X+1, 0);
	for(int n = 1; n<=C.size(); n++)
	{
		DP[C[n-1]] += 1;
		for(int x = 1; x<=X; x++)
		{
			if(x>=C[n-1])
				DP[x] = (DP[x] + DP[x-C[n-1]])%MOD;
		}
	}
	cout<<DP[X]<<endl;
	return 0;
}
