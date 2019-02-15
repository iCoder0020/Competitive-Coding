/*
ID: iCoder0020
PROG: Maximum Element
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Q;
    cin>>Q;
    stack <int> s;
    stack <int> max;
    int operation;
    int temp;
    while(Q--)
    {
        cin>>operation;
        switch(operation)
        {
            case 1:
                cin>>temp;
                if(s.empty())
                {
                    s.push(temp);
                    max.push(temp);
                }
                else
                {
                    s.push(temp);
                    if(temp > max.top())
                    {
                        max.push(temp);
                    }
                    else
                    {
                        max.push(max.top());
                    }
                }
                break;
            case 2:
                s.pop();
                max.pop();
                break;
            case 3:
                cout<<max.top()<<endl;
                break;
        }
    }
    return 0;
}