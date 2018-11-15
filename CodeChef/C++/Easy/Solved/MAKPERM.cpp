/*
ID: ishan_sang
PROG: MAKPERM
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T,N;
	int num;
	int count;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		int A[N] = {0};
		count = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>num;
			if(num<=N && A[num-1] == 0)
			{
				A[num-1] = 1;
			}
		}
		for(int n = 0; n<N; n++)
		{
			if(A[n] == 0)
			{
				count++;
			}
		}
		cout<<count<<"\n";
	}
	return 0;
}