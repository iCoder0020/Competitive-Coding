#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		string S;
		cin>>S;
		int N = S.length();
		int a = 0, b = 0;
		int moves = 0;
		for(int n = 0; n<N; n++)
		{
			if(S[n] == '0')
				a++;
			else
				b++;
		}
		if(a == 0 || b == 0)
		{
			cout<<moves<<endl;
			continue;
		}
		moves = min(a,b);
		vector<int>v0(N+1,0), v1(N+1,0);
		for(int n = N-1; n>=0 ;n--)
		{
			if(S[n] == '0')
			{
				v0[n] = v0[n+1]+1;
				v1[n] = v1[n+1];
			}
			else
			{
				v0[n] = v0[n+1];
				v1[n] = v1[n+1]+1;
			}
		}
		int c = 0, d = 0;
		for(int i = 0; i<N; i++)
		{
			if(S[i] == '0')
				d++;
			else
				c++;
			// cout<<c+v0[i]-1<<" "<<d+v1[i]-1<<endl;
			moves = min(moves, min(c+v0[i+1],d+v1[i+1]));
		}
		cout<<moves<<endl;
	}
	return 0;
}
