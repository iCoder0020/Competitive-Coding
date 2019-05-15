/*
ID: iCoder0020
PROG: Serval and Bus
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N;
	double T;
	cin>>N>>T;
	double min_diff = INT_MAX;
	int min_num = 0;
	for(int n = 0; n<N; n++)
	{
		double A,B;
		cin>>A>>B;
		if(A >= T)
		{
			if(A-T <= min_diff)
			{
				min_diff = A-T;
				min_num = n+1;
			}
		}
		else
		{
			int num = ceil((T-A)/B);
			if(A+num*B - T <= min_diff)
			{
				min_diff = A+num*B - T;
				min_num = n+1;
			}
		}
	}
	cout<<min_num<<endl;
	return 0;
}