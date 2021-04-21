#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		bool odd[N];
		int A[N][N];
		for(int n = 0; n<N; n++)
		{
			for(int m = 0; m<N; m++)
			{
				cin>>A[n][m];
				if(n == 0)
				{
					odd[m] = false;
					if(A[0][m] != m+1)
						odd[m] = true;
				}
			}
		}
		int cnt = 0;
		for(int n = 2; n<N; n++)
			if(odd[n]!=odd[n-1])
				cnt++;
		if(odd[N-1])
			cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}