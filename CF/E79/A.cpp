#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int A[3];
		for(int i = 0; i<3; i++)
			cin>>A[i];
		sort(A, A+3);
		int x = A[0], y = A[1], z = A[2];
		if(z <= x+y+1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}

