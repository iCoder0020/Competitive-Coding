/*
ID: iCoder0020
PROG: Diverse Strings
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		string S;
		cin>>S;
		sort(S.begin(), S.end());
		bool diverse = true;
		for(int n = 1; n<S.length(); n++)
		{
			if(S[n] - S[n-1] != 1)
				diverse = false;
		}
		if(diverse)
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}
	return 0;
}