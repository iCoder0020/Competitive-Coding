/*
ID: ishan_sang
PROG: ZCO13001
LANG: C++                  
*/

#include <iostream>

using namespace std;

typedef long long int lli;

int main()
{
	int N;
	cin>>N;
	lli A[1001] = {0};
	int temp;
	for(int n = 0; n<N; n++)
	{
		cin>>temp;
		A[temp]++;
	}
	lli sum = 0;
	for(int n = 1; n<=1000; n++)
	{
		if(A[n]!=0)
		{
			for(int m = n+1; m<=1000; m++)
			{	
				if(A[m]!=0)
				{
					if(m != n)
					{
						sum += A[n]*A[m]*(m-n);
					}
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}