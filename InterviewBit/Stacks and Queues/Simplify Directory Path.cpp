/*
ID: ishan-sang
PROG: Simplify Directory Path
LANG: C++                  
*/

string Solution::simplifyPath(string A) 
{
    stack<string>S;
    int N = A.length();
    int cnt = 0;
    string s;
    for(int n = 0; n<N; n++)
    {
        if(A[n] == '/')
        {
            cnt = 0;
            continue;
        }
        if(isalpha(A[n]))
        {
            cnt = 0;
            int start = n;
            while(n<N && isalpha(A[n]))
                n++;
            if(n-start>0)
                S.push(A.substr(start, n-start));
        }
        else
        {
            if(A[n] == '.')
                cnt++;
            if(cnt == 2 && !S.empty())
                S.pop();
        }
    }
    string B = "";
    while(!S.empty())
    {
        B = S.top() + "/" + B;
        S.pop();
    }
    if(B.size() > 1 && B[B.length()-1] == '/')
        B = B.substr(0, B.length()-1);
    B = "/"+B;
    return B;
}
