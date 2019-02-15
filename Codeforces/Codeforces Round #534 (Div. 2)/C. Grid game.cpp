/*
ID: iCoder0020
PROG: Grid game
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>>S;
	bool grid[4][4];

	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			grid[i][j] = false;
		}
	}

	for(int n = 0; n<S.length(); n++)
	{
		
		for(int i = 0; i<4; i++)
		{
			for(int j = 0; j<4; j++)
			{
				if(grid[i][j] == false)
				{
					break;
				}
				if(j == 3)
				{
					for(int k = 0; k<4; k++)
					{
						grid[i][k] = false;
					}
				}
			}
		}

		if(S[n] == '0')
		{
			int j;
			for(j = 0; j<4; j++)
			{
				if(grid[0][j] == false)
				{
					grid[0][j] = true;
					grid[1][j] = true;
					break;
				}
			}
			cout<<1<<" "<<j+1<<endl;
		}	
		else
		{
			int i,j;
			bool got = false;
			for(i = 2; i<4; i++)
			{
				for(j = 0; j<4; j+=2)
				{
					if(grid[i][j] == false)
					{
						grid[i][j] = true;
						grid[i][j+1] = true;
						got = true;
						break;
					}
				}
				if(got)
				{
					got = false;
					break;
				}
			}
			cout<<i+1<<" "<<j+1<<endl;
		}
	}
	return 0;
}