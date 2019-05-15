/*
ID: ishan_sang
PROG: ISSNAKE
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int N;
		cin>>N;
		int x,y;
		char A[2][N];
		bool visited [2][N];
		int parts = 0;
		for(int n = 0; n<2; n++)
		{
			for(int m = 0; m<N; m++)
			{
				cin>>A[n][m];
				visited[n][m] = false;
				if(A[n][m] == '#')
				{
					x = n;
					y = m;
					parts++;
				}
			}
		}
		queue<pair<int,int>>Q;
		int cnt = 1;
		Q.push({x,y});
		visited[x][y] = true;
		while(!Q.empty())
		{
			pair<int,int> temp = Q.front();
			int r = temp.first;
			int c = temp.second;
			if(r-1 >=0 && A[r-1][c] == '#' && !visited[r-1][c])
			{
				Q.push({r-1,c});
				visited[r-1][c] = true;
				cnt++;
			}
			if(c-1 >=0 && A[r][c-1] == '#' && !visited[r][c-1])
			{
				Q.push({r,c-1});
				visited[r][c-1] = true;
				cnt++;
			}
			if(r+1 <2 && A[r+1][c] == '#' && !visited[r+1][c])
			{
				Q.push({r+1,c});
				visited[r+1][c] = true;
				cnt++;
			}
			if(c+1 <N && A[r][c+1] == '#' && !visited[r][c+1])
			{
				Q.push({r,c+1});
				visited[r][c+1] = true;
				cnt++;
			}
			Q.pop();
		}
		bool possible = true;
		if(cnt == parts)
		{
			int count[2] = {0};
			set<pair<int,int>>S;
			for(int m = 0; m<N; m++)
			{
				if(A[0][m] == '.' && A[1][m] == '#')
				{
					count[0]++;
					S.insert({m,0});
				}
				else if(A[0][m] == '#' && A[1][m] == '.')
				{
					count[1]++;
					S.insert({m,1});
				}
			}
			if(count[0] + count[1] <= 1)
				cout<<"yes";
			else
			{
				pair<int,int> prev = {-1,-1};
				pair<int,int> current;
				for(auto it: S)
				{
					current = it;
					if(prev.first != -1)
					{
						if(prev.second == current.second && (current.first - prev.first)%2 == 0)
						{
							possible = false;
							break;
						}
						else if(prev.second != current.second && (current.first - prev.first)%2 == 1)
						{
							possible = false;
							break;
						}

					}
					prev = current;
				}
				if(possible)
					cout<<"yes";
				else
					cout<<"no";
			}	
		}
		else 
			cout<<"no";
		cout<<endl;
	}	
	return 0;
}