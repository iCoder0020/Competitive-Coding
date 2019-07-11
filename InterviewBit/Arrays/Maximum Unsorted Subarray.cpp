/*
ID: ishan-sang
PROG: Maximum Unsorted Subarray
LANG: C++                  
*/

vector<int> Solution::subUnsort(vector<int> &A) 
{
    int i;
    int idx1 = -1, idx2 = -1;
    vector<int> ans;
    int N = A.size();
    for(i = 0; i<N-1; i++)
    {
        if(A[i] > A[i+1])
        {
            if(idx1 == -1)
                idx1 = i;
            else
                idx2 = i+1;
        }
    }
    if(idx1 == -1)
        ans.push_back(-1);
    else if(idx2 == -1)
    {
        int a = upper_bound(A.begin(), A.begin()+idx1, A[idx1+1]) - A.begin();
        int b = lower_bound(A.begin()+idx1, A.end(), A[idx1]) - A.begin() -1;
        ans.insert(ans.end(), {a,b});
    }
    else
    {
        int mn,mx;
        mn = mx = A[idx1];
        for(i = idx1; i<=idx2; i++)
        {
            mn = min(mn, A[i]);
            mx = max(mx, A[i]);
        }
        int a = upper_bound(A.begin(), A.begin()+idx1, mn) - A.begin();
        int b = lower_bound(A.begin()+idx2, A.end(), mx) - A.begin() -1;
        ans.insert(ans.end(), {a,b});
    }
    return ans;
}

