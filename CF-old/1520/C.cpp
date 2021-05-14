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
		int A[N][N];
		if(N == 2)
			cout<<-1<<endl;
		else
		{
			int cnt = 1;
			for(int n = 0; n<N; n++)
			{
				for(int m = 0; m<N; m++)
				{
					A[n][m] = cnt;
					cnt++;
				}
			}
			for(int m = 1; m<N; m+=2)
			{
				int B[N];
				for(int n = 0; n<N; n++)
					B[n] = A[n][m];
				for(int n = 0; n<N; n++)
					A[n][m] = B[(n+1)%N];
			}
			for(int n = 0; n<N; n++)
			{
				for(int m = 0; m<N; m++)
				{
					cout<<A[n][m]<<" ";
				}
				cout<<endl; 
			}
		}
	}
	return 0;
}
