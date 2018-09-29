/*
ID: iCoder0020
PROG: Sum square difference
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	long long int N, answer;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		answer = ((N)*(N+1)*(3*N*N-N-2))/12;
		cout<<answer<<"\n";
	}
	return 0;
}