#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N, K;
		cin>>N>>K;
		int a = N-2, b = 2;
		string S = "";
		while(1)
		{
			if(a == 0)
			{
				while(b != 0)
				{
					S += 'b';
					b--;
				}
				break;
			}

			if(b == 0)
			{
				while(a != 0)
				{
					S += 'a';
					a--;
				}
				break;
			}

			int skip = (b == 2)?((a*(a+1))/2):a+b-1;

			if(K <= skip)
			{
				S += 'a';
				a--;
			}
			else
			{
				K -= skip;
				S += 'b';
				b--;
			}
		}
		cout<<S<<endl;
	}
	return 0;
}
