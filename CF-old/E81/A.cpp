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
		int k = 0;
		if(N%2 == 1)
		{
			k = 3;
			cout<<"7";
		}
		for(int n = 0; n<(N-k)/2; n++)
			cout<<"1";
		cout<<endl;
	}
	return 0;
}

