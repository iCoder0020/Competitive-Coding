#include <bits/stdc++.h>

using namespace std;

#define int long long
#define LIM 63

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		int A[M];
		for(int m = 0; m<M; m++)
			cin>>A[m];
		sort(A, A+M);
		vector<int> freq(LIM, 0);
		for(int m = 0; m<M; m++)
			freq[log2(A[m])]++;
		int idx = 0;
		int ans = 0;
		for(int i = 0; i<LIM; i++)
		{
			if(N & (1LL<<i))
			{

			}
			if(freq[i]>0)
			{
				
			}
		}
		cout<<endl;
	}
	return 0;
}

