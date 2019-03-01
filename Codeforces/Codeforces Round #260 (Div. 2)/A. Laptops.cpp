/*
ID: iCoder0020
PROG: Laptops
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N], B[N];
	bool happy_alex = false;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n]>>B[n];
		if(A[n] != B[n])
		{
			happy_alex = true;
		}
	}
	if(happy_alex)
	{
		cout<<"Happy Alex"<<endl;
	}
	else
	{
		cout<<"Poor Alex"<<endl;
	}
	return 0;
}