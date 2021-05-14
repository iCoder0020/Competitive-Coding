#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	if(N == 1)
	{
		cout<<7<<endl;
		for(int n = 0; n<=N; n++)
			cout<<0<<" "<<n<<endl;
		for(int n = 0; n<=N+1; n++)
			cout<<1<<" "<<n<<endl;
		for(int n = 1; n<=N+1; n++)
			cout<<2<<" "<<n<<endl;
	}
	else
	{
		int up = ((N-1)/2)+1;
		int down = (N/2)+1;
		cout<<5*(up+down) + 2*N+3<<endl;
		for(int i = 0; i<down; i++)
		{
			for(int j = i*4; j<=i*4+2; j++)
				cout<<0<<" "<<j<<endl;
			for(int j = i*4; j<=i*4+2; j++)
				if(j%2 == 0)
					cout<<1<<" "<<j<<endl;
		}
		for(int n = 0; n<2*N+3; n++)
			cout<<2<<" "<<n<<endl;
		for(int i = 0; i<up; i++)
		{
			for(int j = i*4+2; j<=i*4+4; j++)
				if(j%2 == 0)
					cout<<3<<" "<<j<<endl;
			for(int j = i*4+2; j<=i*4+4; j++)
				cout<<4<<" "<<j<<endl;
		}
	}
	return 0;
}
