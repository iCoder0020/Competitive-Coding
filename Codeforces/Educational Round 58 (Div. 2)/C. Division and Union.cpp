/*
ID: iCoder0020
PROG: Division and Union
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)
{
	if(a.first.first == b.first.first)
	{
		return a.first.second<b.first.second;
	}
	else
	{
		return a.first.first<b.first.first;
	}
}

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int N;
		cin>>N;
		bool possible = true;
		pair<pair<int,int>, int> segments[N];
		for(int n = 0; n<N; n++)
		{
			cin>>segments[n].first.first>>segments[n].first.second;
			segments[n].second = n;
		}
		sort(segments, segments+N, comp);
		int rt = segments[0].first.second;
		int index = -1;
		for(int n = 1; n<N; n++)
		{
			if(rt < segments[n].first.first)
			{
				index = n;
				break;
			}
			rt = max(rt, segments[n].first.second);
		}
		if(index == -1)
		{
			cout<<"-1";
		}	
		else
		{
			int ans[N] = {0};
			for(int n = 0; n<index; n++)
			{
				ans[segments[n].second] = 1;
			}
			for(int n = 0; n<N; n++)
			{
				cout<<2-ans[n]<<" ";
			}
		}
		cout<<endl;
	}	
	return 0;
}