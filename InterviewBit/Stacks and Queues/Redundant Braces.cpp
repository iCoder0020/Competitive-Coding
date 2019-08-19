/*
ID: ishan-sang
PROG: Redundant Braces
LANG: C++                  
*/

int Solution::braces(string A) 
{
    stack<int>S;
    int N = A.length();
    int temp;
    int cnt = 0;
    int brack = 0;
    for(int n = 0; n<N; n++)
    {
        
        temp = -1;
        if(A[n] == '+' || A[n] == '-' || A[n] == '*' || A[n] == '/')
            cnt++;
        if(A[n] == '(')
            S.push(n);
        else if(A[n] == ')')
        {
            brack++;
            while(n<N && A[n] == ')')
            {
                if((n<N && A[n] == ')' && temp == S.top()+1) || (n-S.top()<=2))
                {
                    // cout<<temp<<" "<<S.top()<<endl;
                    return 1;
                }
                temp = S.top();
                S.pop();
                n++;
            }
        }
    }
    if(cnt <= 1 && brack!=0)
        return 1; 
    return 0;
}
