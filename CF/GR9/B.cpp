#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,M;
		cin>>N>>M;
		int A[N][M];
		bool poss = true;
		for(int n = 0; n<N; n++)
		{
			for(int m = 0; m<M; m++)
			{
				cin>>A[n][m];
				if(A[n][m]>=5)
					poss = false;
				if(n == 0 && m == 0 && A[n][m]>=3)
					poss = false;
				if(n == 0 && m == M-1 && A[n][m]>=3)
					poss = false;
				if(n == N-1 && m == 0 && A[n][m]>=3)
					poss = false;
				if(n == N-1 && m == M-1 && A[n][m]>=3)
					poss = false;
				if((n == 0 || n == N-1 || m == 0 || m == M-1) && A[n][m]>=4)
					poss = false;
			}
		}
		if(!poss)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			for(int n = 0; n<N; n++)
			{
				for(int m = 0; m<M; m++)
				{
					A[n][m] = 4;
					if(n == 0 || n == N-1 || m == 0 || m == M-1)
						A[n][m] = 3;
					if(n == 0 && m == 0)
						A[n][m] = 2;
					if(n == 0 && m == M-1)
						A[n][m] = 2;
					if(n == N-1 && m == 0)
						A[n][m] = 2;
					if(n == N-1 && m == M-1)
						A[n][m] = 2;
					cout<<A[n][m]<<" ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
