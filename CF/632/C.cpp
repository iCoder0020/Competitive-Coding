#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 10000000000000000

int32_t main()
{
	int N;
	cin>>N;
	vector<int>A(N);
	vector<pair<int,int>>prefix(N);
	for(int n = 0; n<N; n++)
		cin>>A[n];
	prefix[0] = {A[0], 0};
	for(int n = 1; n<N; n++)
		prefix[n] = {A[n]+prefix[n-1].first, n};
	vector<int>prefix_copy;
	for(auto it: prefix)
		prefix_copy.push_back(it.first);
	int cnt = 0;
	int total = ((N+1)*(N))/2;
	sort(prefix.begin(), prefix.end());
	vector<int>C,D;
	for(auto it: prefix)
		C.push_back(it.first);
	for(auto it: prefix)
		D.push_back(it.second);
	for(int i = 0; i<N; i++)
	{
		int k = (i==0)?0:(prefix_copy[i-1]);
		int n = lower_bound(C.begin(), C.end(), k)-C.begin();
		int m = lower_bound(D.begin()+n, D.end(), i+1)-D.begin();
		cout<<n<<" "<<m<<endl;
		if(m<N && n<N && C[m] == k)
			cnt += N-prefix[m].second;
	}
	cout<<total-cnt<<endl;
	return 0;
}
