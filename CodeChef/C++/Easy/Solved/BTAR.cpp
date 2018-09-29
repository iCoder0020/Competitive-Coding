/*
ID: ishan_sang
PROG: BTAR
LANG: C++
*/

#include <iostream>
 
using namespace std;
 
int main()
{
	long int T,N;
	long int D3,D2,D1,ans;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		long int A[N];
		D3 = 0;
		D2 = 0;
		D1 = 0;
		ans = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n]%4 == 1)
			{
				D1++;
			}
			if(A[n]%4 == 2)
			{
				D2++;
			}
			if(A[n]%4 == 3)
			{
				D3++;
			}
		}
		if(D3 > D1)
		{
			ans += D1;
			D3 -= D1;
			D1 = 0;
		}
		else if(D1 > D3)
		{
			ans += D3;
			D1 -= D3;
			D3 = 0;
		}
		else
		{
			ans += D1;
			D1 = 0;
			D3 = 0;
		}
		ans += D2/2;
		D2 %= 2;
		ans += 3*(D3-D3%4)/4;
		D3 %= 4;
		ans += 3*(D1-D1%4)/4;
		D1 %= 4;
		if(D1 == 2 && D2 == 1)
		{
			ans += 2;
			D1 = 0;
			D2 = 0;
		}
		if(D2 == 1 && D3 == 2)
		{
			ans += 2;
			D2 = 0;
			D3 = 0;
		}
		if(D1 == 0 && D2 == 0 && D3 == 0)
		{
			cout<<ans<<"\n";
		}
		else
		{
			cout<<"-1"<<"\n";
		}
	}
	return 0;
} 