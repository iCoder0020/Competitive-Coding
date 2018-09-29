/*
ID: iCoder0020
PROG: Sequence Equation
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int p[N];
	bool flag;
	for(int n = 0; n<N; n++)
	{
		cin>>p[n];
	}
	for(int i = 1; i<=N; i++)
	{
		flag = false;
		for(int j = 1; j<=N; j++)
		{
			if(p[j-1] == i)
			{
				for(int n = 1; n<=N; n++)
				{
					if(p[n-1] == j)
					{
						cout<<n<<"\n";
						flag = true;
						break;
					}
				}
			}
			if(flag)
			{
				break;
			}
		}
	}
	return 0;
}	