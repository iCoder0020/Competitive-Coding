/*
ID: ishan-sang
PROG: Max Continuous Series of 1s
LANG: C++                  
*/

vector<int> Solution::maxone(vector<int> &A, int B) 
{
    int N = A.size();
    vector<int>zero;
    vector<int>ans;
    int start,end,len;
    int max_start,max_end,max_len = -1;
    for(int n = 0; n<N; n++)
        if(A[n] == 0) zero.push_back(n);
    int Z = zero.size();
    if(B>=Z)
        max_start = -1, max_end = N;
    else
    {
        zero.insert(zero.begin(), -1);
        zero.push_back(N);
        for(int i = 0; i<=Z-B; i++)
        {
            start = zero[i];
            end = zero[i+B+1];
            // cout<<start<<" "<<end<<endl;
            len = (end - start);
            if(len > max_len)
            {
                max_start = start, max_end = end;
                max_len = len;
            }
        }
    }
    for(int n = max_start+1; n<=max_end-1; n++)
        ans.push_back(n);
    return ans;
}
