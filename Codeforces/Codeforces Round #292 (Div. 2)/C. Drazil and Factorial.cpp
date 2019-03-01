/*
ID: iCoder0020
PROG: Drazil and Factorial
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	string S;
	cin>>S;
	int A[4] = {0};
	int arr[4] = {2,3,5,7};
	for(int n = 0; n<N; n++)
	{
		if(S[n] == '2')
		{
			A[0]++;
		}
		else if(S[n] == '3')
		{
			A[1]++;
		}
		else if(S[n] == '4')
		{
			A[0]+=2;
			A[1]++;
		}
		else if(S[n] == '5')
		{
			A[2]++;
		}
		else if(S[n] == '6')
		{
			A[1]++;
			A[2]++;
		}
		else if(S[n] == '7')
		{
			A[3]++;
		}
		else if(S[n] == '8')
		{
			A[0]+=3;
			A[3]++;
		}
		else if(S[n] == '9')
		{
			A[0]++;
			A[1]+=2;
			A[3]++;
		}
	}
	for(int n = 3; n>=0; n--)
	{
		for(int m = 0; m<A[n]; m++)
		{
			cout<<arr[n];
		}
	}
	cout<<endl;
	return 0;
}