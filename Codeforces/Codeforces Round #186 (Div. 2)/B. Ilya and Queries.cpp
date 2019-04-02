/*
ID: iCoder0020
PROG: Ilya and Queries
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>>S;
	int N = S.length();
	int M;
	cin>>M;
	int ans[N] = {0};
	for(int n = 0; n<N-1; n++)
	{
		ans[n+1] = ans[n];
		if(S[n] == S[n+1])
		{
			ans[n+1]++;
		}
	}
	while(M--)
	{
		int L,R;
		cin>>L>>R;
		cout<<ans[R-1] - ans[L-1]<<endl;
	}
	return 0;
}