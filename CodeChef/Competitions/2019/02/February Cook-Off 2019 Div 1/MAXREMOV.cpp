/*
ID: ishan_sang
PROG: MAXREMOV
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int num_cakes = 100000;

#define lb(arr, a) lower_bound(arr.begin(), arr.end(), a) - arr.begin()
#define ub(arr, a) upper_bound(arr.begin(), arr.end(), a) - arr.begin()

int main()
{
	int T;
	cin>>T;
	int N,K;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>K;
		int cake_height[num_cakes] = {0};
		int range[N][2];
		vector<int>index_remove;
		vector<int>index_keep;
		for(int n = 0; n<N; n++)
		{
			int l,r;
			cin>>l>>r;
			range[n][0] = l;
			range[n][1] = r;

			cake_height[l-1]++;
			if(r < num_cakes)
			{
				cake_height[r]--;
			}
		}
		int prev_count = 0;
		for(int n = 0; n<num_cakes; n++)
		{
			if(n>0)
			{
				cake_height[n] += cake_height[n-1];
			}
			if(cake_height[n] == K+1)
			{
				index_remove.push_back(n);
			}
			else if(cake_height[n] == K)
			{
				index_keep.push_back(n);
				prev_count++;
			}
		}	
		int count ;
		int max_count = -1*INT_MAX;
		for(int n = 0; n<N; n++)
		{
			count = 0;
			int l = range[n][0]-1;
			int r = range[n][1]-1;

			// cout<<l<<" "<<r<<endl;

			int a = lb(index_remove, r);
			int b = lb(index_remove, l);
			int c = ub(index_remove, r);
			int d = ub(index_remove, l);

			int e = lb(index_keep, r);
			int f = lb(index_keep, l);
			int g = ub(index_keep, r);
			int h = ub(index_keep, l);

			// cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
			// cout<<e<<" "<<f<<" "<<g<<" "<<h<<endl;
			// cout<<count<<endl;

			count += c-b;
			count -= g-f;

			if(count > max_count)
			{
				max_count = count;
			}
		}
		cout<<prev_count + max_count<<endl;
	}
	return 0;
}