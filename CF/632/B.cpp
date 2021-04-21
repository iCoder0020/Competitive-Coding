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
		int A[N], B[N];
		for(int n = 0; n<N; n++)
			cin>>A[n];		
		for(int n = 0; n<N; n++)
			cin>>B[n];
		if(A[0] != B[0])
		{
			cout<<"NO\n";
			continue;
		}
		vector<pair<bool,bool>>got(N, {false,false});
		for(int n = 0; n<N; n++)
		{
			if(A[n] == -1)
				got[n].first = true;
			if(A[n] == 1)
				got[n].second = true;
			if(n!= 0)
			{
				got[n].first = (got[n].first || got[n-1].first);
				got[n].second = (got[n].second || got[n-1].second);
			}
		}
		bool poss = true;
		for(int n = N-1; n>0; n--)
		{
			if(A[n]<B[n] && got[n-1].second == false)
			{
				poss = false;
				break;
			}
			if(A[n]>B[n] && got[n-1].first == false)
			{
				poss = false;
				break;
			}
		}
		if(poss)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
