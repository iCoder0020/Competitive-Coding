/*
ID: iCoder0020
PROG: Appending Mex
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	int T = 1;
	cin>>N;
	long long int A[N];
	long long int max;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	if(A[0] != 0)
	{
		cout<<T<<"\n";
	}
	else if(N == 1)
	{
		cout<<"-1\n";
	}
	else
	{
		max = A[0];
		for(int n = 1; n<N; n++)
		{
			T++;
			if(A[n]>max+1)
			{
				cout<<T<<"\n";
				break;
			}
			else
			{
				if(A[n]>max)
				{
					max = A[n];
				}
				if(n == N-1)
				{
					cout<<"-1\n";
				}
			}
		}
	}
	return 0;
}