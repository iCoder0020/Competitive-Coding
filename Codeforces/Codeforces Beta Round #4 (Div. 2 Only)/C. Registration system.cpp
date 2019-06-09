/*
ID: iCoder0020
PROG: Registration system
LANG: C++                  
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	int N;
  	cin>>N;
  	map<string, int>MAP;
  	while(N--)
  	{
  		string S;
  		cin>>S;
  		if(MAP.find(S) == MAP.end())
  		{
  			cout<<"OK"<<endl;
  			MAP[S] = 1;
  		}
  		else
  		{
  			cout<<S<<MAP[S]<<endl;
  			MAP[S]++;
  		}
  	}
    return 0;
}