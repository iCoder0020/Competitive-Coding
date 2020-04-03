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
		map<int,vector<int>>M;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			for(int m = 2; m*m<=A[n]; m++)
			{
				if(A[n]%m == 0)
				{					
					M[m].push_back(n);
					break;
				}
			}
		}
		int k = 1;
		int ans[N] = {0};
		for(auto it: M)
		{
			bool used = false;
			for(auto jt: it.second)
			{
				// cout<<it.first<<" "<<A[jt]<<endl;
				if(ans[jt] == 0)
				{
					used = true;
					ans[jt] = k;
				}
			}
			if(used)
				k++;
		}
		cout<<k-1<<endl;
		for(int n = 0; n<N; n++)
			cout<<ans[n]<<" ";
		cout<<endl;
	}
	return 0;
}
