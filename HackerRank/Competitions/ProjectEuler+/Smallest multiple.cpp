/*
ID: iCoder0020
PROG: Smallest multiple
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define N_MAX 40

int max(int a, int b)
{
	return (a>b)?a:b;
}

long int power(long int a, long int x)
{
	if(x < 0)
	{
		cout<<"No negative exponents allowed.\n";
		return 0;
	}
	if(a == 1 || x == 0)
	{
		return 1;
	}
	long int result = a;
	if(x == 1)
	{
		return result;
	}	
	else if(x&1)
	{
		x--;
		return result*power(result,x);
	}
	else
	{
		x = x>>1;
		result = result*result;
		return power(result,x);
	}
}

int main()
{
	int A[N_MAX-1];
	int prime_factors_count = 0;
	for(int i = 0; i<N_MAX-1; i++)
	{
		A[i] = i+2;
	}
	for(int i = 2; i<=N_MAX/2; i++)
	{
		for(int j = 2; i*j<=N_MAX; j++)
		{
			A[i*j-2] = 0;
		}
	}
	for(int i = 0; i<N_MAX-1; i++)
	{
		if(A[i]!= 0)
		{
			prime_factors_count++;
		}
	}
	int Prime_Factors_Exponent[prime_factors_count][2];
	int k = 0;
	for(int i = 0; i<N_MAX-1; i++)
	{
		if(A[i]!= 0)
		{
			Prime_Factors_Exponent[k][0] = A[i];
			Prime_Factors_Exponent[k][1] = 0;
			k++;
		}
	}
	int T;
	cin>>T;
	int N, n_copy;
	int power_count;
	long int answer;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		answer = 1;
		for(int n = 2; n<=N; n++)
		{
			n_copy = n;
			for(int i = 0; i<prime_factors_count; i++)
			{
				if(n_copy/Prime_Factors_Exponent[i][0]<1)
				{
					break;
				}
				else
				{
					power_count = 0;
					while(n_copy%Prime_Factors_Exponent[i][0] == 0)
					{
						n_copy/=Prime_Factors_Exponent[i][0];
						power_count++;
					}
					Prime_Factors_Exponent[i][1] = max(Prime_Factors_Exponent[i][1], power_count);
				}
			}
		}
		for(int i = 0; i<prime_factors_count; i++)
		{
			answer*=pow(Prime_Factors_Exponent[i][0], Prime_Factors_Exponent[i][1]);
			Prime_Factors_Exponent[i][1] = 0;
		}
		cout<<answer<<"\n";
	}
	return 0;
}