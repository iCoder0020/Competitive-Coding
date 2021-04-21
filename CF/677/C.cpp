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
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		int maxm = -1, maxi = -2;
		for(int n = 0; n<N; n++)
		{
			if(A[n]>maxm)
			{
				if((n-1>=0 && A[n-1]<A[n]) || (n+1<N && A[n+1]<A[n]))
					maxm = A[n], maxi = n;
			}
		}
		cout<<maxi+1<<endl;
	}
	return 0;
}