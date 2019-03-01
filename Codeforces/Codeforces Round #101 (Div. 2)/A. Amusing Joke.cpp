/*
ID: iCoder0020
PROG: Amusing Joke
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string A,B,C;
	cin>>A>>B>>C;
	if(A.length() + B.length() != C.length())
	{
		cout<<"NO";
	}
	else
	{
		A = A+B;
		sort(A.begin(), A.end());
		sort(C.begin(), C.end());

		if(A == C)
		{
			cout<<"YES";
		}
		else
		{
			cout<<"NO";
		}
	}
	cout<<endl;
	return 0;
}