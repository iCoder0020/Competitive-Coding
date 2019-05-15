/*
ID: iCoder0020
PROG: Serval and Toy Bricks
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N,M,H;
	cin>>N>>M>>H;
	int FV[M];
	int LV[N];
	int TV[N][M];
	int ans[N][M];
	for(int m = 0; m<M; m++)
		cin>>FV[m];
	for(int n = 0; n<N; n++)
		cin>>LV[n];
	for(int n = 0; n<N; n++)
	{
		for(int m = 0; m<M; m++)
		{
			ans[n][m] = 0;
			cin>>TV[n][m];
			if(TV[n][m] != 0)
				ans[n][m] = min(LV[n], FV[m]);
			cout<<ans[n][m]<<" ";
		}
		cout<<endl;
	}
	return 0;
}