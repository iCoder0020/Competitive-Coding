#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int K;
	cin>>K;
	int A[3][4];
	int x = 1LL<<17;
	int y = (1LL<<18)-1;
	for(int i = 0; i<3; i++)
		for(int j = 0; j<4; j++)
			A[i][j] = 0;
	A[0][0] = A[0][1] = A[0][2] = A[2][2] = y;
	A[1][0] = A[2][0] = A[2][1] = x;
	A[1][2] = A[2][3] = K;
	cout<<3<<" "<<4<<endl;
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<4; j++)
			cout<<A[i][j]<<" " ;
		cout<<endl;
	}
	return 0;
}
