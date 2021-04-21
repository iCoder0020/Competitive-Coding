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
		int A[N+1];
		string S[N+1];
		A[0] = 0;
		for(int n = 1; n<=N; n++)
			cin>>A[n];
		S[0] = 'a';
		for(int n = 1; n<=N; n++)
		{
			int x = max(A[n], A[n-1])-S[n-1].length();
			char c = (char)('a'+(n)%26);
			if(x <= 0)
				x=1;
			string T(x, c);
			S[n-1] += T;
			if(A[n] == 0)
				S[n] = string(1,c);
			else
				S[n] = S[n-1].substr(0, A[n]);
		}
		for(int n = 0; n<=N; n++)
			cout<<S[n]<<endl;
	}
	return 0;
}
