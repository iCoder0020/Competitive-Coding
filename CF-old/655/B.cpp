#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e6

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		set<int>factors;
		for(int i = 2; i*i<=N; i++)
		{
			if(N%i == 0)
			{
				factors.insert(i);
				factors.insert(N/i);
			}
		}
		pair<int,int>p = {1,N-1};
		int minm = N-1;
		for(auto it: factors)
		{
			int a = it;
			int b = N-it;
			int g = __gcd(a,b);
			if((a*b)/g<minm)
			{
				minm = (a*b)/g;
				p = {a,b};
			}
		}
		cout<<p.first<<" "<<p.second<<endl;
	}
	return 0;
}
