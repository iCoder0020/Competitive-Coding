/*
ID: iCoder0020
PROG: Multiples of 3 and 5
LANG: C++                  
*/

#include <iostream>

using namespace std;

long long int sum;

void get_all_multiples(long long int A, long long int N, char c)
{
	while(N%A != 0)
	{
		N--;
	}
	long long int s = (N*((N/A)+1))/2;
	if(c == '+')
	{
		sum += s;
	}
	else
	{
		sum -= s;
	}
}

int main()
{
	int T;
	long long int N;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		sum = 0;
		cin>>N;
		N = N-1;
		get_all_multiples(3, N, '+');
		get_all_multiples(5, N, '+');
		get_all_multiples(15, N, '-');
		cout<<sum<<"\n";
	}
	return 0;
}