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
		{
			A+=B;
			B = A-B;
			A-=B;
		}
		int cnt = 0;
		cnt+=(B-A)/10;
		if((B-A)%10 !=0)
			cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
