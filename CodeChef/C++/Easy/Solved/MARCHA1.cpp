/*
ID: ishan_sang
PROG: MARCHA1
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int N,M;
	int sum;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>M;
		int C[N];
		for(int n = 0; n<N; n++)
		{
			cin>>C[n];
		}
		for(int i = 1; i<=(1<<N); i++)
		{
			sum = 0;
			for(int j = 0; j<N; j++)
			{
				if(i & (1<<j))
				{
					sum += C[j]; 
				}
			}
			if(sum == M)
			{
				cout<<"Yes\n";
				break;
			}
			if(i == (1<<N))
			{
				cout<<"No\n";
			}
		}
	}
	return 0;
}