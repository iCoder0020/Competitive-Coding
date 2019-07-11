/*
ID: iCoder0020
PROG: Extra Element
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	vector<pair<int,int>> v;
	int temp;
	int diff[N] = {0};
	int diff2[N] = {0};
	int zero = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>temp;
		v.push_back({temp, n+1});
	}
	if(N <= 3)
	{
		cout<<1<<endl;
	}
	else
	{
		sort(v.begin(), v.end());
		int d = v[2].first-v[1].first;
		int n;
		for(n = 3; n<N; n++)
			if(v[n].first - v[n-1].first != d)
				break;
		if(n == N)
			cout<<v[0].second<<endl;
		else
		{
			d = v[N-2].first-v[N-3].first;
			for(n = N-3; n>0; n--)
				if(v[n].first-v[n-1].first != d)
					break;
			if(n == 0)
				cout<<v[N-1].second<<endl;
			else
			{
				for(int n = 1; n<N; n++)
				{
					diff[n] = v[n].first - v[n-1].first;
				}
				for(int n = N-2; n>=0; n--)
				{
					diff2[n] = v[n+1].first - v[n].first;
				}
				d = v[1].first - v[0].first;
				bool once = false;
				bool poss = true;
				int idx = -1;
				for(int n = 1; n<N; n++)
				{
					if(diff[n] != d)
					{
						if(!once)
						{
							once = true;
							idx = n;
							if(n+1 < N)
								diff[n+1] = v[n+1].first - v[n-1].first;
						}
						else
						{
							poss = false;
							break;
						}
					}
				}
				if(poss)
				{
					if(idx == -1)
						cout<<1<<endl;
					else
					{
						// cout<<idx<<endl;
						for(int i = max(zero,idx-1); i<=min(N-1,idx+1); i++)
						{
							int l = max(zero, i-1);
							int m = i;
							int r = min(N-1, i+1);
							// cout<<v[l].first<<" "<<v[m].first<<" "<<v[r].first<<endl;
							if(l<m && m<r)
							{
								if(v[m].first-v[l].first != d && v[r].first-v[m].first != d)
								{
									idx = v[m].second;
									break;
								}
							}
						}
						cout<<idx<<endl;
					}
				}
				else
				{
					d = v[N-1].first - v[N-2].first;
					once = false;
					poss = true;
					idx = -1;
					for(int n = N-2; n>=0; n--)
					{
						// cout<<v[n+1].first<<" "<<v[n].first<<diff2[n]<<endl;
						if(diff2[n] != d)
						{
							if(!once)
							{
								once = true;
								idx = n;
								if(n-1>=0)
									diff2[n-1] = v[n+1].first - v[n-1].first;
							}
							else
							{
								poss = false;
								break;
							}
						}
					}
					if(poss)
					{
						if(idx == -1)
							cout<<1<<endl;
						else
						{
							for(int i = max(zero,idx-1); i<=min(N-1,idx+1); i++)
							{
								int l = max(zero, i-1);
								int m = i;
								int r = min(N-1, i+1);

								if(l<m && m<r)
								{
									if(v[m].first-v[l].first != d && v[r].first-v[m].first != d)
									{
										idx = v[m].second;
										break;
									}
								}
							}
							cout<<idx<<endl;
						}
					}
					else
					{
						cout<<-1<<endl;
					}
				}
			}
		}
	}
	return 0; 
}