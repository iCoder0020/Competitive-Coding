#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check_square(int N)
{
	int x = sqrt(N);
	return x*x == N;
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N;
		cin>>N;
		if((N%2 == 0 && check_square(N/2)) || (N%4 == 0 && check_square(N/4)))
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}
