/*
ID: iCoder0020
PROG: Make Product Equal One
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	int pos = 0, neg = 0, zero = 0, cnt = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(A[n]<0)
		{
			cnt += abs(A[n])-1;
			neg++;
		}
		else if(A[n] == 0)
		{
			cnt++;
			zero++;
		}
		else
		{
			cnt += A[n]-1;
			pos++;
		}
	}
	if(neg%2 != 0 && zero == 0)
		cnt+=2;
	cout<<cnt<<endl;
}