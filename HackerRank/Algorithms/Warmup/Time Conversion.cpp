/*
ID: iCoder0020
PROG: Time Conversion
LANG: C++                  
*/

#include <iostream>

using namespace std;

void change_number(string s)
{
    int num=(int)(s[0]-48)*10+(int)(s[1]-48);
    int num1=num+12;
    cout<<num1;
}

int main() 
{
    string s;
    cin>>s;
    if(s[8]=='A')
    {
        if(s[0]=='1'&&s[1]=='2')
        {
            s[0]='0';
            s[1]='0';
        }
        for(int i=0;i<8;i++)
        {
            cout<<s[i];
        }
    }
    else if(s[8]=='P')
    {
        if(s[0]=='1'&&s[1]=='2')
        {
            cout<<s[0]<<s[1];
        }
        else
            change_number(s);
        for(int i=2;i<8;i++)
        {
            cout<<s[i];
        }
    }
    cout<<"\n";
    return 0;
}
