/*
ID: ishan_sang
PROG: VCS
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N,M,K;
	int x,y;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		x = 0, y = 0;
		cin>>N>>M>>K;
		int C[N];
		for(int j = 0; j<N; j++)
		{
			C[j] = 0;
		}
		int A[M];
		for(int j = 0; j<M; j++)
		{
			cin>>A[j];
			C[A[j]-1]++;
		}
		int B[K];
		for(int j = 0; j<K; j++)
		{
			cin>>B[j];
			C[B[j]-1]++;
		}
		for(int j = 0;j <N; j++)
		{
			if(C[j] == 0)
				y++;
			if(C[j] == 2)
				x++;
		}
		cout<<x<<" "<<y<<"\n";
	}
	return 0;
}
