/*
ID: ishan_sang
PROG: XORNEY
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
	for(int n = 0; n<N; n++)
	{
		long long int L,R;
		cin>>L>>R;
		long long int odd = (R-L)/2;
		if(L%2 == 1 || R%2 == 1)
		{
			odd++;
		}
		if(odd%2 == 0)
		{
			cout<<"Even\n";
		}
		else
		{
			cout<<"Odd\n";
		}
	}
	return 0;
}