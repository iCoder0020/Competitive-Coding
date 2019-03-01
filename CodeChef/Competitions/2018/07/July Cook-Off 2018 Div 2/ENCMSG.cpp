/*
ID: ishan_sang
PROG: ENCMSG
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N;
	string S;
	char temp;
	cin>>T;
	for(int t = 0; t<T; t++)
	{	
		cin>>N;
		cin>>S;
		for(int i = 0; i<N; i+=2)
		{
			if(i+1 < N)
			{
				temp = S[i];
				S[i] = S[i+1];
				S[i+1] = temp;
			}
		}
		for(int i = 0; i<N; i++)
		{
			S[i] = char(97 + 122 - (int)(S[i]));
		}
		cout<<S<<"\n";
	}
	return 0;
}