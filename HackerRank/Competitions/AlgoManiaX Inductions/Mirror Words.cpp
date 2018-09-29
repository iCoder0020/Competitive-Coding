/*
ID: f20170069
PROG: Mirror Words
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	char a[50];
	int n;
    cin>>n;
    long ans=1;
    int k=(n%2);
    for(int i=1;i<=n/2+k;i++)
    {
        ans*=26;
    }
    cout<<ans<<"\n";
	return 0;
}