#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		string S;
		cin>>S;
		int M;
		cin>>M;
		int A[M];
		for(int m = 0; m<M; m++)
			cin>>A[m];
		vector<int>lcount(26,0);
		for(auto it: S)
			lcount[it-'a']++;
		int z_total = 0;
		string ans;
		ans.resize(M);
		int maxm = 25;
		while(z_total<M)
		{
			vector<int>v;
			for(int m = 0; m<M; m++)
				if(A[m] == 0)
					v.push_back(m);
			
			int z = v.size();
			int start;
			for(int n = maxm; n>=0; n--)
			{
				if(lcount[n] >= z)
				{
					start = n;
					lcount[n]-=z;
					break;
				}
			}
			maxm = start-1;
			for(auto it: v)
			{
				for(int m = 0; m<M; m++)
				{
					if(A[m] == -1)
						continue;
					if(A[m] == 0)
					{
						ans[m] = 'a'+start;
						A[m] = -1;
					}
					else
						A[m] -= abs(m-it);
				}
			}
			
			z_total += z;
		}
		cout<<ans<<endl;
	}
	return 0;
}