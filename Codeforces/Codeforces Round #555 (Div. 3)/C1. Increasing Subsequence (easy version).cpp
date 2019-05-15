/*
ID: iCoder0020
PROG: Increasing Subsequence (easy version)
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
	for(int n = 0; n<N; n++)
		cin>>A[n];
	int l = 0;
	int r = N-1;
	int temp = -1*INT_MAX;
	string ans = "";
	while(1)
	{
		if(l>r)
			break;
		if(A[l] < temp && A[r] < temp)
			break;
		if(A[l] < temp)
		{
			temp = A[r];
			ans+='R';
			r--;
		}
		else if(A[r] < temp)
		{
			temp = A[l];
			ans+='L';
			l++;
		}
		else
		{
			if(A[l] < A[r])
			{
				temp = A[l];
				ans+='L';
				l++;
			}
			else
			{
				temp = A[r];
				ans+='R';
				r--;
			}
		}
	}
	cout<<ans.length()<<endl<<ans<<endl;
	return 0;
}