/*
ID: ishan_sang
PROG: KCOMPRES
LANG: C++                  
*/

#include <iostream>

using namespace std;

int max(int a, int b)
{
	return (a>b)?a:b;
}

int min(int a, int b)
{
	return (a<b)?a:b;
}

int main()
{
	int T;
	int N,S;
	long int sum, sum_copy;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>S;
		if(S<N)
		{
			cout<<"0\n";
		}
		else
		{
			int A[N];
			sum = 0;
			for(int n = 0; n<N; n++)
			{
				cin>>A[n];
				sum += A[n];
			}
			if(S>=sum)
			{
				cout<<N+1<<"\n";
			}
			else
			{
				sum_copy = sum;
				while(1)
				{

				}
			}	
		}
	}
	return 0;
}