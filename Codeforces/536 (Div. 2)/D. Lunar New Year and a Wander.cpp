/*
ID: iCoder0020
PROG: Lunar New Year and a Wander
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N, M;
	cin>>N>>M;
	vector <int> adj_list[N+1];
	int a,b;
	for(int m = 0; m<M; m++)
	{
		cin>>a>>b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	vector<int> ans;
	ans.push_back(1);
	set <int> ver;
	bool first = true;
	bool visited[N+1];
	for(int n = 0; n<=N; n++)
	{
		visited[n] = false;
	}
	visited[1] = true;
	while(ans.size() != N)
	{
		if(first)
		{
			for(int n = 0; n<adj_list[1].size(); n++)
			{				
				if(visited[adj_list[1][n]] == false)
				{
					ver.insert(adj_list[1][n]);
					visited[adj_list[1][n]] = true;
				}
			}
			first = false;
		}
		else
		{
			auto it = ver.begin();
			ans.push_back(*it);
			
			for(int n = 0; n<adj_list[*it].size(); n++)
			{
				if(visited[adj_list[*it][n]] == false)
				{
					ver.insert(adj_list[*it][n]);
					visited[adj_list[*it][n]] = true;
				}
			}
			
			ver.erase(it);
		}

	}
	for(auto it: ans)
	{
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}