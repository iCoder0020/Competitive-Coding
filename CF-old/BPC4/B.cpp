#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC = 10;
	srand(time(NULL));
	while(TC--)
	{
		int N = 0,K = 0;
		N = rand()%10 + 5;
		K = rand()%21 - 10;
		cout<<N<<" "<<K<<endl;
		for(int n = 1; n<=N; n++)
		{
			int x = rand()%21 - 10;
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}
