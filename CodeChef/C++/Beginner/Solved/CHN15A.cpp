/*
ID: ishan_sang
PROG: CHN15A
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T,N,K;
	int count;
	cin>>T;
	for(int t = 0; t<T; t++)
	{	
		count = 0;
		cin>>N>>K;
		int A[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if((A[n]+K) % 7 == 0)
			{
				count++;
			}
		}
		cout<<count<<"\n";
	}
	return 0;
}