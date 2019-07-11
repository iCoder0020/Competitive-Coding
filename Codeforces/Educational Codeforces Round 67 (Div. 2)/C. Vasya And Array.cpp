/*
ID: iCoder0020
PROG: Vasya And Array
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,M;
	cin>>N>>M;
	int arr[N];
	for(int n = 0; n<N; n++)
		arr[n] = (n+1)*1000000;
	int type,l,r;
	vector<pair<int,int>>t1;
	vector<pair<int,int>>t2;
	bool poss = true;
	for(int i = 0; i<M; i++)
	{
		cin>>type>>l>>r;
		if(type == 1)
			t1.push_back({l,r});
		else
			t2.push_back({l,r});
	}
	for(auto it1: t1)
	{
		int l1 = it1.first, r1 = it1.second;
		for(auto it2: t2)
		{
			int l2 = it2.first, r2 = it2.second;
			if((l2>=l1 && l2<r1) || (r2>l1 && r2<=r1))
				poss = false;
		}
	}
	if(!poss)
		cout<<"NO"<<endl;
	else
	{
		int sz = t1.size();
		for(auto it: t2)
		{
			int l = it.first, r = it.second;
			bool got_it = false;
			for(int n = r; n>=l && !got_it; n--)
			{
				for(int m = 0; m<sz; m++)
				{
					if(n>t1[m].first && n<t1[m].second)
						break;
					if(m == sz-1)
						got_it = true;
				}
				if(got_it)
				{
					arr[n-1] = n;
					break; 
				}
			}
		}
		cout<<"YES"<<endl;
		for(int n = 0; n<N; n++)
			cout<<arr[n]<<" ";
		cout<<endl;
	}
	return 0;
}