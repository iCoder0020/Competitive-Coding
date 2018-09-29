/*
ID: iCoder0020
PROG: Circular Array Rotation
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N,K,Q;
	int i;
	cin>>N>>K>>Q;
	int A[N];
	K = K%N;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	for(int q = 0; q<Q; q++)
	{
		cin>>i;
		cout<<A[(i-K+N)%N]<<"\n";
	}
	return 0;
}