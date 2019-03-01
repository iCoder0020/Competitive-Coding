/*
ID: ishan_sang
PROG: MGCSET
LANG: C++                  
*/

#include <iostream>

using namespace std;

typedef long int li;

li power(li a, li x)
{
	if(x < 0)
	{
		cout<<"No negative exponents allowed.\n";
		return 0;
	}
	if(a == 1 || x == 0)
	{
		return 1;
	}
	li result = a;
	if(x == 1)
	{
		return result;
	}	
	else if(x&1)
	{
		x--;
		return result*power(result,x);
	}
	else
	{
		x = x>>1;
		result = result*result;
		return power(result,x);
	}
}

int main()
{
	int T;
	int N,M;
	int num;
	li count;
	cin>>T;
	for(int t = 0; t<T; t++)
	{	
		cin>>N>>M;
		count = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>num;
			if(num%M == 0)
			{
				count++;
			}	
		}
		cout<<power(2, count)-1<<"\n";
	}
	return 0;
}