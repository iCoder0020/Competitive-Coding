/*
ID: iCoder0020
PROG: Badge
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> parent;
vector<bool> visited;

int bfs(int x)
{
	visited.clear();
	visited.resize(N+1, false);
	queue<int>Q;
	Q.push(x);
	visited[x] = true;
	while(!Q.empty())
	{
		int temp = Q.front();
		Q.pop();
		if(visited[parent[temp]] == true)
			return parent[temp];
		else
		{
			Q.push(parent[temp]);
			visited[parent[temp]] = true;
		}
	}
}

int main()
{
	cin>>N;
	parent.clear();
	parent.resize(N+1);
	for(int n = 1; n<=N; n++)
		cin>>parent[n];
	for(int n = 1; n<=N; n++)
		cout<<bfs(n)<<" ";
	cout<<endl;
	return 0;
}