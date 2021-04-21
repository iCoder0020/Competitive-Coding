#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N, C0, C1, H;
		cin>>N>>C0>>C1>>H;
		string S;
		cin>>S;
		int zero = 0, one = 0;
		for(int n = 0; n<N; n++)
			if(S[n] == '0')
				zero++;
		one = N-zero;
		int minm = N*max(C0, C1);
		for(int n = 0; n<=one; n++)
			minm = min(minm, (zero+n)*C0 + n*H + (one-n)*C1);
		for(int n = 0; n<=zero; n++)
			minm = min(minm, (one+n)*C1 + n*H + (zero-n)*C0);
		cout<<minm<<endl;
	}
	return 0;
}
