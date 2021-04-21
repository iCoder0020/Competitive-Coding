#include <bits/stdc++.h>

using namespace std;

// #define int long long
// #define MOD 1000000007

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int sz = max(1,N/2);
		cout<<sz<<"\n";
		for(int i = 1; i<=sz; i++)
		{
			int cnt = 0;
			int a = 2*i;
			int b = 2*i + 1;
			if(i == 1)
				cnt++;
			if(a <= N)
				cnt++;
			if(b <= N)
				cnt++;

			cout<<cnt<<" ";

			if(i == 1)
				cout<<1<<" ";
			if(a <= N)
			{
				if(b <= N)
					cout<<a<<" "<<b;
				else
					cout<<a;
			}
			cout<<"\n";
		}
	}
	return 0;
}