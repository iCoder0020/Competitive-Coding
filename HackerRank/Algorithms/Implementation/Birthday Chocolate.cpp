/*
ID: iCoder0020
PROG: Birthday Chocolate
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int S[N];
	int DAY;
	int MONTH;
	for(int n=0; n<N; n++)
	{
		cin>>S[n];
	}	
	cin>>DAY>>MONTH;
	int count = 0;
	int sum;
	for(int i=0; i<=N-MONTH; i++)
	{
		sum = 0;
		for(int j=0; j<MONTH; j++)
		{
			sum+=S[i+j];
		}
		if(sum == DAY)
		{
			count++;
		}
	}
	cout<<count<<"\n";
	return 0;
}