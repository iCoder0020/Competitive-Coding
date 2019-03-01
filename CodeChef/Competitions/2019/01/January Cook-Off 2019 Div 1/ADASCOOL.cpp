/*
ID: ishan_sang
PROG: ADASCOOL
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int N,M;
	
	for(int t = 0; t<T; t++)
	{
		cin>>N>>M;
		if(N*M%2 == 0)
		{
			cout<<"YES";
		}
		else
		{
			cout<<"NO";
		}
		cout<<endl;
	}
	return 0;
}