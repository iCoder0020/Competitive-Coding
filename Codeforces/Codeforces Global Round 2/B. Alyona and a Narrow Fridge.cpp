/*
ID: iCoder0020
PROG: Alyona and a Narrow Fridge
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N, H;
	cin>>N>>H;
	int A[N], B[N];
	bool possible = true;
	int K = 0;
	for(int n = 0; n<N; n++)
		cin>>B[n];
	for(int n = 0; n<N; n++)
	{
		for(int i = 0; i<n+1; i++)
			A[i] = B[i];

		sort(A, A+n+1, greater<int>());
		int H_temp = H;

		for(int i = 0; i<n+1; i+=2)
		{
			H_temp -= A[i];
			if(H_temp < 0)
			{
				possible = false;
				break;
			}
		}
		if(!possible)
			break;
		K++;
	}
	cout<<K<<endl;
	return 0;
}