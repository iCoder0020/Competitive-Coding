/*
ID: ishan-sang
PROG: Tushar's Birthday Bombs
LANG: C++                  
*/

vector<int> Solution::solve(int A, vector<int> &B) 
{
    int N = B.size();
    int minm_idx = 0;
    for(int n = 0; n<N; n++)
        if(B[n] < B[minm_idx])
            minm_idx = n;
    int x = B[minm_idx];
    vector<int>ans;
    int rem = A%x;
    ans.resize(A/x, minm_idx);
    if(rem != 0)
    {
        int idx = 0;
        int n = 0;
        while(n<minm_idx)
        {
            while(rem - (B[n]-x) >= 0 && idx<ans.size())
            {
                rem -= (B[n]-x);
                ans[idx] = n;
                idx++;
            }
            if(rem == 0)
                break;
            n++;
        }
    }
    return ans;
}
