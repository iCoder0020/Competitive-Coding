/*
ID: ishan_sang
PROG: CHHAPPY
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T,N;
	bool possible;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		possible = false;
		int A[N+1];
		int B[N+1] = {0};
		int C[N+1] = {0};
		for(int n = 1; n<=N; n++)
		{
			cin>>A[n];
			B[A[n]]++;
		}
		for(int n = 1; n<=N; n++)
		{
			if(B[n]!=0)
			{
				C[A[n]]++;
				if(C[A[n]] == 2)
				{
					possible = true;
				}
			}
			if(possible)
			{
				break;
			}
		}
		if(possible)
		{
			cout<<"Truly Happy";
		}
		else
		{
			cout<<"Poor Chef";
		}
		cout<<"\n";
	}
	return 0;
}