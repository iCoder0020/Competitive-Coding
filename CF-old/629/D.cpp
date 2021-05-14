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
		int A[N];
		bool allsame = true;
		bool pair = false;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(n>0)
			{
				if(A[n]!=A[n-1])
					allsame = false;
				else
					pair = true;
			}
		}
		if(allsame)
		{
			cout<<"1"<<endl;
			for(int n = 0; n<N; n++)
				cout<<"1 ";
			cout<<endl;
		}
		else if(N%2 == 0 || A[0] == A[N-1])
		{
			cout<<"2"<<endl;
			for(int n = 0; n<N; n++)
				cout<<(n%2+1)<<" ";
			cout<<endl;
		}
		else
		{
			int ans[N] = {0};
			ans[0] = 1;
			int k = 2;
			for(int n = 1; n<N; n++)
			{
				if(A[n] == A[n-1])
					ans[n] = ans[n-1];
				else
				{
					for(int c = 1; c<=3; c++)
					{
						if(ans[n-1] != c)
						{
							if(n == N-1 && c == 1)
								continue;
							ans[n] = c;
							break;
						}
					}
				}
				k = max(k, ans[n]);
			}
			if(k == 3 && pair)
			{
				k = 2;
				int idx;
				for(int n = 1; n<N; n++)
				{
					if(A[n] == A[n-1])
					{
						idx = n;
						ans[n] = 3-ans[n];
						break;
					}
				}
				for(int n = idx+1; n<N; n++)
				{
					if(A[n] == A[n-1])
						ans[n] = ans[n-1];
					else
					{
						for(int c = 1; c<=2; c++)
						{
							if(ans[n-1] != c)
							{
								if(n == N-1 && c == 1)
									continue;
								ans[n] = c;
								break;
							}
						}
					}
				}
			}
			cout<<k<<endl;
			for(int n = 0; n<N; n++)
				cout<<ans[n]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
