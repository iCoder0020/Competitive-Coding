/*
ID: ishan_sang
PROG: EID
LANG: C++                  
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	int N;
	int min;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
		}
		sort(A, A+N);
		min = abs(A[1] - A[0]);
		for(int n = 0; n<N-1; n++)
		{
			if(abs(A[n] - A[n+1]) < min)
			{
				min = abs(A[n] - A[n+1]);
			}
		}
		cout<<min<<"\n";
	}
	return 0;
}