#include <bits/stdc++.h>

using namespace std;

#define int long long

int count(string S, int N)
{
	int x = 0;
	string T = "abacaba";
	for(int i = 0; i<=N-7; i++)
		if(S.substr(i,7) == T)
			x++;
	return x;
}

int diff(string S, string T)
{
	int x = 0;
	for(int n = 0; n<S.length(); n++)
		if(S[n]!=T[n])
			x++;
	return x;
}	

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
		int x = count(S,N);
		if(x >= 2)
			cout<<"NO"<<endl;
		else if(x == 1)
		{
			cout<<"YES"<<endl;
			for(int i = 0; i<N; i++)
				if(S[i] == '?')
					S[i] = 'x';
			cout<<S<<endl;
		}
		else
		{
			string ans = "";
			string T = "abacaba";
			for(int i = 0; i<=N-7; i++)
			{
				string A = S.substr(0, i);
				string B = S.substr(i,7);
				string C = S.substr(i+7,N-i-6);
				for(int n = 0; n<7; n++)
				{
					if(T[n] == B[n])
						continue;
					else
					{
						if(B[n] == '?')
							B[n] = T[n];
						else
							break;
					}
				}
				if(B== T)
				{
					for(auto &it: A)
						if(it == '?')
							it = 'x';
					for(auto &it: C)
						if(it == '?')
							it = 'x';
					if(count(A+B+C,N) == 1)
						ans = A+B+C;
				}

			}
			if(ans.length())
			{
				cout<<"YES"<<endl;
				cout<<ans<<endl;
			}
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}
