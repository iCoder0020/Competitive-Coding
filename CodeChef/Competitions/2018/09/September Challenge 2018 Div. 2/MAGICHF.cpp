/*
ID: ishan_sang
PROG: MAGICHF
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N,X,S;
	cin>>T;
	int A,B;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>X>>S;
		for(int s = 0; s<S; s++)
		{
			cin>>A>>B;
			if(X == A)
			{
				X = B;
			}
			else if(X == B)
			{
				X = A;
			}
			else
			{

			}
		}
		cout<<X<<"\n";
	}
	return 0;
}