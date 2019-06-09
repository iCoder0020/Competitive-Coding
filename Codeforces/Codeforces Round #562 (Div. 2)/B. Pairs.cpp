/*
ID: iCoder0020
PROG: Pairs
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
	int N, M;	
	cin>>N>>M;

	int x1 = 0, x2 = 0, x3 = 0;
	pair<int, int> P[M];

	bool ans = true;

	for(int m = 0; m<M; m++)
	{
		int u,v;
		cin>>u>>v;
		P[m] = {u, v};
	}

	x1 = P[0].first;
	for(int m = 0; m<M; m++)
	{
		if(P[m].first != x1 && P[m].second != x1)
		{
			x2 = P[m].first;
			x3 = P[m].second;
			break;
		}
	}
	for(int m = 0; m<M; m++)
	{
		if(P[m].first != x1 && P[m].first != x2 && P[m].second != x1 && P[m].second != x2)
		{
			ans = false;
			break;
		}
	}
	if(!ans)
	{
		ans = true;
		for(int m = 0; m<M; m++)
		{
			if(P[m].first != x1 && P[m].first != x3 && P[m].second != x1 && P[m].second != x3)
			{
				ans = false;
				break;
			}
		}
	}
	if(!ans)
	{
		ans = true;
		x1 = P[0].second;
		for(int m = 0; m<M; m++)
		{
			if(P[m].first != x1 && P[m].second != x1)
			{
				x2 = P[m].first;
				x3 = P[m].second;
				break;
			}
		}
		for(int m = 0; m<M; m++)
		{
			if(P[m].first != x1 && P[m].first != x2 && P[m].second != x1 && P[m].second != x2)
			{
				ans = false;
				break;
			}
		}
		if(!ans)
		{
			ans = true;
			for(int m = 0; m<M; m++)
			{
				if(P[m].first != x1 && P[m].first != x3 && P[m].second != x1 && P[m].second != x3)
				{
					ans = false;
					break;
				}
			}
		}
	}	

	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}