/*
ID: iCoder0020
PROG: Coloring a Tree
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

vector<int>parent;
vector<int>color;
vector<int>final_color;
vector<vector<int>>children;

int moves;

void bfs()
{
	moves = 1;
	color[1] = final_color[1];

	queue<int>Q;
	Q.push(1);

	while(!Q.empty())
	{
		int temp = Q.front();
		Q.pop();
		for(auto it: children[temp])
		{
			int par = parent[it];
			if(final_color[it] != color[par])
				moves++;
			color[it] = final_color[it];
			Q.push(it);
		}
	}
}

int main()
{
	int N;
	cin>>N;

	parent.clear();
	parent.resize(N+1, -1);
	color.clear();
	color.resize(N+1, 0);
	final_color.clear();
	final_color.resize(N+1);
	children.clear();
	children.resize(N+1);
	
	for(int i = 2; i<=N; i++)
	{
		int p;
		cin>>p;
		children[p].push_back(i);
		parent[i] = p;
	}

	for(int i = 1; i<=N; i++)
	{
		int c;
		cin>>c;
		final_color[i] = c;
	}

	bfs();

	cout<<moves<<endl;

	return 0;
}