/*
ID: iCoder0020
PROG: Hamburgers
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

bool bs(pair<int,int> ing[3], int rec[3], int num, int money)
{
	int m = 0;
	for(int i = 0; i<3; i++)
	{
		if(rec[i]*num > ing[i].first)
			m += (rec[i]*num-ing[i].first)*ing[i].second;
	}
	return (m<=money);
}

int32_t main()
{
	string recipe;
	pair<int,int> ing[3];
	int rec[3] = {0};
	int money;
	cin>>recipe;
	for(int i = 0; i<3; i++)
		cin>>ing[i].first;
	for(int i = 0; i<3; i++)
		cin>>ing[i].second;
	cin>>money;
	for(auto it: recipe)
	{
		if(it == 'B')
			rec[0]++;
		else if(it == 'S')
			rec[1]++;
		else
			rec[2]++;
	}
	int lo = 0, hi = 1e14, mid;
	while(lo<hi)
	{
		mid = lo + (hi-lo+1)/2;
		if(bs(ing, rec, mid, money))
			lo = mid;
		else
			hi = mid-1;
	}
	cout<<lo<<endl;
	return 0;
}