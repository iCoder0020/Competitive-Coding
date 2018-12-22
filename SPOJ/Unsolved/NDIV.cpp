/*
ID: icoder_0020
PROG: NDIV
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A,B,N;
	int count = 0;
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
	for(int i = 2; i<=sqrt(B); i++)
	{
		for(int j = (A/i); i*j<=B; j++)
		{
            if(j>1 && i*j-A>=0)
            {
            	if(i == j)
            	{
            		ARR[i*j-A]++;
            	}
            	else
            	{
                	ARR[i*j-A]+=2;
                }
            }
		}
	}
	for(int i = 0; i<=B-A; i++)
	{
		cout<<i+A<<" "<<ARR[i]<<endl;
		if(ARR[i] == N)
		{
			count++;
		}
	}
	cout<<count<<"\n";
	return 0;
}
