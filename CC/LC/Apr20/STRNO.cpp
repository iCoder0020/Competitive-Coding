#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int X,K;
		cin>>X>>K;
		int X_copy = X;
		vector<int>prime_factors;
		for(int i = 2; i*i<=X; i++)
		{
			if(X%i == 0)
			{
				prime_factors.push_back(i);
				while(X%i == 0)
					X/=i;
			}
		}
		if(X != 1)
			prime_factors.push_back(X);
		// for(auto it: prime_factors)
		// 	cout<<it<<" ";
		// cout<<endl;
		int cnt = 0;
		int p = 0;
		X = X_copy;
		while(X)
		{
			if(X == 1)
				break;
			if(X%prime_factors[p] == 0)
			{
				X/=prime_factors[p];
				cnt++;
			}
			else
				p++;
		}
		if(cnt >= K)
			cout<<"1";
		else
			cout<<"0";
		cout<<endl;
	}
	return 0;
}