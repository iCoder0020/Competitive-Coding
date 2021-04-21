#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	if(N == 2 || N == 3)
		cout<<"NO SOLUTION";
	else if(N == 4)
		cout<<"3 1 4 2";
	else
	{
		for(int n = 1; n<=N; n+=2)
			cout<<n<<" ";
		for(int n = 2; n<=N; n+=2)
			cout<<n<<" ";
	}
	cout<<endl;
	return 0;
}
