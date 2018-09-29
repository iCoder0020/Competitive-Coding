/*
ID: iCoder0020
PROG: Beautiful Days at the Movies
LANG: C++                  
*/

#include <iostream>

using namespace std;

int reverse(int N)
{
	int rev = 0;
	while(N)
	{
		rev *= 10;
		rev += N%10;
		N /= 10;
	}
	return rev;
}

int main()
{
	int start,end,K;
	int count = 0;
	cin>>start>>end>>K;
	for(int i = start; i<=end; i++)
	{
		if(abs(i - reverse(i))%K == 0)
		{
			count++;
		}
	}
	cout<<count<<"\n";
	return 0;
}