/*
ID: iCoder0020
PROG: Plus Minus
LANG: C++                  
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
    float N,input;
    float a=0,b=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>input;
        if(input>0)
            a++;
        if(input<0)
            b++;
    }
    cout<<fixed<<setprecision(6)<<(a/N)<<"\n"<<(b/N)<<"\n"<<((N-a-b)/N)<<"\n";
    return 0;
}
