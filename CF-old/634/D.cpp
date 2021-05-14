#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N = 9;
		string S[9];
		string T[9];
		for(int n = 0; n<N; n++)
		{
			cin>>S[n];
			T[n] = S[n];
		}
		for(int n = 0; n<3; n++)
		{
			for(int m = 0; m<3; m++)
			{
				int i = 3*n+m;
				int j = 3*m+n;
				T[i][j] = T[3*n+1][3*m+1];
			}
		}	
		T[4][4] = T[4][5];
		for(int n = 0; n<N; n++)
			cout<<T[n]<<endl;	
	}
	return 0;
}
