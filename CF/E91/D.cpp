#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,M;
	cin>>N>>M;
	int X,K,Y;
	cin>>X>>K>>Y;
	int A[N], B[M];
	queue<int> Q;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		Q.push(A[n]);
	}
	for(int m = 0; m<M; m++)
	{
		cin>>B[m];
		if(!Q.empty() && Q.top()==B[m])
			Q.pop();
	}
	if(!Q.empty() || M>N)
		cout<<"-1"<<endl;
	else
	{

	}
	return 0;
}
