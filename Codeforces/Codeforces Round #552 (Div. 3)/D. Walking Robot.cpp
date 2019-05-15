/*
ID: iCoder0020
PROG: Walking Robot
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N,B,A;
	cin>>N>>B>>A;
	int sun[N];
	for(int n = 0; n<N; n++)
		cin>>sun[n];
	int a = A;
	int b = B;
	int cnt = 0;
	for(int n = 0; n<N; n++)
	{
		if(b>=1 && sun[n] == 1 && a < A)
		{
			b--;
			a++;
			cnt++;
		}
		else if(a > 0)
		{
			a--;
			cnt++;
		}
		else if(b > 0)
		{
			b--;
			cnt++;
		}
		else
		{
			break;
		}
	}
	cout<<cnt<<endl;
	return 0;
}