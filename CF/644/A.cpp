#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int A,B;
		cin>>A>>B;
		if(A>B)
			swap(A,B);
		if(2*A>=B)
			cout<<4*A*A<<endl;
		else
			cout<<B*B<<endl;
	}
	return 0;
}
