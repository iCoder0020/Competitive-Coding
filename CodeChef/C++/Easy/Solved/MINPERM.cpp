/*
ID: ishan_sang
PROG: MINPERM
LANG: C++
*/

#include <iostream>

using namespace std;

int T;
long N;
int i,j,k;

void run()
{
	cin>>T;
	for(i=0;i<T;i++)
	{
		cin>>N;
		if(N%2==0)
		{
			for(j=2;j<=N;j+=k)
			{
				cout<<j<<" ";
				if(j%2==0)
				{
					k=-1;
				}
				else
				{
					k=3;
				}
			}
		}
		else
		{
			for(j=2;j<=N;j+=k)
			{
				if(j==N-1)
				{
					cout<<j<<" "<<N<<" "<<N-2<<" ";
					j=N+1;
				}
				else
				{
					cout<<j<<" ";
					if(j%2==0)
					{
						k=-1;
					}
					else
					{
						k=3;
					}
				}
			}	
		}
		cout<<"\n";
	}
}

int main()
{
	run();
	return 0;
}
