/*
ID: ishan-sang
PROG: Largest Rectangle in Histogram
LANG: C++                  
*/

int Solution::largestRectangleArea(vector<int> &A) 
{
    stack<int>S;
    int N = A.size();
    vector<int> PSE(N, 0);
    vector<int> NSE(N, 0);
    for(int n = 0; n<N; n++)
    {
        while(!S.empty() && A[n]<=A[S.top()])
            S.pop();
        if(!S.empty())
            PSE[n] = S.top();
        else
            PSE[n] = -1;
        S.push(n);
    }
    while(!S.empty())
        S.pop();
    for(int n = N-1; n>=0; n--)
    {
        while(!S.empty() && A[n]<=A[S.top()])
            S.pop();
        if(!S.empty())
            NSE[n] = S.top();
        else
            NSE[n] = N;
        S.push(n);
    }
    // for(auto it: PSE)
    //     cout<<it<<" ";
    // cout<<endl;
    // for(auto it: NSE)
    //     cout<<it<<" ";
    // cout<<endl;
    int ans = 0;
    for(int n = 0; n<N; n++)
    {
        ans = max(ans, A[n]*(NSE[n] - PSE[n] -1));
        // cout<<A[n]<<" "<<NSE[n]<<" "<<PSE[n]<<endl;
    }
    return ans;
}