/*
ID: ishan_sang
PROG: FCTRL
LANG: C++                  
*/

#include <iostream>

using namespace std;

int T,N[100000],p;
int i,num,k;

void input()
{
	cin>>T;
	for(i=0;i<T;i++)
	{
		cin>>N[i];
	}
}

void print_num_zeroes()
{
	for(i=0;i<T;i++)
	{
		num=0;
		while(N[i]/5!=0)
		{
			N[i]/=5;
			num+=N[i];
		}
		cout<<num<<"\n";
	}

}

int main()
{
	input();
	print_num_zeroes();
	return 0;
}