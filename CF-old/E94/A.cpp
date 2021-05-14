#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		string S;
		cin>>S;
		string T = "";
		for(int n = 0; n<N; n++)
			T+=S[N-1];
		cout<<T<<endl;
	}
	return 0;
}
