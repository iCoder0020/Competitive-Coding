#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e12

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int A[N+1];
		for(int n = 1; n<=N; n++)
			cin>>A[n];
		int n = 1;
		vector<int>v;
		while(n<=N)
		{
			if(n != A[n])
				v.push_back(n);
			n++;
		}
		int cnt = 0;
		for(int i = 1; i<v.size(); i++)
		{
			if(v[i]-v[i-1]!=1)
			{
				cnt = 2;
				break;
			}
			cnt = 1;
		}
		cout<<cnt<<endl;
	}
	return 0;
}