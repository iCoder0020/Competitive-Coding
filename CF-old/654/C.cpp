#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e12

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int A,B,N,M;
		cin>>A>>B>>N>>M;
		bool poss = true;
		if(A+B < N+M)
			poss = false;
		if(min(A,B)<M)
			poss = false;
		if(poss)
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}
	return 0;
}