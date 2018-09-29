/*
ID: ishan_sang
PROG: C00K0FF
LANG: C++                  
*/

#include <string.h>
#include <iostream>

using namespace std;

int main()
{
    int T;
    int a,b,c,d,e;
    int N;
    char s[20];
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>N;

        a=0,b=0,c=0,d=0,e=0;
        for(int j=0;j<N;j++)
        {
            cin>>s;
            if(!strcmp(s,"cakewalk"))
                    a=1;
            if(!strcmp(s,"simple"))
                    b=1;
            if(!strcmp(s,"easy"))
                    c=1;
            if(!(strcmp(s,"easy-medium")&&strcmp(s,"medium")))
                    d=1;
            if(!(strcmp(s,"medium-hard")&&strcmp(s,"hard")))
                    e=1;
        }
        if(a+b+c+d+e==5)
            cout<<"Yes"<<"\n";
        else
            cout<<"No"<<"\n";
    }
    return 0;
}