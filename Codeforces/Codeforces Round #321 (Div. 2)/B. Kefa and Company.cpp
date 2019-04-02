/*
ID: iCoder0020
PROG: Kefa and Company
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N,D;
	cin>>N>>D;
	pair<int,int> F[N];
	for(int n = 0; n<N; n++)
		cin>>F[n].first>>F[n].second;
	sort(F, F+N);
	bool pass = true;
	int maxm = 0;
	int sum = 0;
	int i,j,k;
	i = 0;
	for(j = 0; j<N; j++)
	{
		while(F[j].first - F[i].first >= D)
		{
			sum -= F[i].second;
			i++;
		}
		sum += F[j].second;
		maxm = max(maxm, sum);
	}
	cout<<maxm<<endl;
	return 0;
}