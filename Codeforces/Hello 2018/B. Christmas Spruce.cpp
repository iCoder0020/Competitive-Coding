/*
ID: iCoder0020
PROG: Christmas Spruce
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<int> adj_list[N+1];
	set<int>leaf_nodes;
	int temp;
	bool possible = true;
	for(int n = 2; n<=N; n++)
	{
		cin>>temp;
		adj_list[temp].push_back(n);
	}
	for(int n = 1; n<=N; n++)
	{
		if(adj_list[n].size() == 0)
		{
			leaf_nodes.insert(n);
		}
	}
	for(int n = 1; n<=N; n++)
	{
		auto it = leaf_nodes.find(n);
		if(it == leaf_nodes.end())
		{
			int count = 0;
			for(auto it1: adj_list[n])
			{
				auto it2 = leaf_nodes.find(it1);
				if(it2 != leaf_nodes.end())
				{
					count++;
				}
				if(count == 3)
				{
					break;
				}
			}
			if(count<3)
			{
				possible = false;
			}
		}
		if(!possible)
		{
			break;
		}
	}
	if(possible)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	cout<<endl;
	return 0;
}