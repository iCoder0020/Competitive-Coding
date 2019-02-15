/*
ID: iCoder0020
PROG: Balanced Brackets
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) 
{
    stack <char> stk;
    string yes = "YES";
    string no = "NO";
    int len = s.length();
    for(int n = 0; n<len; n++)
    {
        if(s[n] == '{' || s[n] == '[' || s[n] == '(')
        {
            stk.push(s[n]);
        }
        else
        {
            if(!stk.empty())
            {
                if(s[n] == '}' && stk.top() == '{')
                {
                    stk.pop();
                }
                else if(s[n] == ')' && stk.top() == '(')
                {
                    stk.pop();
                }
                else if(s[n] == ']' && stk.top() == '[')
                {
                    stk.pop();
                }
                else
                {
                    return no;
                }
            }
            else
            {
                return no;
            }
        }
    }
    if(stk.empty())
    {
        return yes;
    }
    else
    {
        return no;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
