/*
ID: ishan_sang
PROG: PUMPWAT
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
		int ans = 0;
		bool inc;

		cin>>N;
		long long int H[N];
		for(int n = 0; n<N; n++)
		{
			cin>>H[n];
		}

		long long int max = 0;

		max = H[0];

		for(int n = 1; n<N; n++)
		{
			if(H[n] - H[n-1]>0 && H[n]>max)
			{
				max = H[n];
				ans++;
			}
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}