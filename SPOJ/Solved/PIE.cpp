/*
ID: icoder_0020
PROG: PIE
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793238462643383279502884197169399375105820974
#define EPSILON 0.0000001

typedef long double ld;

bool check(double mid, double A[], int N, int F)
{
	int count = 0;
	for(int n = 0; n<N; n++)
	{
		count += floor((A[n]*A[n])/mid);
		if(count >= F+1)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,F;
		cin>>N>>F;
		double A[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
		}
		double min = 0;
		double max = 1e16;
		double mid;
		while(1)
		{
			mid = (min + max)/2;
			if(max - min <= EPSILON)
			{
				if(check(mid, A, N, F))
				{
					mid = max;
				}
				else
				{
					mid = min;
				}
				break;
			}
			else if(check(mid, A, N, F))
			{
				min = mid;
			}
			else
			{
				max = mid - EPSILON;
			}
		}
		cout<<setprecision(10)<<fixed<<mid*PI<<endl;
	}
	return 0;
}