/*
ID: ishan_sang
PROG: TREEWLK2
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int N;
		cin>>N;
		int A[N];
		int freq[1000005]={0};
		vector <vector<int>> freq2(1000005);
		int count = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			freq[A[n]-1]++;
		}
		for(int n = 0; n<N; n++)
		{
			freq2[freq[A[n]-1]].push_back(A[n]);
		}
		for(int n = 0; n<1000005; n++)
		{
			if(freq2[n].size()!=0)
			{
				for(int m = 0; m<freq2[n].size(); m++)
				{
					if(freq[freq2[n][m]-1] >= n && freq2[n][m] <= n)
					{
						count++;
					}
				}
			}
		}
		cout<<count<<"\n";
	}	
	return 0;
}