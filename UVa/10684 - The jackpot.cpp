/*
ID: iCoder0020
PROG: 10684 - The jackpot
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
	int N ;
	while(cin>>N)
	{
		if(N == 0)
		{
			break;
		}
		li A[N];
		li sum = 0;
		li max_sum = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			sum = max(sum + A[n], A[n]);
			max_sum = max(sum, max_sum);
		}
		if(max_sum > 0)
		{
			cout<<"The maximum winning streak is "<<max_sum<<"."<<endl;
		}
		else
		{
			cout<<"Losing streak."<<endl;
		}
	}
	return 0;
}