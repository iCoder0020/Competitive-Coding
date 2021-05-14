#include <bits/stdc++.h>

using namespace std;

#define int long long

set<int>VALUES;

int ans = 0;
int N,M;

void recurse(vector<int>&A, int i, int r, int sum, int type)
{
	if(i == r)
	{
		int x = sum%M;
		if(type == 1)
		{
			VALUES.insert(sum%M);
			ans = max(ans, x);
		}
		if(type == 2)
		{
			int find = (M-x)%M;
			set<int>::iterator it = VALUES.lower_bound(find);
			int y1 = 0, y2 = 0;
			if(it!=VALUES.end())
				y1 = *it;
			if(it!=VALUES.begin())
				y2 = *(--it);
			ans = max({ans,x,(x+y1)%M,(x+y2)%M});
		}
		return;
	}
	recurse(A,i+1,r,sum,type);
	sum += A[i];
	recurse(A,i+1,r,sum,type);
}

int32_t main()
{
	cin>>N>>M;
	vector<int>A(N);
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		A[n] = A[n]%M;
	}
	recurse(A,0,N/2,0,1);
	recurse(A,N/2,N,0,2);
	cout<<ans<<endl;
	return 0;
}
