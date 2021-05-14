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
		int X = A, Y = A*(B-1), Z = A*B;
		if (X == Y)
		{
			Y = 2*A*B-A;
			Z = 2*A*B;
		}
		if(B == 1)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			cout<<X<<" "<<Y<<" "<<Z<<endl;	
		}
	}
	return 0;
}
