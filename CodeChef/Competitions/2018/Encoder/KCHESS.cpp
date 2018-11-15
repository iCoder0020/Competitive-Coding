/*
ID: ishan_sang
PROG: KCHESS
LANG: C++                  
*/

#include <bits/stdc++.h>

bool in_check(long long int X[], long long int Y[], int N, long long int X_king, long long int Y_king, int set_x, int set_y)
{
	for(int i = 0; i<N; i++)
	{
		if(X[i] == X_king-2+set_x)
		{
			if(Y[i] == Y_king - 1 + set_y || Y[i] == Y_king + 1 + set_y)
			{
				return true;
			}
		}

		if(X[i] == X_king-1+set_x)
		{
			if(Y[i] == Y_king - 2 + set_y || Y[i] == Y_king + 2 + set_y)
			{
				return true;
			}
		}

		if(X[i] == X_king+1+set_x)
		{
			if(Y[i] == Y_king - 2 + set_y|| Y[i] == Y_king + 2 + set_y)
			{
				return true;
			}
		}

		if(X[i] == X_king+2+set_x)
		{
			if(Y[i] == Y_king - 1 + set_y || Y[i] == Y_king + 1 + set_y)
			{
				return true;
			}
		}
	}
	return false;
}

using namespace std;

int main()
{
	int T;
	cin>>T;
	int N;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		long long int X[N],Y[N];
		long long int X_king,Y_king;
		for(int i = 0; i<N; i++)
		{
			cin>>X[i];
			cin>>Y[i];
		}
		cin>>X_king>>Y_king;
		bool check[9];
		check[0] = in_check(X,Y,N,X_king,Y_king,-1,-1);
		check[1] = in_check(X,Y,N,X_king,Y_king,0,-1);
		check[2] = in_check(X,Y,N,X_king,Y_king,1,-1);
		check[3] = in_check(X,Y,N,X_king,Y_king,-1,0);
		check[4] = in_check(X,Y,N,X_king,Y_king,0,0);
		check[5] = in_check(X,Y,N,X_king,Y_king,1,0);
		check[6] = in_check(X,Y,N,X_king,Y_king,-1,1);
		check[7] = in_check(X,Y,N,X_king,Y_king,0,1);
		check[8] = in_check(X,Y,N,X_king,Y_king,1,1);

		if(check[0] && check[1] && check[2] && check[3] && check[4] && check[5] && check[6] && check[7] && check[8])
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}