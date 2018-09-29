/*
ID: iCoder0020
PROG: Birthday Cake Candles
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main() 
{
    long N,h,hmax=0,num=0;
    int i;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>h;
        if(hmax<=h)
        {
            if(hmax<h)
            {
                num=0;
                hmax=h;
            }
            num++;
        }
    }
    cout<<num<<"\n";
    return 0;
}
