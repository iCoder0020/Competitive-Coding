/*
ID: iCoder0020
PROG: Divisible Sum Pairs
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	int K;
	cin>>N>>K;
	int A[N];
	for(int n=0; n<N; n++)
	{
		cin>>A[n];
	}	
	int count = 0;
	for(int i=0; i<N-1; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			if((A[i]+A[j])%K == 0)
			{
				count++;
			}
		}
	}
	cout<<count<<"\n";
	return 0;
}