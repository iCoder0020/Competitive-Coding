#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		string S;
		cin>>S;
		vector<bool> seen(26, false);
		bool poss = true;
		for(int n = 0; n<N; n++)
		{
			if(seen[S[n]-'A'])
				poss = false;
			if(n+1<N && S[n+1] != S[n])
				seen[S[n]-'A'] = true;
		}
		if(poss)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
