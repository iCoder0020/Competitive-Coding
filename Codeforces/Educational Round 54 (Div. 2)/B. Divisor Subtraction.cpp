/*
ID: iCoder0020
PROG: Meme Problem
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int N;
	cin>>N;
	if(N%2 == 0)
	{
		cout<<N/2<<endl;
	}
	else
	{
		bool flag = false;
		for(int i = 3; i<=sqrt(N); i+=2)
		{
			if(N%i == 0)
			{
				N-=i;
				flag = true;
				break;
			}
		}
		if(flag)
		{
			cout<<N/2+1<<endl;
		}
		else
		{
			cout<<1<<endl;
		}
	}
	return 0;
}