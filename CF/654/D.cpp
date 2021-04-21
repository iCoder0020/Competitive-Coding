#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,K;
		cin>>N>>K;
		vector<vector<int>>A(N, vector<int>(N,0));
		int div = K/N;
		int j = 0;
		for(int i = 0; i<N; i++)
		{
			for(int x = 0; x<div; x++)
			{
				A[i][j] = 1;
				j=(j+1)%N;
			}
			if(div>1)
				j=(j+N-1)%N;
		}
		vector<int>vis(N,0);
		int maxvis = 0;
		int rem = K%N;
		int adj = 0;
		while(rem!=0)
		{
			for(int i = 0; i<N; i++)
			{
				bool p = false;
				for(int j = 0; j<N; j++)
				{
					if(A[i][j] == 0 && vis[j] < maxvis+adj)
					{
						A[i][j] = 1;
						vis[j]++;
						maxvis = max(maxvis, vis[j]);
						p = true;
						break;
					}
				}
				if(p)
					rem--;
				if(rem == 0)
					break;
			}
			adj++;
		}
		vector<int>R(N,0);
		vector<int>C(N,0);
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				R[i]+=A[i][j], C[j]+=A[i][j];
		int a =*max_element(R.begin(), R.end()), b =*min_element(R.begin(), R.end());
		int c =*max_element(C.begin(), C.end()), d =*min_element(C.begin(), C.end());
		cout<<(a-b)*(a-b)+(c-d)*(c-d)<<endl;
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<N; j++)
				cout<<A[i][j];
			cout<<endl;
		}
	}
	return 0;
}