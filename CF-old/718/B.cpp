#include <bits/stdc++.h>

using namespace std;

#define int long long

struct path
{
	int val;
	pair<int,int> pos;
	bool available;
};

bool valsort(path &A, path &B)
{
	return A.val < B.val;
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,M;
		cin>>N>>M;
		vector<path> B(N*M);
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<M; j++)
			{
				cin>>B[i*M + j].val;
				B[i*M + j].pos = {i,j};
				B[i*M + j].available = true;
			}
		}
		vector<path> C = B;
		sort(C.begin(), C.end(), valsort);
		vector<vector<int>>runner(M, vector<int>(N,-1));
		for(int i = 0; i<M; i++)
		{
			pair<int,int> pos = C[i].pos;
			runner[i][pos.first] = C[i].val;
			B[pos.first*M + pos.second].available = false;
		}
		for(int i = 0; i<M; i++)
		{
			for(int j = 0; j<N; j++)
			{
				if(runner[i][j] != -1)
					continue;
				for(int k = 0; k<M; k++)
				{
					if(B[j*M + k].available)
					{
						B[j*M + k].available = false;
						runner[i][j] = B[j*M + k].val;
						break;
					}
				}
			}
		}
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<M; j++)
				cout<<runner[j][i]<<" ";
			cout<<endl;	
		}
	}
	return 0;
}
