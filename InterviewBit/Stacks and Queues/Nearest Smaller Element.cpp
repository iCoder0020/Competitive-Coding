/*
ID: ishan-sang
PROG: Nearest Smaller Element
LANG: C++                  
*/

vector<int> Solution::prevSmaller(vector<int> &A) 
{
    int N = A.size();
    vector<int>G(N, -1);
    stack<int>S;
    for(int i = 0; i<N; i++)
    {
        while(!S.empty() && S.top()>=A[i])
            S.pop();
        if(S.empty())
            G[i] = -1;
        else
            G[i] = S.top();
        S.push(A[i]);
    }
    return G;
}
