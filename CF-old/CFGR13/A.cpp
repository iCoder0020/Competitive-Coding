#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,Q;
	cin>>N>>Q;
	int A[N];
	int sum = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		sum += A[n];
	}
	while(Q--)
	{
		int t, v;
		cin>>t>>v;
		if(t == 1)
		{
			if(A[v-1] == 1)
				sum--;
			else
				sum++;
			A[v-1] = 1 - A[v-1];
		}
		if(t == 2)
		{
			if(sum >= v)
				cout<<1;
			else
				cout<<0;
			cout<<endl;
		}
	}
	return 0;
}
