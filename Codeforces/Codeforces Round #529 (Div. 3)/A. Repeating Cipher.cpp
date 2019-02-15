/*
ID: iCoder0020
PROG: Repeating Cipher
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	string S;
	cin>>S;
	int k = 1;
	string T="";
	for(int n = 0; n<N; n+=k)
	{
		T+=S[n];
		k++;
	}
	cout<<T<<endl;
	return 0;
}