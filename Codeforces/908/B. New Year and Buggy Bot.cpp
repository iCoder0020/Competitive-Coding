/*
ID: iCoder0020
PROG: New Year and Buggy Bot
LANG: C++                  
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int N, M;
	cin>>N>>M;
	char MAZE[N][M];
	int S_i, S_j, cur_i, cur_j;
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<M; j++)
		{
			cin>>MAZE[i][j];
			if(MAZE[i][j] == 'S')
			{
				S_i = i;
				S_j = j;
			}
		}
	}
	string s;
	cin>>s;
	int count = 0;
	char dirn[4] = {'0', '1', '2', '3'};
	char dirc[4] = {'l', 'r', 'u', 'd'}; 
	for(int n = 0; n<24; n++)
	{
		next_permutation(dirn, dirn+4);
		map< char, char >DIR;
		for(int i = 0; i<4; i++)
		{
			DIR[dirn[i]] = dirc[i];
		}
		cur_i = S_i;
		cur_j = S_j;
		for(int i = 0; i<s.length(); i++)
		{
			switch(DIR[s[i]])
			{
				case 'l':
					cur_j--;
					break;

				case 'r':
					cur_j++;
					break;

				case 'u':
					cur_i--;
					break;

				case 'd':
					cur_i++;
					break;

				default:
					break;
			}
			if(cur_i>N-1 || cur_j>M-1 || cur_i<0 || cur_j<0 || MAZE[cur_i][cur_j] == '#')
			{
				break;
			}	
			if(MAZE[cur_i][cur_j] == 'E')
			{
				count++;
				break;
			}
		}
	}
	cout<<count<<"\n";
	return 0;
}