/*
ID: ishan_sang
PROG: PERMUT2
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	while(1)
	{
		cin>>N;
		if(N == 0)
		{
			break;
		}
		else
		{
			int A[N];
			for(int n = 0; n<N; n++)
			{
				cin>>A[n];
			}
			for(int n = 0; n<N; n++)
			{
				if(A[A[n]-1] != n+1)
				{
					cout<<"not ambiguous";
					break;
				}
				if(A[A[n]-1] == n+1 && n == N-1)
				{
					cout<<"ambiguous";
				}
			}
			cout<<"\n";
		}
	}
	return 0;
}