#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 998244353 

int32_t main()
{
	
	int N,K;
	cin>>N>>K;
	int P[N];
	vector<int>S;
	S.push_back(1);
	for(int n = 0; n<N; n++)
	{
		cin>>P[n];
		if(P[n] > N-K)
			S.push_back(n+1);
	}
	S.push_back(N);
	int sum = N*K - (K*(K-1))/2;
	int total = 1;
	for(int n = 2; n<=K; n++)
		total = (total * (S[n]-S[n-1]))%MOD;
	cout<<sum<<" "<<total<<endl;
	return 0;
}
