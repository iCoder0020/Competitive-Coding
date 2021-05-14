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
		vector<int>row(N,0);
		vector<int>col(M,0);
		for(int n = 0; n<N; n++)
		{
			for(int m = 0; m<M; m++)
			{
				cin>>A[n][m];
				if(A[n][m] == 1)
				{
					row[n] = 1;
					col[m] = 1;
				}
			}
		}
		int x = accumulate(row.begin(), row.end(), 0);
		int y = accumulate(col.begin(), col.end(), 0);
		int z = min(N-x, M-y);
		if(z%2)
			cout<<"Ashish";
		else
			cout<<"Vivek";
		cout<<endl;
	}
	return 0;
}
