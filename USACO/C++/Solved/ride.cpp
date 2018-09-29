/*
ID: ishansa2
PROG: ride
LANG: C++                  
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    char a[8],b[8];
    int c=1,d=1,i=0;
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    fin>>a>>b;
    for(i=0;a[i]!='\0';i++) {
        c*=(int(a[i])-64);
    }
    for(i=0;b[i]!='\0';i++) {
        d*=(int(b[i])-64);
    }
    if(c%47==d%47)
        fout<<"GO"<<"\n";
    else
        fout<<"STAY"<<"\n";
    return 0;
}