#include <bits/stdc++.h>

using namespace std;

#define int long long

void fix(vector<int>&A, int N)
{
	if(N == 2)
	{
		A[0] = 3;
		A[1] = 4;
		return;
	}
	if(N%2 == 0)
		A[N-1] = (N-2)/2;
	else
	{
		A[0] = 2;
		A[N-1] = (N+1)/2;
	}
}
int32_t main()
{
	int N,M;
	cin>>N>>M;
	vector<int> A(N, 1);
	vector<int> B(M, 1);
	fix(A,N);
	fix(B,M);
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<M; j++)
			cout<<A[i]*B[j]<<" ";
		cout<<endl;
	}
	return 0;
}
