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
		if(N < 2)
		{
			cout<<-1<<endl;
			continue;
		}
		string S = "";
		for(int n = 0; n<N-1; n++)
			S += '5';
		S+='4';
		cout<<S<<endl;
	}
	return 0;
}
