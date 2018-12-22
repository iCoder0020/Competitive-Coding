/*
ID: iCoder0020
PROG: Margarite and the best present
LANG: C++                  
*/

#include <iostream>

using namespace std;

long long int pos_sum(long long int a, long long int b)
{
	return ((b-a+2)*(a+b))/4;
}
long long int neg_sum(long long int a, long long int b)
{
	return ((b-a+2)*(a+b)*(-1))/4;
}

int main()
{
	int Q, L, R;
	cin>>Q;
	for(int q = 0; q<Q; q++)
	{
		cin>>L>>R;
		if(L%2 == 0 && R%2 == 0)
		{
			cout<<pos_sum(L,R) + neg_sum(L+1,R-1);
		}
		else if(L%2 == 1 && R%2 == 0)
		{
			cout<<pos_sum(L+1,R) + neg_sum(L,R-1);
		}
		else if(L%2 == 0 && R%2 == 1)
		{
			cout<<pos_sum(L,R-1) + neg_sum(L+1,R);
		}
		else
		{
			cout<<pos_sum(L+1,R-1) + neg_sum(L,R);
		}
		cout<<endl;
	}
	return 0;
}