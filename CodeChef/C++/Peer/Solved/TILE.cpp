/*
ID: ishan_sang
PROG: TILE
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long int mat[2][2];
mat matrix;

mat M = {{1,1}, {1,0}};

void mat_mul(mat A, mat B, mat C)
{
	C[0][0] = (((A[0][0])%MOD)*(B[0][0]%MOD) + ((A[1][0])%MOD)*((B[0][1])%MOD))%MOD;
	C[0][1] = (((A[0][1])%MOD)*(B[0][0]%MOD) + ((A[1][1])%MOD)*((B[1][0])%MOD))%MOD;

	C[1][0] = (((A[0][0])%MOD)*(B[1][0]%MOD) + ((A[1][0])%MOD)*((B[1][1])%MOD))%MOD;
	C[1][1] = (((A[0][1])%MOD)*(B[1][0]%MOD) + ((A[1][1])%MOD)*((B[1][1])%MOD))%MOD;
}

void assign(mat A, mat B)
{
	A[0][0]=B[0][0], A[0][1]=B[0][1], A[1][0]=B[1][0], A[1][1]=B[1][1];
}

void mat_power(mat A, long long int N, mat ans)
{
	if(N == 1)
	{
		assign(ans,A);
	}
	else
	{
		if(N%2 == 1)
		{
			mat_power(A, N-1, ans);
			mat temp;
			mat_mul(ans, A, temp);
			assign(ans, temp);
		}
		else
		{
			mat_power(A,N/2, ans);
			mat temp;
			mat_mul(ans, ans, temp);
			assign(ans, temp);
		}
	}
}

int main()
{
	long long int T,N;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		mat ans ={};
		mat_power(M, N, ans);
		cout<<ans[0][0]<<"\n";
	}
	return 0;
}