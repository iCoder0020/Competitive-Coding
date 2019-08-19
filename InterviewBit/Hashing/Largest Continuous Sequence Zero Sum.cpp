/*
ID: ishan-sang
PROG: Largest Continuous Sequence Zero Sum
LANG: C++                  
*/

vector<int> Solution::lszero(vector<int> &A) 
{
    int N = A.size();
    vector<int> pre(N, 0);
    map<int,int> MAP;
    int start = 0, end = -1;
    for(int n = 0; n<N; n++)
    {
        if(n == 0)
            pre[n] = A[n];
        else
            pre[n] = pre[n-1] + A[n];
        if(pre[n] == 0)
            end = n;
        MAP[pre[n]] = n;
    }
    
    for(int n = 0; n<N; n++)
    {
        if(MAP.find(pre[n]) != MAP.end())
        {
            if(end-start < MAP[pre[n]]-n-1)
                start = n+1, end = MAP[pre[n]];
        }
    }
    vector<int> ans;
    for(int n = start; n<=end; n++)
        ans.push_back(A[n]);
    return ans;
}
