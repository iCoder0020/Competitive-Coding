/*
ID: iCoder0020
PROG: Summation of primes
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define N_MAX 1000000

int main()
{
	int A[N_MAX-1];
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
	long int Prime_Factors_Sum[N_MAX-1];
	for(int i = 0; i<N_MAX-1; i++)
	{
		if(i == 0)
		{
			Prime_Factors_Sum[i] = A[i];
		}
		else
		{
			Prime_Factors_Sum[i] = Prime_Factors_Sum[i-1] + A[i];
		}
	}
	int T;
	int N;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		if(N<2)
		{
			cout<<"0\n";
		}
		else
		{
			cout<<Prime_Factors_Sum[N-2]<<"\n";			
		}
	}
	return 0;
}