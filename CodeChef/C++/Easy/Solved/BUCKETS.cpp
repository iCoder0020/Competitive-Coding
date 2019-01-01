/*
ID: ishan_sang
PROG: BUCKETS
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,K;
	cin>>N>>K;
	long double prob[N][K];
	long double A[N][K];
	long double row_sum[N];
	for(int n = 0; n<N; n++)
	{
		row_sum[n] = 0.0;
	}
	for(int i = 0; i<N; i++)
	{
		int j;
		for(j = 0; j<K; j++)
		{
			cin>>A[i][j];
			row_sum[i] += A[i][j];
		}
		for(j = 0; j<K; j++)
		{
			if(i == 0)
			{
				prob[i][j] = A[i][j]/row_sum[i];
			}
			else
			{
				prob[i][j] = ((prob[i-1][j])*(A[i][j]+1))/(row_sum[i]+1) + ((1-prob[i-1][j])*(A[i][j]))/(row_sum[i]+1);
			}
		}
	}
	for(int k = 0; k<K; k++)
	{
		cout<<fixed<<setprecision(8)<<prob[N-1][k]<<" ";
	}
	cout<<endl;
	return 0;
}