/*
ID: ishan_sang
PROG: COMPILER
LANG: C++                  
*/
 
#include <bits/stdc++.h>
 
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string S;
        cin>>S;
        int len = S.length();
        stack <char> stk;
        int count = 0;
        int max_count = -1; 
        int start = 0;
        if(S[0] != '>')
        {
            for(int n = 0; n<len; n++)
            {
                if(S[n] == '<')
                {
                    stk.push('<');
                }
                else
                {
                    if(stk.empty())
                    {
                        break;
                    }
                    else
                    {
                        stk.pop();
                        if(stk.empty())
                        {
                            count = n+1;
                        }
                    }
                }
                max_count = max(count, max_count);
            }
        }
        if(max_count == -1)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<max_count<<endl;
        }
    }
    return 0;
} 