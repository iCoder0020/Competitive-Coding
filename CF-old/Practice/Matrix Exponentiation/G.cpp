#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

struct matrix
{
	vector<vector<int>>v;
	matrix operator *(matrix other)
	{
		int N = v.size();
		matrix p;
		p.v.resize(N, vector<int>(N,0));
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				for(int k = 0; k<N; k++)
					p.v[i][j] = (p.v[i][j] + (v[i][k]*other.v[k][j])%MOD)%MOD;
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
	C.v.resize(N, vector<int>(N,0));
	for(int m = 0; m<M; m++)
	{
		int u,v;
		cin>>u>>v;
		C.v[u-1][v-1] = 1;
	}
	matrix ans;
	power(C,K,ans);
	int sum = 0;
	for(int i = 0; i<N; i++)
		for(int j = 0; j<N; j++)
			sum = (sum + ans.v[i][j])%MOD;
	cout<<sum<<endl;
	return 0;
}
