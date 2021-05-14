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
		int x = 0, y = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(n&1 && A[n]>0)
				A[n]*=-1;
			if(!(n&1) && A[n]<0)
				A[n]*=-1;
		}
		for(int n = 1; n<N; n++)
		{
			if(A[n]>=A[n-1])
				x++;
			if(A[n]<=A[n-1])
				y++;
		}
		// cout<<x<<" "<<y<<endl;
		for(int n = 0; n<N; n++)
			cout<<A[n]<<" ";
		cout<<endl;
	}
	return 0;
}
