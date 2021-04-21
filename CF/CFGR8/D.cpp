#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	vector<int> v(20,0);
	int maxm = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		for(int i = 0; i<20; i++)
		{
			if(A[n]&(1LL<<i))
			{
				v[i]++;
				maxm = max(maxm, v[i]);
			}
		}
	}
	vector<int>x(maxm, 0);
	for(int n = 0; n<maxm; n++)
	{
		for(int i = 0; i<20; i++)
		{
			if(v[i]>0)
			{
				v[i]--;
				x[n]+= (1LL<<i);
			}
		}
	}
	int sum = 0;
	for(auto it: x)
		sum += it*it;
	cout<<sum<<endl;
	return 0;
}