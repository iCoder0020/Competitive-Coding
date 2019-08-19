/*
ID: ishan-sang
PROG: Evaluate Expression
LANG: C++                  
*/

int Solution::evalRPN(vector<string> &A) 
{
    stack<int> S;
    int ans = 0;
    for(auto it: A)
    {
        if(it == "+" || it == "-" || it == "*" || it == "/")
        {
            int a = S.top();
            S.pop();
            int b = S.top();
            S.pop();
            if(it == "+")
                S.push(b+a);
            else if(it == "-")
                S.push(b-a);
            else if(it == "*")
                S.push(b*a);
            else
                S.push(b/a);
        }
        else
            S.push(stoi(it));
    }
    return S.top();
}
