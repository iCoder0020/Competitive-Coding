/*
ID: iCoder0020
PROG: Non-Coprime Partition
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int p;
	if(N<3)
	{
		cout<<"No\n";
	}
	else
	{
		if(N%2 == 0)
		{
			p = N/2;
		}
		else
		{
			p = (N+1)/2;
		}
		cout<<"Yes\n";
		cout<<"1 "<<p<<"\n";
		cout<<N-1<<" ";
		for(int n = 1; n<=N; n++)
		{
			if(n!=p)
			{
				cout<<n<<" ";
			}
		}
		cout<<"\n";
	}
	return 0;
}