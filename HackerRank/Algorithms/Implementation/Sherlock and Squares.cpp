/*
ID: iCoder0020
PROG: Sherlock and Squares
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int A,B;
	int count;
	for(int t = 0; t<T; t++)
	{
		count = 0;
		cin>>A>>B;
		cout<<floor(sqrt(B))-ceil(sqrt(A))+1<<"\n";
	}
	return 0;
}
