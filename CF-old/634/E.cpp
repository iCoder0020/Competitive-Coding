#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX 27
int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int A[N];
		vector<vector<int>>prefix(N, vector<int>(MAX,0));
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			for(int k = 0; k<MAX; k++)
			{
				if(n>0)
					prefix[n][k] = prefix[n-1][k];
			}
			prefix[n][A[n]]++;
		}
		int ans = 0;

		for(int k = 0; k<MAX; k++)
			ans = max(ans, prefix[N-1][k]);

		int x = 0, curr;
		for(int i = 0; i<N-1; i++)
		{
			curr = 0;
			for(int j = i+1; j<N; j++)
			{
				int s, num = -1, maxs = -1;
				for(int k = 1; k<MAX; k++)
				{
					int l = 0, r = 0;
					if(i>0)
						l=prefix[i-1][k];
					if(j<N-1)
						r=prefix[N-1][k] - prefix[j][k];
					if(l == 0 || r == 0)
					{
						continue;
					}
					s = l+r;
					if(maxs < s)
					{
						num = k;
						maxs = s;
					}
					if(maxs == s)
					{
						int r1 = (i==0)?0:prefix[i-1][num];
						int r2 = (i==0)?0:prefix[i-1][k];
						if(prefix[j][num] - r1 > prefix[j][k] - r2)
							num = k;
					}
				}
				if(maxs == -1)
					continue;
				for(int k = 1; k<MAX; k++)
				{
					curr = maxs;
					if(k != num)
					{
						int r1 = (i==0)?0:prefix[i-1][k];
						curr += prefix[j][k] - r1;
						x = max(x, curr);
					}
				}
			}
		}
		cout<<max({ans,x})<<endl;
	}	
	return 0;
}
