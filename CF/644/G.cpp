#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,M,A,B;
		cin>>N>>M>>A>>B;
		if(A*N != B*M)
		{
			cout<<"NO"<<endl;
			continue;
		}

		int D;
		for(int i = 1; i<M; i++)
			if((i*N)%M == 0)
				D = i;

		vector<int>row(N, A);
		vector<int>col(M, B);
		vector<vector<int>>grid(N, vector<int>(M,0));
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<M; j++)
			{
				int k = (D*i+j)%M;
				if(row[i] == 0)
					break;
				if(col[k] == 0)
					continue;
				grid[i][k] = 1;
				row[i]--;
				col[k]--;
			}
		}
		cout<<"YES"<<endl;
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<M; j++)
				cout<<grid[i][j];
			cout<<endl;
		}
	}
	return 0;
}
