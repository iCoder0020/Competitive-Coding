/*
ID: icoder_0020
PROG: Manna's First Name
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;

#define MAX_LENGTH 160

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		char S[MAX_LENGTH];
		scanf("%s^\n", S);
		int a = 0;
		int b = 0;
		for(int n = 0; S[n]!='\0'; n++)
		{
			if(S[n] == 'S' && S[n+1] == 'U' && S[n+2] == 'V' && S[n+3] == 'O')
			{
				if(S[n+4] == 'J' && S[n+5] == 'I' && S[n+6] == 'T')
				{
					a++;
				}
				else
				{
					b++;
				}
			}
		}
		cout<<"SUVO = "<<b<<", SUVOJIT = "<<a<<endl;
	}
	return 0;
}
