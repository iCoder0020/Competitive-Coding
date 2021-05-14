#include <bits/stdc++.h>

using namespace std;

#define intu unsigned long long
#define int long long
#define MOD 4294967296

struct matrix
{
	vector<vector<intu>>v;
	matrix operator *(matrix other)
	{
		int N = v.size();
		matrix p;
		p.v.resize(N, vector<intu>(N,0));
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				for(int k = 0; k<N; k++)
					p.v[i][j] = (p.v[i][j] + (v[i][k]*other.v[k][j])%MOD)%MOD;
		return p;
	}
	matrix operator +(matrix other)
	{
		int N = v.size();
		matrix p;
		p.v.resize(N, vector<intu>(N,0));
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				p.v[i][j] = (v[i][j] + other.v[i][j])%MOD;
		return p;
	}
	void operator =(matrix other)
	{
		v = other.v;
	}
};

matrix I;

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

void sum(matrix &A, int N, matrix &ans)
{
	if(N == 1)
		ans = A;
	else
	{
		matrix temp;
		matrix temp2;
		sum(A, N/2, temp);
		power(A, N/2, temp2);
		temp = temp*(I + temp2);
		if(N&1)
			ans = temp + temp2*temp2*A;
		else
			ans = temp;
	}
}

int32_t main()
{
	int N;
	cin>>N;
	int S = 0;
	if(N>0)
	{
		int bsize = 64;
		I.v.resize(bsize, vector<intu>(bsize,0));
		for(int i = 0; i<bsize; i++)
			I.v[i][i] = 1;
		matrix C;
		C.v.resize(bsize, vector<intu>(bsize,0));
		for(int i = 0; i<8; i++)
		{
			for(int j = 0; j<8; j++)
			{
				int n = 8*i+j;
				if(i-2>=0 && j-1>=0)
					C.v[n][8*(i-2)+(j-1)]=1;
				if(i-2>=0 && j+1<8)
					C.v[n][8*(i-2)+(j+1)]=1;

				if(i-1>=0 && j-2>=0)
					C.v[n][8*(i-1)+(j-2)]=1;
				if(i-1>=0 && j+2<8)
					C.v[n][8*(i-1)+(j+2)]=1;

				if(i+2<8 && j-1>=0)
					C.v[n][8*(i+2)+(j-1)]=1;
				if(i+2<8 && j+1<8)
					C.v[n][8*(i+2)+(j+1)]=1;

				if(i+1<8 && j-2>=0)
					C.v[n][8*(i+1)+(j-2)]=1;
				if(i+1<8 && j+2<8)
					C.v[n][8*(i+1)+(j+2)]=1;
			}
		}
		matrix ans;
		sum(C,N,ans);
		for(int i = 0; i<bsize; i++)
			S = (S + ans.v[i][0])%MOD;
	}
	cout<<S+1<<endl;
	return 0;
}
