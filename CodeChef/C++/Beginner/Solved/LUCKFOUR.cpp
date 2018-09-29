/*
ID: ishan_sang
PROG: LUCKFOUR
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T,num;
	long N;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		num=0;
		cin>>N;
		while(N!=0)
		{
			if(N%10==4)
				num++;
			N/=10;
		}
		cout<<num<<"\n";
	}
	return 0;
}