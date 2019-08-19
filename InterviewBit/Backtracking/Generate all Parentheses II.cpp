/*
ID: ishan-sang
PROG: Generate all Parentheses II
LANG: C++                  
*/

void f(vector<string>&ans, string &curr, int stk, int cnt, int N)
{
    if(cnt == N)
    {
        if(stk == 0)
            ans.push_back(curr);
        return;
    }
    if(stk == 0)
    {
        curr.push_back('(');
        f(ans, curr, 1, cnt+1, N);
        curr.pop_back();
    }
    else
    {
        curr.push_back('(');
        f(ans, curr, stk+1, cnt+1, N);
        curr.pop_back();
        
        curr.push_back(')');
        f(ans, curr, stk-1, cnt+1, N);
        curr.pop_back();
    }
}
vector<string> Solution::generateParenthesis(int A) 
{
    vector<string> ans;
    string curr;
    f(ans, curr, 0, 0, 2*A);
    sort(ans.begin(), ans.end());
    return ans;
}
