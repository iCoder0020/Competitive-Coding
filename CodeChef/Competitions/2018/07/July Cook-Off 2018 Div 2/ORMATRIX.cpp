/*
ID: ishan_sang
PROG: ORMATRIX
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N,M;
	bool all_zeroes;
	cin>>T;
	for(int t = 0; t<T; t++)
	{	
		cin>>N>>M;
		all_zeroes = true;
		string A[N];
		int moves[N][M];
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<M; j++)
			{
				moves[i][j] = -5;
			}
		}
		bool row[N];
		bool col[M];
		for(int i = 0; i<N; i++)
		{
			row [i] = false;
		}
		for(int j = 0; j<M; j++)
		{
			col[j] = false;
		}
		for(int i = 0; i<N; i++)
		{
			cin>>A[i];
			for(int j = 0; j<M; j++)
			{
				if(A[i][j] == '1')
				{
					if(all_zeroes == true)
					{
						all_zeroes = false;
					}
					if(row[i] == false)
					{
						row[i] = true;
					}
					if(col[j] == false)
					{
						col[j] = true;
					}
					moves[i][j] = 0;
				}
			}
		}
		if(all_zeroes == true)
		{
			for(int i = 0; i<N; i++)
			{
				for(int j = 0; j<M; j++)
				{
					cout<<"-1 ";
				}
				cout<<"\n";
			}
		}
		else
		{
			for(int i = 0; i<N; i++)
			{
				for(int j = 0; j<M; j++)
				{
					if(moves[i][j] != 0)
					{
						if(row[i] == true || col[j] == true)
						{
							moves[i][j] = 1;
						} 
						else
						{
							moves[i][j] = 2;
						}
					}
				}
			}

			for(int i = 0; i<N; i++)
			{
				for(int j = 0; j<M; j++)
				{
					cout<<moves[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
	}
	return 0;
}