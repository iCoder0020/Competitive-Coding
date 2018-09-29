/*
ID: ishan_sang
PROG: PRB01
LANG: C++                  
*/

#include <iostream>
#include <math.h>

using namespace std;

#define N_MAX 100000

int main()
{
	int T,N;
	cin>>T;
	int A[N_MAX+1];
	A[0] = 0;
	A[1] = 0;
	for(int n = 2; n<=N_MAX; n++)
	{
		A[n] = n;
	}
	for(int n = 2; n<=sqrt(N_MAX)+1; n++)
	{
		for(int m = 2; m*n<=N_MAX; m++)
		{
			if(A[m*n])
			{
				A[m*n]=0;
			}
		}
	}
	for(int t = 0; t<T; t++)
	{	
		cin>>N;
		if(A[N])
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	return 0;
}