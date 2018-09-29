/*
ID: ishan_sang
PROG: ABX01
LANG: C++
*/

#include <iostream>
 
using namespace std;
 
typedef long long int li;
 
li F(li A)
{
    li sum = 0;
    li n;
    while(A != 0)
    {
        n = A%10;
        A /= 10;
        sum += n;
    }
    if(sum/10 == 0)
    {
        return sum; 
    }
    else
    {
        return F(sum);
    }
}
 
int main()
{
    int T;
    cin>>T;
    li A, N;
    int B;
    for(int t = 0; t<T; t++)
    {
        cin>>A>>N;
        A = F(A);
        if(A == 0)
        {
            cout<<A;
        }
        if(A == 1)
        {
            cout<<A;
        }
        if(A == 2)
        {
            N--;
            if(N%6 == 0)
            {
                cout<<"2";
            }
            if(N%6 == 1)
            {
                cout<<"4";
            }
            if(N%6 == 2)
            {
                cout<<"8";
            }
            if(N%6 == 3)
            {
                cout<<"7";
            }
            if(N%6 == 4)
            {
                cout<<"5";
            }
            if(N%6 == 5)
            {
                cout<<"1";
            }
        }
        if(A == 3)
        {
            if(N == 1)
            {
                cout<<"3";
            }
            else
            {
                cout<<"9";
            }
        }
        if(A == 4)
        {
            N--;
            if(N%3 == 0)
            {
                cout<<"4";
            }
            if(N%3 == 1)
            {
                cout<<"7";
            }
            if(N%3 == 2)
            {
                cout<<"1";
            }
        }
        if(A == 5)
        {
            N--;
            if(N%6 == 0)
            {
                cout<<"5";
            }
            if(N%6 == 1)
            {
                cout<<"7";
            }
            if(N%6 == 2)
            {
                cout<<"8";
            }
            if(N%6 == 3)
            {
                cout<<"4";
            }
            if(N%6 == 4)
            {
                cout<<"2";
            }
            if(N%6 == 5)
            {
                cout<<"1";
            }
        }
        if(A == 6)
        {
            if(N == 1)
            {
                cout<<"6";
            }
            else
            {
                cout<<"9";
            }
        }
        if(A == 7)
        {
            N--;
            if(N%3 == 0)
            {
                cout<<"7";
            }
            if(N%3 == 1)
            {
                cout<<"4";
            }
            if(N%3 == 2)
            {
                cout<<"1";
            }
        }
        if(A == 8)
        {
            N--;
            if(N%2 == 0)
            {
                cout<<"8";
            }
            if(N%2 == 1)
            {
                cout<<"1";
            }
        }
        if(A == 9)
        {
            cout<<"9";
        }
        cout<<"\n";
    }
    return 0;
} 
