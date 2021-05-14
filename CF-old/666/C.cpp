#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e12

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	for(int n = 0; n<N; n++)
		cin>>A[n];
	if(N == 1)
	{
		cout<<1<<" "<<1<<endl;
		cout<<-1*A[0]<<endl;
		for(int i = 0; i<2; i++)
		{
			cout<<1<<" "<<1<<endl;
			cout<<0<<endl;
		}
	}
	else
	{
		cout<<1<<" "<<N-1<<endl;
		for(int n = 0; n<N-1; n++)
		{
			int y = A[n] - (A[n]/(N-1))*(N-1);
			int x = (N*y - A[n])/(N-1);
			A[n] += (N-1)*x;
			cout<<(N-1)*x<<" ";
		}
		cout<<endl<<2<<" "<<N<<endl;
		for(int n = 1; n<N; n++)
		{
			int y = A[n] - (A[n]/(N-1))*(N-1);
			int x = (N*y - A[n])/(N-1);
			A[n] += (N-1)*x;
			cout<<(N-1)*x<<" ";
		}
		cout<<endl<<1<<" "<<N<<endl;
		for(int n = 0; n<N; n++)
			cout<<-1*A[n]<<" ";
		cout<<endl;
	}
	return 0;
}