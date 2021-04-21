#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,K;
	cin>>N>>K;
	int A[N],B[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		B[n] = A[n];
	}
	sort(B,B+N);
	if(B[N-1] - B[0] <= K)
	{
		cout<<"YES\n";
		for(int n = 0; n<N; n++)
		{
			for(int x = 0; x<B[0]; x++)
				cout<<1<<" ";
			int l = 0;
			if(A[n] == B[0]+K)
			{
				cout<<1<<" ";
				l = 1;
			}
			for(int k = 0; k<A[n]-B[0]-l; k++)
				cout<<k+2<<" ";
			cout<<endl;
		}
	}
	else
		cout<<"NO\n";
	return 0;
}
