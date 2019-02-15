/*
ID: iCoder0020
PROG: Connect Three
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x,y;
	vector<pair<int,int>>plots;
	for(int i = 0; i<3; i++)
	{
		cin>>x>>y;
		plots.push_back(make_pair(x,y));
	}
	sort(plots.begin(), plots.end());
	set<pair<int,int>> S;

	for(int i = 0; i<3; i++)
	{
		int plot1y = plots[i].second;
		int plot2y = plots[(i+1)%3].second;

		for(int i = min(plot1y, plot2y); i<=max(plot1y, plot2y); i++)
		{
			S.insert(make_pair(plots[1].first, i));
		}
	}

	for(int i = plots[0].first; i<=plots[1].first; i++)
	{
		S.insert(make_pair(i, plots[0].second));
	}

	for(int i = plots[1].first; i<=plots[2].first; i++)
	{
		S.insert(make_pair(i, plots[2].second));
	}

	cout<<S.size()<<endl;
	for(auto it = S.begin(); it!=S.end(); it++)
	{
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	return 0;
}