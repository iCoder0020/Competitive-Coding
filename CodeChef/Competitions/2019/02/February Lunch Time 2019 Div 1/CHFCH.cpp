/*
ID: ishan_sang
PROG: CHFCH
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
	int T;
	cin>>T;	
	for(int t = 0; t<T; t++)
	{
		int N,K;
		cin>>N>>K;
		int A[N];
		map<int, vector<int>> M;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			M[A[n]].push_back(n);		
		}
		int swaps;
		int min_swaps = -1;

		int num = -1;
		int index;
		int min_diff = INT_MAX;

		for(auto it: M)
		{
			if(it.second.size() >= K)
			{
				for(int i = 0; i<=it.second.size()-K; i++)
				{
					if(it.second[i+K-1] - it.second[i] < min_diff)
					{
						min_diff = it.second[i+K-1] - it.second[i];
						num = it.first;
						index = i;
					}
				}
			}
		}

		auto it = M.find(num);
		if(it != M.end())
		{
			for(int i = index; i<index+K; i++)
			{
				swaps = 0;
				int k = 1;
				for(int j = i-1; j>=index; j--)
				{
					swaps += (*it).second[i] - (*it).second[j] - k;
					k++;
				}
				k = 1;
				for(int j = i+1; j<index+K; j++)
				{
					swaps += (*it).second[j] - (*it).second[i] - k;
					k++;
				}
				if(min_swaps == -1)
				{
					min_swaps = swaps;
				}
				else
				{
					min_swaps = min(min_swaps, swaps);
				}
			}
		}
		cout<<min_swaps<<endl;
	}
	return 0;
}