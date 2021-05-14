#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int X,Y,A,B;
		cin>>X>>Y>>A>>B;
		if(abs(X-Y) % (A+B) == 0)
			cout<<abs(X-Y)/(A+B);
		else
			cout<<-1;
		cout<<endl;
	}
	return 0;
}
