/*
ID: iCoder0020
PROG: Right-Left Cipher
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S,T;
	int i,j;
	cin>>S;
	T = "";
	int len = S.length();
	i = 0;
	j = S.length()-1;
	while(len!=0)
	{
		if(len%2 == 0)
		{
			T = S[j] + T;
			j--; 
		}
		else
		{
			T = S[i] + T; 
			i++;
		}
		len--;
	}
	cout<<T<<endl;
	return 0;
}