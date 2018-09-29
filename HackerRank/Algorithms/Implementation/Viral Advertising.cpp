/*
ID: iCoder0020
PROG: Viral Advertising
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int shared, liked, sum = 0;
	shared = 5;
	for(int n = 0; n<N; n++)
	{
		liked = shared/2;
		shared = 3*liked;
		sum += liked;
	}
	cout<<sum<<"\n";
	return 0;
}