#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,A,B;
		cin>>N>>A>>B;
		string S;
		for(int n = 0; n<A-B+1;n++)
			S+='a';
		for(int n = A-B+1; n<A; n++)
			S+=(char)('b' + (n-A+B-1));	
		for(int n = 0; n<N; n++)
			cout<<S[n%A];
		cout<<endl;
	}
	return 0;
}
