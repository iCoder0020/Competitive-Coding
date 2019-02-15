/*
ID: ishan_sang
PROG: QHOUSE
LANG: C++                  
*/
 
#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    int coordinates[4][2];
    int low,high;
    int x,y;
    int area;
    string S;

    low = 0;
    high = 1000;
    y = 0;
    while(1)
    {
        x = (low + high)/2;
        if(low == high)
        {
            break;
        }
        else if(low == high - 1)
        {
            x = high;
            cout<<"? "<<x<<" "<<y<<endl;
            cin>>S;
            if(S == "NO")
            {
                x = low;
            }
            break;
        }
        cout<<"? "<<x<<" "<<y<<endl;
        cin>>S;
        if(S == "YES")
        {
            low = x;
        }
        else
        {
            high = x-1;
        }
    }
    coordinates[0][0] = x;
    coordinates[0][1] = y;

    low = 0;
    high = 1000;
    x = 0;
    while(1)
    {
        y = (low + high)/2;
        if(low == high)
        {
            break;
        }
        else if(low == high - 1)
        {
            y = high;
            cout<<"? "<<x<<" "<<y<<endl;
            cin>>S;
            if(S == "NO")
            {
                y = low;
            }
            break;
        }
        cout<<"? "<<x<<" "<<y<<endl;
        cin>>S;
        if(S == "YES")
        {
            low = y;
        }
        else
        {
            high = y-1;
        }
    }
    coordinates[1][0] = x;
    coordinates[1][1] = y;

    coordinates[2][0] = coordinates[0][0];
    coordinates[2][1] = 2*coordinates[0][0];

    low = 0;
    high = 1000;
    y = coordinates[2][1];
    while(1)
    {
        x = (low + high)/2;
        if(low == high)
        {
            break;
        }
        else if(low == high - 1)
        {
            x = high;
            cout<<"? "<<x<<" "<<y<<endl;
            cin>>S;
            if(S == "NO")
            {
                x = low;
            }
            break;
        }
        cout<<"? "<<x<<" "<<y<<endl;
        cin>>S;
        if(S == "YES")
        {
            low = x;
        }
        else
        {
            high = x-1;
        }
    }
    coordinates[3][0] = x;
    coordinates[3][1] = y;

    area = 4*coordinates[0][0]*coordinates[0][0] + (coordinates[1][1] - coordinates[2][1])*(coordinates[3][0]);
    cout<<"! "<<area<<endl;

    return 0;
} 