/*
ID: ishan_sang
PROG: BEX
LANG: C++                  
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    int temp;
    string name;
    stack<pair<int, string>> books;
    stack<int> mins;
    while(N--)
    {
        cin>>temp;
        if(temp == -1)
        {
            int count = 0;
            while(books.top().first != mins.top())
            {
                count++;
                books.pop();
            }
            cout<<count<<" "<<books.top().second<<endl;
            books.pop();
            mins.pop();
        }
        else
        {
            cin>>name;
            if(temp != 0)
            {
                books.push({temp, name});
                if(mins.empty() || temp <= mins.top())
                {
                    mins.push(temp);
                }
            }
        }
    }
    return 0;
} 