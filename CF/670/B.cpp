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
		vector<int>pos1, pos2, neg1, neg2;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n]>=0)
			{
				pos1.push_back(A[n]);
				pos2.push_back(A[n]);
			}
			else
			{
				neg1.push_back(A[n]);
				neg2.push_back(A[n]);
			}
		}
		sort(A.begin(), A.end(), greater<int>());
		sort(pos1.begin(), pos1.end());
		sort(pos2.begin(), pos2.end(), greater<int>());
		sort(neg1.begin(), neg1.end());
		sort(neg2.begin(), neg2.end(), greater<int>());
		int ps = pos1.size(), ns = neg1.size();
		int ans = 1;
		for(int n = 0; n<5; n++)
			ans *= A[n];

		for(int i = 0; i<=min(ps,5LL); i++)
		{
			int j = min(ns, (5LL-i));
			if(i+j<5)
				continue;
			int curr1 = 1;
			for(int n = 0; n<i; n++)
				curr1 *= pos1[n];

			int curr2 = 1;
			for(int n = 0; n<i; n++)
				curr2 *= pos2[n];

			int curr3 = 1;
			for(int n = 0; n<j; n++)
				curr3 *= neg1[n];

			int curr4 = 1;
			for(int n = 0; n<j; n++)
				curr4 *= neg2[n];


			// cout<<i<<" "<<curr1<<" "<<curr2<<" "<<curr3<<" "<<curr4<<endl;
			ans = max({ans, curr1*curr3, curr1*curr4, curr2*curr3, curr2*curr4});
		}
		cout<<ans<<endl;
	}	
	return 0;
}
