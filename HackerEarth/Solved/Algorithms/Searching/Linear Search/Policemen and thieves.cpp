/*
ID: icoder_0020
PROG: Policemen and thieves
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int T,N,K;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>K;
		int caught = 0;
		char grid[N][N];
		vector <int> police_index [N];
		vector <int> thief_index [N];
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<N; j++)
			{
				cin>>grid[i][j];
				if(grid[i][j] == 'P')
				{
					police_index[i].push_back(j);
				}
				if(grid[i][j] == 'T')
				{
					thief_index[i].push_back(j);
				}
			} 
		}
		for(int i = 0; i<N; i++)
		{
			int l = 0;
			int r = 0;
			while(l!=police_index[i].size() && r!=thief_index[i].size())
			{
				if(abs(police_index[i][l] - thief_index[i][r]) <= K)
				{
					caught++;
					l++;
					r++;
				}
				else if(police_index[i][l] < thief_index[i][r])
				{
					l++;
				}
				else
				{
					r++;
				}
			}
		}
		cout<<caught<<endl;
	}
	return 0;
}
