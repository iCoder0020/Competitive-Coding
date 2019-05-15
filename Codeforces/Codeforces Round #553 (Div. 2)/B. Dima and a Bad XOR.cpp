/*
ID: iCoder0020
PROG: Dima and a Bad XOR
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N,M;
	cin>>N>>M;
	int A[N][M];
	int sinxo = 0;
	int idx=-1, idy=-1;
	for(int n = 0; n<N; n++)
	{
		for(int m = 0; m<M; m++)
		{
			cin>>A[n][m];
			if(M == 1)
				sinxo ^= A[n][m];
			else if(m!=0 && A[n][m]!=A[n][0])
			{
				idx = n;
				idy = m;
			}
		}
	}
	if(M == 1)
	{
		if(sinxo == 0)
			cout<<"NIE"<<endl;
		else
		{
			cout<<"TAK"<<endl;
			for(int n = 0; n<N; n++)
				cout<<"1 ";
			cout<<endl;
		}
	}
	else if(idx == -1)
	{
		for(int n = 0; n<N; n++)
			sinxo ^= A[n][0];
		if(sinxo == 0)
			cout<<"NIE"<<endl;
		else
		{
			cout<<"TAK"<<endl;
			for(int n = 0; n<N; n++)
				cout<<"1 ";
			cout<<endl;
		}

	}
	else
	{
		cout<<"TAK"<<endl;
		for(int n = 0; n<N; n++)
		{
			if(n!=idx)
				sinxo^=A[n][0];
		}
		for(int n = 0; n<N; n++)
		{
			if(n!=idx)
				cout<<"1 ";
			else
			{
				if((sinxo^A[n][0]) == 0)
					cout<<idy+1<<" ";
				else
					cout<<"1 ";
			}
		}
		cout<<endl;
	}
	
	return 0;
}