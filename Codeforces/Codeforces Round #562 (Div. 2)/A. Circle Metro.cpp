/*
ID: iCoder0020
PROG: Circle Metro
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N, A, B, X, Y;
	cin>>N>>A>>X>>B>>Y;
	bool ans = false;
	while(X!=A && Y!=B)
	{
		if(A == B)
			ans = true;
		A++;
		if(A == N+1)
			A = 1;
		B--;
		if(B == 0)
			B = N;
	}
	if(A == B)
		ans = true;
	if(ans)
		cout<<"YES";
	else
		cout<<"NO";
	cout<<endl;
	return 0;
}