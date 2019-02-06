/*
ID: iCoder0020
PROG: 118 - Mutant Flatworld Explorers
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

char turn_left(char dir)
{
	if(dir == 'N')
	{
		return 'W';
	}
	if(dir == 'W')
	{
		return 'S';
	}
	if(dir == 'S')
	{
		return 'E';
	}
	if(dir == 'E')
	{
		return 'N';
	}
}

char turn_right(char dir)
{
	if(dir == 'N')
	{
		return 'E';
	}
	if(dir == 'E')
	{
		return 'S';
	}
	if(dir == 'S')
	{
		return 'W';
	}
	if(dir == 'W')
	{
		return 'N';
	}
}

int main()
{
	int X_MIN, Y_MIN, X_MAX, Y_MAX;
	X_MIN = 0;
	Y_MIN = 0;
	cin>>X_MAX>>Y_MAX;
	bool scent[X_MAX+1][Y_MAX+1];
	for(int i = 0; i<=X_MAX; i++)
	{
		for(int j = 0; j<=Y_MAX; j++)
		{
			scent[i][j] = false;
		}
	}
	int x,y;
	char dir;
	while(cin>>x>>y>>dir)
	{
		string inst;
		cin>>inst;
		bool fallen = false;
		for(int n = 0; n<inst.length(); n++)
		{
			if(inst[n] == 'L')
			{
				dir = turn_left(dir);
			}
			else if(inst[n] == 'R')
			{
				dir = turn_right(dir);
			}
			else if(inst[n] == 'F')
			{
				if(dir == 'N')
				{
					if(y+1 > Y_MAX)
					{
						if(scent[x][y] == false)
						{
							fallen = true;
							scent[x][y] = true;
							break;
						}
					}
					else
					{
						y = y+1;
					}
				}
				if(dir == 'W')
				{
					if(x-1 < X_MIN)
					{
						if(scent[x][y] == false)
						{
							fallen = true;
							scent[x][y] = true;
							break;
						}
					}
					else
					{
						x = x-1;
					}
				}
				if(dir == 'S')
				{
					if(y-1 < Y_MIN)
					{
						if(scent[x][y] == false)
						{
							fallen = true;
							scent[x][y] = true;
							break;
						}
					}
					else
					{
						y = y-1;
					}
				}
				if(dir == 'E')
				{
					if(x+1 > X_MAX)
					{
						if(scent[x][y] == false)
						{
							fallen = true;
							scent[x][y] = true;
							break;
						}
					}
					else
					{
						x = x+1;
					}
				}
			}
		}
		if(fallen)
		{
			cout<<x<<" "<<y<<" "<<dir<<" LOST"<<endl;
		}
		else
		{
			cout<<x<<" "<<y<<" "<<dir<<endl;
		}
	}
	return 0;
}