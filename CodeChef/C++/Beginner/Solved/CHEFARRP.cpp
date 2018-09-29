/*
ID: ishan_sang
PROG: CHEFARRP
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T,N;
	int count;
	int sum, product;
	cin>>T;
	for(int t = 0; t<T; t++)
	{	
		cin>>N;
		count = N;
		int A[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
		}
		for(int k = 2; k<=N; k++)
		{
			for(int n = 0; n<=N-k; n++)
			{
				sum = 0;
				product = 1;
				for(int m = n; m<n+k; m++)
				{
					sum += A[m];
					product *= A[m];
				}
				if(sum == product)
				{
					count++;
				}
			}

		}
		cout<<count<<"\n";
	}
	return 0;
}