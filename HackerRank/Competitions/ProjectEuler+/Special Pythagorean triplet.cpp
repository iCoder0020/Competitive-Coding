/*
ID: iCoder0020
PROG: Special Pythagorean triplet
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	int N;
	int a,b,c;
	cin>>T;
	long int max, product;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		if(N<12)
		{
			cout<<"-1\n";
		}
		else
		{
			max = -1;
			for(int n = 2; n<=ceil(sqrt(ceil(N/2))); n++)
			{
				for(int m = 1; m<n; m++)
				{
					a = n*n - m*m;
					b = 2*m*n;
					c = n*n + m*m;
					for(int k = 1; k*(a + b + c)<=N; k++)
					{
						if(k*a + k*b + k*c == N)
						{
							product = k*k*k*a*b*c;
							max = (max>product)?max:product;
						}
					}
				}
			}
			cout<<max<<"\n";
		}
	}
	return 0;
}