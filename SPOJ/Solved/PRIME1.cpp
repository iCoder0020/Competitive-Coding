/*
ID: icoder_0020
PROG: PRIME1
LANG: C++
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int T;
	int M,N;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>M>>N;
		if(M == 1)
        {
            M = 2;
        }
		int A[N-M+1];
		for(int i = M; i<=N; i++)
		{
			A[i-M] = i;
		}
		for(int i = 2; i<=sqrt(N); i++)
		{
			for(int j = (M/i); i*j<=N; j++)
			{
                if(j>1)
                {
                    A[i*j-M] = 0;
                }
			}
		}
		for(int i = 0; i<N-M+1; i++)
		{
			if(A[i] != 0)
			{
				cout<<A[i]<<"\n";
			}
		}
		cout<<"\n";
	}
	return 0;
}
