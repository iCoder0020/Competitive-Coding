#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	map<int,vector<int>>MAP;
	map<int,int>IDX;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		MAP[A[n]].push_back(n);
		IDX[A[n]] = 0;
	}
	int left = 0;
	for(int n = 0; n<N; n++)
	{
		if(n<left)
			n = left;
		// cout<<n<<endl;
		while(n>=MAP[A[n]][IDX[A[n]]])
			IDX[A[n]]++;
		int i = IDX[A[n]];
		int sz = MAP[A[n]].size();
		if(i<sz)
		{
			int j = n;
			int k = MAP[A[n]][i];
			int j0 = j;
			int k0 = k;
			// cout<<j<<" "<<k<<endl; 
			while(j<k0 && k<N && A[j] == A[k])
			{
				j++;
				k++;
			}
			if(j == k0)
			{
				left = k0;
			}
		}
	}
	cout<<N-left<<endl;
	for(int i = left; i<N; i++)
		cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}
