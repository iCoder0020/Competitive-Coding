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
		for(int i = 2; i<62; i++)
		{
			int s = (1LL<<i);
			s--;
			if(N%s == 0)
			{
				cout<<N/s<<endl;
				break;
			}
		}
	}
	return 0;
}
