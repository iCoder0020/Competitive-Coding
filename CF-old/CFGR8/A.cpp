#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int A,B,N;
		cin>>A>>B>>N;
		int a = A, b = B;
		int cnt1 = 0, cnt2 = 0;
		while(A<=N && B<=N)
		{
			if(A<B)
				A = A+B;
			else
				B = A+B;
			cnt1++;
		}
		cout<<cnt1<<endl;
	}
	return 0;
}
