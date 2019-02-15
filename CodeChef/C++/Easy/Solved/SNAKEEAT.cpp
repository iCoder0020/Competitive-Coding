/*
ID: ishan_sang
PROG: SNAKEEAT
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX_SNAKES = 1e9;

#define int long long int

bool f(vector<int> &L, vector<int> &prefix, int K, int n, int index)
{
	int sz = L.size();
	int already_long = L.size() - index - 1;
	if(already_long >= n)
	{
		return true;
	}
	else
	{
		int a = prefix[index] - prefix[sz-n] + L[sz-n];
		if(K*(n-already_long)-a <= sz-n)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,Q,K;
		cin>>N>>Q;
		vector <int> L;
		vector <int> prefix;
		int sum = 0;
		int len;
		for(int n = 0; n<N; n++)
		{
			cin>>len;
			L.push_back(len);
		}
		sort(L.begin(), L.end());
		for(int n = 0; n<N; n++)
		{
			sum += L[n];
			prefix.push_back(sum);
		}

		for(int q = 0; q<Q; q++)
		{
			int min = 0;
			int max = N;
			int mid;
			cin>>K;

			auto it = lower_bound(L.begin(), L.end(), K);
			int index = it - L.begin() - 1;

			while(1)
			{
				mid = (min + max)/2;
				if(min == max)
				{
					cout<<mid<<endl;
					break;
				}
				else if(max - min == 1)
				{
					if(f(L,prefix,K,max,index))
					{
						cout<<max<<endl;
						break;
					}
					else
					{
						cout<<min<<endl;
						break;
					}
				}
				else if(f(L,prefix,K,mid,index))
				{
					min = mid;
				}
				else
				{
					max = mid-1;
				}
			}
		}
	}
	return 0;
}