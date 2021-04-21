#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int X,prev;
	cin>>X;
	prev = X;
	int cnt = 0;
	for(int n = 1; n<N; n++)
	{
		cin>>X;
		if(X<prev)
			cnt += prev-X;
		prev = max(X,prev);
	}
	cout<<cnt<<endl;
	return 0;
}
