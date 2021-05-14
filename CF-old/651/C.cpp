#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e5

int32_t main()
{
	int TC;
	cin>>TC;
	vector<int>pow2(32, 1);
	for(int n = 1; n<32; n++)
		pow2[n] = pow2[n-1]*2;
	while(TC--)
	{
		int N;
		cin>>N;
		int move = 0;
		while(N>1)
		{			
			move++;
			if(N&1)
				N = 1;
			else
			{
				bool p2 = false;
				for(int n = 0; n<32; n++)
				{
					if(N == pow2[n])
					{
						N = N-1;
						p2 = true;
						break;
					}
				}
				if(p2)
					continue;
				if(N%4 == 0)
					N = 1;
				else
				{
					int M = N/2;
					bool y = false;
					for(int i = 3; i*i<=M; i+=2)
						if(M%i == 0)
							y = true;
					if(y)
						N = 1;
					else
						N = 2;
				}
			}
		}
		if(move&1)
			cout<<"Ashishgup";
		else
			cout<<"FastestFinger";
		cout<<endl;
	}
	return 0;
}