/*
ID: iCoder0020
PROG: Utopian Tree
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T,N;
	int ans;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		ans = 1;
		for(int n = 0; n<N; n++)
		{
			if(n%2 == 0)
			{
				ans*=2;
			}
			else
			{
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}