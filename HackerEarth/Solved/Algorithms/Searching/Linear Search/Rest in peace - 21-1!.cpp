/*
ID: icoder_0020
PROG: Rest in peace - 21-1!
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;

int toi(string S)
{
	int num = 0;
	for(int i = 0; i<S.length(); i++)
	{
		num = 10*num + (int)(S[i]) - 48;
	}
	return num;
}

int main()
{
	int T;
	cin>>T;
	string S;
	for(int t = 0; t<T; t++)
	{
		cin>>S;
		if(toi(S)%21 == 0)
		{
			cout<<"The streak is broken!";
		}
		else
		{
			for(int n = 0; n<S.length()-1; n++)
			{
				if(S[n] == '2' && S[n+1] == '1')
				{
					cout<<"The streak is broken!";
					break;
				}
				if(n == S.length()-2)
				{
					cout<<"The streak lives still in our heart!";
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
