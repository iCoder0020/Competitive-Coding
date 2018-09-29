/*
ID: icoder_0020
PROG: NDIV
LANG: C++
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int A,B,N;
	int count =0;
	cin>>A>>B>>N;
	int ARR[B-A+1];
	for(int i = A; i<=B; i++)
	{
	    if(i == 1)
        {
            ARR[i-A] = 1;
        }
		else
        {
                ARR[i-A] = 2;
		}
	}
	for(int i = 2; i<=B; i++)
		{
			for(int j = (A/i); i*j<=B; j++)
			{
                if(j>1 && )
                {
                    ARR[i*j-A]++;
                }
			}
		}
	for(int i = 0; i<=B-A; i++)
	{
		if(ARR[i] == N)
		{
			count++;
		}
	}
	cout<<count<<"\n";
	return 0;
}
