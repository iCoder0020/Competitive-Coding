/*
ID: code_lite
PROG: SNCKYEAR
LANG: C++                  
*/

#include <iostream>
using namespace std;

int main() 
{
  int T;
  cin>>T;
  for(int t=0;t<T;t++)
  {
    int num;
    cin>>num;
    if(num==2010 || num==2015|| num==2016|| num==2017|| num==2019)
    {
      cout<<"HOSTED\n";
    }
    else
    {
      cout<<"NOT HOSTED\n";
    }
  }
}