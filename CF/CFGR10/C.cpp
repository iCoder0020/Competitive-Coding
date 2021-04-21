#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e16
int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];
		vector<int>LGE(N,INF), RGE(N,INF);
		stack<int>S;
		int ans = 0;
		for(int n = 0; n<N; n++)
		{
			while(!S.empty() && S.top()<=A[n])
				S.pop();
			if(!S.empty())
				LGE[n] = S.top();
			S.push(A[n]);
		}
		while(!S.empty())
			S.pop();
		for(int n = N-1; n>=0; n--)
		{
			while(!S.empty() && S.top()<=A[n])
				S.pop();
			if(!S.empty())
				RGE[n] = S.top();
			S.push(A[n]);
		}
		for(int n = 0; n<N; n++)
		{
			// cout<<LGE[n]<<" "<<RGE[n]<<endl;
			if(LGE[n] == INF)
				continue;
			ans += min(LGE[n],RGE[n])-A[n];

		}
		cout<<ans<<endl;
	}
	return 0;
}
