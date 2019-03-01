/*
ID: ishan_sang
PROG: MGAME
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		long long int N,P;
		cin>>N>>P;		
		long long int sum = 0;
		if(N <= 2)
		{
			sum = P*P*P;
		}
		else
		{
			long long int fN = (N-1)/2;
			sum = (P-N)*(P-N) + (P-N)*(P-fN) + (P-fN)*(P-fN);
		}
		cout<<sum<<endl;
	}
	return 0;
}