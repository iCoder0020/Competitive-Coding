#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		cout<<N-1<<endl;
		for(int i = 1; i<N; i++)
		{
			int a = A[i-1], b = A[i];
			int c = min(a,b);
			cout<<i<<" "<<i+1<<" "<<1<<" "<<c<<endl;
		}
	}
	return 0;
}
