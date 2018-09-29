/*
ID: iCoder0020
PROG: Find Digits
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T,N;
	int num;
	int count;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		count=0;
		cin>>N;
		num = N;
		while(N)
		{
			if((N%10) !=0 && num%(N%10) == 0)
			{
				count++;
			}
			N/=10;
		}
		cout<<count<<"\n";
	}
	return 0;
}	