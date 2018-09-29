/*
ID: iCoder0020
PROG: The Hurdle Race
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N,K;
	cin>>N>>K;
	int num;
	int max = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>num;
		if(num>max)
		{
			max = num;
		}
	}
	int ans;
	if(K>=max)
	{
		cout<<"0\n";
	}
	else
	{
		cout<<max-K<<"\n";
	}
	return 0;
}