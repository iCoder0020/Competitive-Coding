#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n];
		bool poss = true;
		while(poss)
		{
			int prev = 0;
			int curr = N+1;
			vector<int>x;
			for(int n = 0; n<A.size(); n++)
			{
				// cout<<A[n]<<" ";
				if(n == 0 || A[n]>A[n-1])
				{
					if(A[n]>prev)
						curr = min(curr, A[n]);
				}
				else if(A[n]<A[n-1])
				{
					prev = curr;
					x.push_back(curr);
					curr = N+1;
				}
				if(n == A.size()-1)
				{
					curr = min(curr, A[n]);
					x.push_back(curr);
				}
			}
			// for(auto it: x)
			// 	cout<<it<<" ";
			// cout<<endl;
			if(x.size() == 1)
				break;
			if(A.size() == x.size())
				poss = false;
			else
				A = x;
		}
		if(poss)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
