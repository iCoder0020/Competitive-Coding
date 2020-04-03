#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,K;
		cin>>N>>K;
		vector<int>A;
		for(int n = 0; n<N; n++)
		{
			int y;
			cin>>y;
			if(y != 0)
				A.push_back(y);
		}
		N = A.size();
		if(N == 0)
		{
			cout<<"YES"<<endl;
			continue;
		}
		sort(A.begin(), A.end(), greater<int>());
		vector<int>powers;
		int x = 1;
		while(x <= A[0])
		{
			powers.push_back(x);
			x *= K;
		}

		int i = 0;
		int j;

		vector<vector<int>>ans(N);

		while(i<N)
		{
			j = powers.size()-1;
			while(j >= 0 && (powers[j] == 0 || powers[j]>A[i]))
				j--;
			if(j<0)
				break;
			if(A[i] > 0)
			{
				A[i] -= powers[j];
				// ans[i].push_back(powers[j]);
				powers[j] = 0;
			}
			if(A[i] == 0)
				i++;
		}

		if(i == N)
		{
			cout<<"YES"<<endl;
			// for(auto it: ans)
			// {
			// 	for(auto jt: it)
			// 		cout<<jt<<" ";
			// 	cout<<endl;
			// }
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
