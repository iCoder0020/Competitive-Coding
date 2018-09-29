/*
ID: ishan_sang
PROG: SMPAIR
LANG: C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long int T,N;
	cin>>T;
	for(long int i = 0; i<T; i++)
	{
		cin>>N;
		long int A[N];
		for(long int j = 0; j<N; j++)
		{
			cin>>A[j];
		}
		sort(A, A+N);
		cout<<A[0]+A[1]<<"\n";
	}
	return 0;
}
