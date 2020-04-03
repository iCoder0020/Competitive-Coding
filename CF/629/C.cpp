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
		char A[N], B[N], C[N];
		for(int n = 0; n<N; n++)
			cin>>C[n];
		bool got = false;
		for(int n = 0; n<N; n++)
		{
			if(C[n] == '0')
				A[n] = B[n] = '0';
			if(got)
			{
				if(C[n] == '1')
					A[n] = '0', B[n] = '1';
				if(C[n] == '2')
					A[n] = '0', B[n] = '2';
			}
			else
			{
				if(C[n] == '1')
				{
					A[n] = '1', B[n] = '0';
					got = true;
				}
				if(C[n] == '2')
					A[n] = '1', B[n] = '1';
			}
		}
		for(int n = 0; n<N; n++)
			cout<<A[n];
		cout<<endl;
		for(int n = 0; n<N; n++)
			cout<<B[n];
		cout<<endl;
	}
	return 0;
}
