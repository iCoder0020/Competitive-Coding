#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e18

int32_t main()
{
	int N;
	cin>>N;
	vector<int>A(N);
	vector<pair<int,int>>B(N);
	vector<int>prefix(N);
	int min_index = -1, min_value = INF;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(n == 0)
			prefix[n] = A[n];
		else
			prefix[n] = prefix[n-1]+A[n];
		if(n!=0 && n!=N-1 && A[n] < min_value)
		{
			min_value = A[n];
			min_index = n;
		}
	}
	if(min_index != -1)
	{
		int l = prefix[min_index] + (N-min_index-1)*min_value;
		int r = prefix[N-1] - prefix[min_index] + (min_index+1)*min_value;
		cout<<l<<" "<<r<<endl; 
	}
	for(auto it: A)
		cout<<it<<" ";
	cout<<endl;
	return 0;
}
