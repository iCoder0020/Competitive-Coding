/*
ID: ishan_sang
PROG: CIELRCPT
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N,count;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		count = 0;
		cin>>N;
		count += N/2048;
		N %= 2048;
		while(N>0)
		{
			if(N&1)
			{
				count++;
			}
			N/=2;
		}
		cout<<count<<"\n";
	}
	return 0;
}