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
		sort(A,A+N,greater<int>());
		bool done[N];
		for(int n = 0; n<N; n++)
			done[n] = false;
		int B[N];
		B[0] = A[0];
		done[0] = true;
		int currg = B[0];
		for(int idx = 1; idx<N; idx++)
		{
			int g = 0;
			int k = 1;
			while(k<N && done[k])
				k++;
			for(int j = 1; j<N; j++)
			{	
				if(done[j])
					continue;
				int x = __gcd(currg, A[j]);
				if(g<x)
				{
					g = x;
					k = j;
				}
			}
			// cout<<idx<<" "<<A[k]<<endl;
			B[idx]=A[k];
			done[k] = true;
			currg=g;
		}
		for(int n = 0; n<N; n++)
			cout<<B[n]<<" ";
		cout<<endl;
	}	
	return 0;
}
