/*
ID: ishan_sang
PROG: JAGAM
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N,Z1,Z2;
	long int S;
	int win;
	int player;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		win = -1;
		player = 0;
		cin>>N>>Z1>>Z2;
		long int A[N];
		long int B[4*N];
		long int C[8*N];
		long int S[2*N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
		}	
		for(int n = 0; n<4*N; n++)
		{
			if(n<2*N)
			{
				if(n<N)
				{
					B[n] = Z1 + A[n];
				}
				else
				{
					B[n] = Z1 - A[n - N];
				}
			}
			else
			{
				if(n<3*N)
				{
					B[n] = Z2 + A[n - 2*N];
				}
				else
				{
					B[n] = Z2 - A[n - 3*N];
				}
			}
		}
		for(int n = 0; n<8*N; n++)
		{
			if(n<4*N)
			{
				C[n] = B[n] + A[n%4];
			}
			else
			{
				C[n] = B[n] - A[n%4];
			}
		}

		sort(A, A+N);
		sort(B, B+4*N);
		sort(C, C+8*N);

		S = 0;
		
		if()
		{
			cout<<"0\n";
		}
		else
		{
			while(win == -1)
			{
				if()
				{
					win = player%2 + 1;
					break;
				}
				player++;
			}
			cout<<win<<"\n";
		}
	}
	return 0;
}