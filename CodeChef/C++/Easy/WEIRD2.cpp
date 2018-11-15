	/*
ID: ishan_sang
PROG: WEIRD2
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

bool sort_by_freq(pair<int,int> p1, pair<int,int> p2)
{
	return p1.second > p2.second;
}

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int N;
		cin>>N;
		int A[N];
		map <int,int> num_freq;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(num_freq.find(A[n]) == num_freq.end())
			{
				num_freq[A[n]] = 1;
			}
			else
			{
				num_freq[A[n]]++;
			}
		}
		sort(num_freq.begin(), num_freq.end(), sort_by_freq);
		int count = 0;
		for(map <int,int> :: iterator it = num_freq.begin(); it!=num_freq.end(); it++)
		{
			cout<<it->first<<" "<<it->second<<"\n";
		}
		cout<<count<<"\n";
	}	
	return 0;
}