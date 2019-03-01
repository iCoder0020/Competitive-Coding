/*
ID: ishan_sang
PROG: TRICKYDL
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
	int T;
	cin>>T;	
	li pow2[40];
	pow2[0] = 1;
	for(int n = 1; n<40; n++)
	{
		pow2[n] = 2*pow2[n-1];
	}
	for(int t = 0; t<T; t++)
	{
		li A;
		cin>>A;
		li i = 0;
		li j = 0;
		li sum1 = 0;
		li max = 0;
		while(1)
		{
			if(sum1 + A - pow2[i]> 0)
			{
				sum1 += A-pow2[i];
				i++;
			}
			else
			{
				break;
			}
		}	
		while(1)
		{
			if(A*(j+1) - pow2[j] > max)
			{
				max = A*(j+1) - pow2[j];
				j++;
			}
			else
			{
				break;
			}
		}
		cout<<i<<" "<<j-1<<endl;
	}
	return 0;
}