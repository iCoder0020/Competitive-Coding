#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int A,B,C,N;
		cin>>A>>B>>C>>N;
		int S = (A+B+C+N)/3;
		if((A+B+C+N) % 3 != 0)
			cout<<"NO";
		else
		{
			if(A<=S && B<=S && C<=S)
				cout<<"YES";
			else
				cout<<"NO";
		}
		cout<<endl;
	}
	return 0;
}
