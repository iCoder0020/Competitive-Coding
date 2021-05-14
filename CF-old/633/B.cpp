#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		sort(A, A+N);
		int l = N/2-1+N%2;
		int r = l+1;
		int B[N];
		int k = 0;
		while(l>=0)
		{
			B[k] = A[l];
			l--;
			k+=2;
		}
		k = 1;
		while(r<N)
		{
			B[k] = A[r];
			r++;
			k+=2;
		}
		for(int n = 0; n<N; n++)
			cout<<B[n]<<" ";
		cout<<endl;
	}
	return 0;
}
