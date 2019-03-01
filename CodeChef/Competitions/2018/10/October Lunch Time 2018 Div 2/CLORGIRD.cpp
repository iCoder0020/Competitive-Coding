/*
ID: ishan_sang
PROG: CLORGIRD
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int N,M;
		cin>>N>>M;
		char grid[N][M];
		bool possible;
		for(int n = 0; n<N; n++)
		{
			for(int m = 0; m<M; m++)
			{
				cin>>grid[n][m];
			}
		}
		for(int n = 0; n<N-1; n++)
		{
			for(int m = 0; m<M-1; m++)
			{
				if(grid[n][m]!='#' && grid[n][m+1]!='#' && grid[n+1][m]!='#' && grid[n+1][m+1]!='#')
				{
					grid[n][m] = 'c';
					grid[n][m+1] = 'c';
					grid[n+1][m] = 'c';
					grid[n+1][m+1] = 'c';
				}
			}
		}
		possible = true;
		for(int n = 0; n<N; n++)
		{
			for(int m = 0; m<M; m++)
			{
				if(grid[n][m] == '.')
				{
					possible = false;
					break;
				}
			}
			if(possible == false)
			{
				break;
			}
		}
		if(possible)
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