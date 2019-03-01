/*
ID: ishan_sang
PROG: MIXGA
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N,K;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>K;
		int A[N];
		int sum = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n] == 1)
			{
				if(n%2 == 0)
				{
					if(abs(sum + 1) >= abs(sum - 1))
					{
						sum ++;
					}
					else
					{
						sum --;
					}
				}
				else
				{
					if(abs(sum + 1) <= abs(sum - 1))
					{
						sum ++;
					}
					else
					{
						sum --;
					}
				}
			}
		}
		if(abs(sum) >= K)
		{
			cout<<"1\n";
		}
		else
		{
			cout<<"2\n";
		}
	}
	return 0;
}