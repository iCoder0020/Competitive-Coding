/*
ID: ishan-sang
PROG: Rain Water Trapped
LANG: C++                  
*/

int Solution::trap(const vector<int> &A) 
{
    int N = A.size();
    stack<int>S;
    int sum = 0;
    int n = 0;
    while(n<N)
    {
        while(!S.empty() && A[n]>A[S.top()])
        {
            int top = S.top();
            S.pop();
            if(S.empty())
                break;
            int d = n-S.top()-1;
            int h = min(A[n], A[S.top()])-A[top];
            sum += d*h;
        }
        S.push(n++);
    }
    return sum;
}
