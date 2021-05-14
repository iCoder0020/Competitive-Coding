#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,Q;
	cin>>N>>Q;
	int A[N];
	vector<int>topcard(51, -1);
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(topcard[A[n]] == -1)
			topcard[A[n]] = n+1;
	}
	while(Q--)
	{
		int T;
		cin>>T;
		cout<<topcard[T]<<" ";
		int x = topcard[T];
		for(int i = 0; i<51; i++)
		{
			if(topcard[i] == -1)
				continue;
			if(topcard[i] < x)
				topcard[i]++;
		}
		topcard[T] = 1;
	}
	cout<<endl;
	return 0;
}
