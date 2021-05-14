#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 9223372036854775807

struct matrix
{
	vector<vector<int>>v;
	matrix operator *(matrix other)
	{
		int N = v.size();
		matrix p;
		p.v.resize(N, vector<int>(N,INF));
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				for(int k = 0; k<N; k++)
				{
					if(v[i][k] == INF || other.v[k][j] == INF)
						continue;
					p.v[i][j] = min(p.v[i][j], v[i][k] + other.v[k][j]);
				}
		return p;
	}
	void operator =(matrix other)
	{
		v = other.v;
	}
};

void power(matrix &A, int N, matrix &ans)
{
	if(N == 1)
		ans = A;
	else
	{
		matrix temp;
		power(A, N/2, temp);
		if(N&1)
			ans = temp*temp*A;
		else
			ans = temp*temp;
	}
}

int32_t main()
{
	int N,M,K;
	cin>>N>>M>>K;
	matrix C;
	C.v.resize(N, vector<int>(N, INF));
	for(int m = 0; m<M; m++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		C.v[u-1][v-1]=w;
	}
	matrix ans;
	power(C, K, ans);
	int min_ans = INF;
	for(int n = 0; n<N; n++)
		for(int m = 0; m<N; m++)
			min_ans = min(min_ans, ans.v[n][m]);
	if(min_ans == INF)
		cout<<"IMPOSSIBLE";
	else
		cout<<min_ans;
	cout<<endl;
	return 0;
}
