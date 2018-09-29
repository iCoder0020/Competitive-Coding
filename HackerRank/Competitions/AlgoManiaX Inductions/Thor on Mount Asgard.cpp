/*
ID: f20170069
PROG: Thor on Mount Asgard
LANG: C++                  
*/

#include <iostream>

using namespace std;

long h,n,v=0;

void climb()
{
    for(n=0;v!=h;n+=3)
    {
        v+=2;
        if(v!=h)
        {
            n++;
            v--;
        }
    }
}

void input()
{
    cin>>h;
}

int main()
{
	input();
    climb();
    cout<<n<<"\n";
	return 0;
}
