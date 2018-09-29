/*
ID: ishan_sang
PROG: KFIB
LANG: C++                  
*/

#include <iostream>

using namespace std;

int MOD = 1000000007;

int MOD_SUM(int a, int b, int c)
{
	return (((a%MOD + b%MOD)%MOD - c%MOD + MOD)%MOD);
}

int KFIB(int N, int K, int A[])
{
	if(A[N-1] != 0)
	{
		return A[N-1];
	}
	if(N <= K)
	{
		return 1;
	}
	if(N == K + 1)
	{
		return K;
	}
	else
	{
		int new_sum = 0;
		new_sum = MOD_SUM(new_sum, 2*KFIB(N-1, K, A), 1*KFIB(N-K-1, K, A));
		A[N-1] = new_sum; 
		return new_sum;
	}
}

int main()
{
	int N, K;
	cin>>N>>K;
	int A[N];
	for(int i = 0; i<N; i++)
	{
		A[i] = 0;
	}
	cout<<KFIB(N, K, A)<<"\n";
	return 0;	
}