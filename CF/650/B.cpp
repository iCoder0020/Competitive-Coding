#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int A[N];
		int o,e;
		o = e = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(n%2 == 1)
			{
				if(A[n]%2 == 0)
					o++;
			}
			else
			{
				if(A[n]%2 == 1)
					e++;
			}
		}
		if(o != e)
			cout<<-1;
		else
			cout<<o;
		cout<<endl;
	}
	return 0;
}
