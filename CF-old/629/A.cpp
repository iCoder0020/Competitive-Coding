#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int A,B;
		cin>>A>>B;
		int moves;
		if(A<=B)
			moves = B-A;
		else if(A%B == 0)
			moves = 0;
		else
			moves = ((A/B)+1)*B-A;
		cout<<moves<<endl;
	}
	return 0;
}
