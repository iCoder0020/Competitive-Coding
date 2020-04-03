#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,D;
		cin>>N>>D;
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		int i = 1;
		int days = D;
		while(i<N)
		{
			while(A[i]>0 && days-i>=0)
			{
				A[0]++;
				days-=i;
				A[i]--;
			}
			i++;
		}
		cout<<A[0]<<endl;
	}
	return 0;
}
