/*
ID: iCoder0020
PROG: 10001st prime
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define N_MAX 1000000

int main()
{
	int A[N_MAX-1];
	int prime_factors_count = 0;
	for(int i = 0; i<N_MAX-1; i++)
	{
		A[i] = i+2;
	}
	for(int i = 2; i<=N_MAX/2; i++)
	{
		for(int j = 2; i*j<=N_MAX; j++)
		{
			A[i*j-2] = 0;
		}
	}
	for(int i = 0; i<N_MAX-1; i++)
	{
		if(A[i]!= 0)
		{
			prime_factors_count++;
		}
	}
	int Prime_Factors[prime_factors_count];
	int k = 0;
	for(int i = 0; i<N_MAX-1; i++)
	{
		if(A[i]!= 0)
		{
			Prime_Factors[k] = A[i];
			k++;
		}
	}
	int T;
	int N;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		cout<<Prime_Factors[N-1]<<"\n";
	}
	return 0;
}