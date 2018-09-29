/*
ID: f20170069
PROG: The Hound and White Walkers
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	long X,Y;
    cin>>X>>Y;
    while(X!=Y||X!=0||Y!=0)
    {
        if(X>Y)
            X-=Y;
        else if(X<Y)
            Y-=X;
        else
        {
             cout<<X<<"\n";
             return 0;
        }
           
    }
    cout<<X<<Y<<"\n";
	return 0;
}