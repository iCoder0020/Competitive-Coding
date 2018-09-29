/*
ID: icoder_0020
PROG: Shubham and Xor
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int N;
	cin>>N;
	int A[N];
	long long int num, s;
	long long int sum = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	sort(A, A+N);
	num = A[0];
	s = 1;
	for(int n = 1; n<N; n++)
	{
		if(A[n] == num)
		{
			s++;	
		}
		else
		{
			num = A[n];
			sum += (s*(s-1))/2;
			s = 1;
		}
	}
	cout<<sum + (s*(s-1))/2<<"\n";
	return 0;
}