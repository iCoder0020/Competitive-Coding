/*
ID: iCoder0020
PROG: Queen
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

#define ff first
#define ss second

using namespace std;

int main()
{
	int N;
	cin>>N;

	pair<int, int> nodes[N+1];
	int root;
	set<int>children[N+1];
	set<int>safe;
	set<int>ans;
	for(int n = 1; n<=N; n++)
	{
		cin>>nodes[n].ff>>nodes[n].ss;
		if(nodes[n].ff != -1)
			children[nodes[n].ff].insert(n);
		else
			root = n;
	}

	queue<pair<int, int>> Q;
	Q.push({root, 0});
	map<int, vector<int>>M;
	int max_level = 0;
	while(!Q.empty())
	{
		int temp = Q.front().ff;
		int level  = Q.front().ss;
		Q.pop();

		M[level].push_back(temp);
		max_level = max(max_level, level);

		for(auto it: children[temp])
			Q.push({it,level+1});
	}

	for(int i = max_level; i>=0; i--)
	{
		for(auto it: M[i])
		{
			if(nodes[it].ss == 1)
			{
				if(i == max_level)
					ans.insert(it);
				else
				{
					if(safe.find(it) == safe.end())
						ans.insert(it);
				}
			}
			else
				safe.insert(nodes[it].ff);
		}
	}

	if(ans.size())
		for(auto it: ans)
			cout<<it<<" ";
	else
		cout<<-1;
	cout<<endl;
	return 0;
}