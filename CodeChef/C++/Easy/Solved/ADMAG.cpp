/*
ID: ishan_sang
PROG: ADMAG
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
    int T;
    long N;
    long a,b,c;
    long ans;
    cin>>T;
    for(int t = 0; t<T; t++)
    {
    	ans = 0;
    	a = 0, b = 1, c = 0;
    	cin>>N;
    	while(c<=N)
    	{
    		c = a+b;
    		a = b;
    		b = c;
    		ans++;
    	}
    	cout<<ans-1<<"\n";
    }
    return 0;
}
