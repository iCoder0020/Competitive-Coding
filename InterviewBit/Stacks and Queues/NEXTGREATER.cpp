/*
ID: ishan-sang
PROG: NEXTGREATER
LANG: C++                  
*/

vector<int> Solution::nextGreater(vector<int> &A) 
{
    int N = A.size();
    vector<int>NGE(N, 0);
    stack<int>S;
    for(int n = N-1; n>=0; n--)
    {
        // cout<<n<<endl;
        while(!S.empty() && A[n]>=S.top())
            S.pop();
        if(S.empty())
            NGE[n] = -1;
        else
            NGE[n] = S.top();
        S.push(A[n]);
    }
    return NGE;
}
