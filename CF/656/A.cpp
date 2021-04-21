#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int A[3];
		cin>>A[0]>>A[1]>>A[2];
		vector<int>v;
		for(int n = 0; n<3; n++)
		{
			v.push_back(A[n]);
			v.push_back(max(1LL,A[n]-1));
			v.push_back(min(1000000000LL,A[n]+1));
		}
		int N = v.size();
		int ans[3] = {0};
		for(int a = 0; a<N; a++)
		{
			for(int b = 0; b<N; b++)
			{
				for(int c = 0; c<N; c++)
				{
					if(max(v[a],v[b]) == A[0] && max(v[a],v[c]) == A[1] && max(v[b],v[c]) == A[2])
						ans[0] = v[a], ans[1] = v[b], ans[2] = v[c];
				}
			}
		}
		if(ans[0]==0)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			for(int n = 0; n<3; n++)
				cout<<ans[n]<<" ";
			cout<<endl;
		}
	}
	

	return 0;
}
