/*
ID: ishan_sang
PROG: MAGICHF2
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
		long long int N;
		long long int K;
		long long int reference_coins = 0;
		long double pr;
		cin>>N>>K;
		if(K == 0 || N<=2)
		{
			pr = (long double)(1.0/((long double)(N)));
		}
		else 
		{
			while(K--)
			{
				if(N%4 == 2)
				{
					if(reference_coins >= N/2)
					{
						reference_coins += N/2;
						N = N/2;
					}
					else
					{
						reference_coins += (N-2)/2;
						N = (N+2)/2;
					}
				}
				else if(N%2 == 0)
				{
					reference_coins += N/2;
					N = N/2;
				}
				else
				{
					reference_coins += (N-1)/2;
					N = (N+1)/2;
				}
				if(N == 1)
				{
					break;
				}
			}
			pr = (long double)(1.0/((long double)(N)));
		}
		cout<<setprecision(10)<<fixed<<pr<<endl;
	}
	
	return 0;
}