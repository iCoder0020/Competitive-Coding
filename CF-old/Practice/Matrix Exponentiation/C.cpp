#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007
#define K 2

typedef int matrix[K][K];

matrix M = {{0,1},{1,1}};

void assign(matrix A, matrix B)
{
	for(int i = 0; i<K; i++)
		for(int j = 0; j<K; j++)
			A[i][j] = B[i][j];
}

void multiply(matrix A, matrix B, matrix C)
{
	for(int i = 0; i<K; i++)
		for(int j = 0; j<K; j++)
			C[i][j]=0;
	for(int i = 0; i<K; i++)
		for(int j = 0; j<K; j++)
			for(int k = 0; k<K; k++)
				C[i][j] = (C[i][j] + ((A[i][k]*B[k][j])%MOD)%MOD)%MOD;
}

void power(matrix A, int N, matrix ans)
{
	if(N == 1)
		assign(ans,A);
	else
	{
		if(N&1)
		{
			matrix temp;
			power(A,N-1,temp);
			multiply(temp,M,ans);
		}
		else
		{
			matrix temp;
			power(A,N/2,temp);
			multiply(temp,temp,ans);
		}
	}
}

int32_t main()
{
	int N;
	cin>>N;
	matrix ans;
	power(M,N+1,ans);
	cout<<ans[0][0]<<endl;
	return 0;
}
