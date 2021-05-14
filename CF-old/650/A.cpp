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
		string T="";
		T += S[0];
		for(int i = 1; i<S.length(); i+=2)
			T+=S[i];
		cout<<T<<endl;	
	}
	return 0;
}
