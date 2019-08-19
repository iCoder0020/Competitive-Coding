/*
ID: ishan-sang
PROG: Reverse String
LANG: C++                  
*/

string Solution::reverseString(string A) 
{
    stack<char>S;
    for(auto it: A)
        S.push(it);
    int n = 0;
    while(!S.empty())
    {
        A[n++] = S.top();
        S.pop();
    }
    return A;
}   
