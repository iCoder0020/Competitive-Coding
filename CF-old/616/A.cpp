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
		int sum = 0;
		int x = -1;
		for(int n = 0; n<N; n++)
		{
			if ((S[n]-'0')%2 != 0 && x==-1)
				x = n;
			sum += (S[n]-'0');
		}
		int idx = N-1;
		while(idx>=0 && (S[idx]-'0')%2 == 0)
			idx--;

		// cout<<idx<<" "<<x<<" "<<sum<<endl;

		if(idx == -1)
			cout<<-1<<endl;
		else
		{
			if(sum%2 == 0)
			{
				string T = "";
				for(int n = 0; n<=idx; n++)
					T += S[n];
				cout<<T<<endl;
			}
			else
			{
				if(x!=-1 && x!=idx)
				{
					int j = x+1;
					if(x == 0)
					{
						while(j<=idx && (S[j]-'0') == 0)
							j++;
					}
					string T = "";
					for(int n = 0; n<=idx; n++)
					{
						if(n>=x && n<j)
							continue;
						T += S[n];
					}
					cout<<T<<endl;
				}
				else
				{
					cout<<-1<<endl;
				}
			}
		}
	}
	return 0;
}
