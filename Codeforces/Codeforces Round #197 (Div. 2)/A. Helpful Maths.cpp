/*
ID: iCoder0020
PROG: Helpful Maths
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>>S;
	int count[4] = {0};
	for(int n = 0; n<S.length(); n++)
	{
		if(S[n] == '1')
			count[1]++;
		if(S[n] == '2')
			count[2]++;
		if(S[n] == '3')
			count[3]++;
	}
	for(int n = 1; n<=3; n++)
	{
		if(count[n] > 0)
		{
			for(int m = 1; m<=count[n]; m++)
			{
				cout<<n;
				if(m != count[n])
				{
					cout<<"+";
				}
			}
			if((n == 1 && (count[2] > 0 ||count[3] > 0)) || (n == 2 && count[3] > 0))
			{
				cout<<"+";
			}
		}
	}
	cout<<endl;
	return 0;
}