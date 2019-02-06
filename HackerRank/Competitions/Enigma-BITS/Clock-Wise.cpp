/*
ID: iCoder0020
PROG: Clock-Wise
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int N;
    cin>>N;
    int T;
    cin>>T;
    while(T--)
    {
        int time;
        cin>>time;
        if((time+1)%N == 0)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}