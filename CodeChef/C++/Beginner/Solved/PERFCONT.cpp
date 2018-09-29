/*
ID: ishan_sang
PROG: PERFCONT
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N,P;
	int a,b;
	int tmp;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		a=0,b=0;
		cin>>N>>P;
		for(int j=0;j<N;j++)
		{
			cin>>tmp;
			if(tmp>=P/2)
				a++;
			if(tmp<=P/10)
				b++;
		}
		if(a==1&&b==2)
			cout<<"yes";
		else
			cout<<"no";
		cout<<"\n";
	}
	return 0;
}