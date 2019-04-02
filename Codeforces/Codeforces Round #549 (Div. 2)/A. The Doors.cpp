/*
ID: iCoder0020
PROG: The Doors
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	int last_zero = -1;
	int last_one = -1;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(A[n] == 0)
			last_zero = n+1;
		else
			last_one = n+1;
	}
	cout<<min(last_zero, last_one)<<endl;
	return 0;
}