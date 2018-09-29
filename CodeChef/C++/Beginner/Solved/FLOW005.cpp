/*
ID: ishan_sang
PROG: FLOW005
LANG: C++                  
*/

#include <iostream>

using namespace std;

int T,N;
int num_notes;

void remove_demonination(int k)
{
	if(N/k)
	{
		num_notes+=N/k;
		N%=k;
	}
}

int main()
{
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		num_notes=0;
		remove_demonination(100);
		remove_demonination(50);
		remove_demonination(10);
		remove_demonination(5);
		remove_demonination(2);
		cout<<num_notes+N<<"\n";
	}
	return 0;
}