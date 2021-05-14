#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e6

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
		int l = -1, r = INF;
		for(int n = 0; n<N; n++)
		{
			if(S[n] == '0')
				l = n;
			else
				break;
		}
		for(int n = N-1; n>=0; n--)
		{
			if(S[n] == '1')
				r = n;
			else
				break;
		}
		// cout<<l<<" "<<r<<endl;
		if(l!=-1)
		{
			for(int i = 0; i<=l; i++)
				T += '0';	
		}
		if(l!=N-1 && r-l>1)
			T += '0';
		if(r!=INF)
		{
			for(int i = r; i<N; i++)
				T += '1';
		}
		cout<<T<<endl;
	}
	return 0;
}
