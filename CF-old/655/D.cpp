#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>min_heap;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		min_heap.push({A[n], n});
	}
	unordered_map<int,int>left;
	unordered_map<int,int>right;
	for(int n = 0; n<N; n++)
	{
		left[n] = (n-1+N)%N;
		right[n] = (n+1)%N;
	}
	int cnt = N;
	vector<bool>gone(N,false);
	while(cnt>1)
	{
		pair<int,int>p = min_heap.top();
		min_heap.pop();
		int l,r,n;
		n = p.second;
		if(gone[n])
			continue;
		while(gone[left[n]])
			left[n] = left[left[n]];
		while(gone[right[n]])
			right[n] = right[right[n]];
		l = left[n];
		r = right[n];
		// cout<<A[n]<<" "<<A[l]<<" "<<A[r]<<endl;
		A[n] = A[l]+A[r];
		min_heap.push({A[n], n});
		gone[l] = gone[r] = true;
		A[l] = A[r] = -1;
		cnt-=2;
		while(gone[left[n]])
			left[n] = left[left[n]];
		while(gone[right[n]])
			right[n] = right[right[n]];
		// cout<<A[left[n]]<<" "<<A[right[n]]<<endl;
	}
	for(int n = 0; n<N; n++)
		if(A[n] != -1)
			cout<<A[n]<<endl;;
	return 0;
}