/*
ID: iCoder0020
PROG: Valid Parentheses
LANG: C++                  
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char>S;
        for(auto it: s)
        {
            if(it == ')')
            {
                if (S.empty() || S.top() != '(')
                    return false ;
                else
                    S.pop();
            }
            else if(it == '}')
            {
                if (S.empty() || S.top() != '{')
                    return false ;
                else
                    S.pop();
            }
            else if(it == ']')
            {
                if (S.empty() || S.top() != '[')
                    return false ;
                else
                    S.pop();
            }
            else
                S.push(it);
        }
        return S.empty();
    }
};