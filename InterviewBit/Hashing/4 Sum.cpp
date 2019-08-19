/*
ID: ishan-sang
PROG: 4 Sum
LANG: C++                  
*/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) 
{
    int N = A.size();
    sort(A.begin(), A.end());
    set<vector<int>> ans;
    unordered_map<int, int> M;
    for(int n = 0; n<N; n++)
        M[A[n]] = n;
    for(int i = 0; i<N-3; i++)
    {
        for(int j = i+1; j<N-2; j++)
        {
            for(int k = j+1; k<N-1; k++)
            {
                int t = B-A[i]-A[j]-A[k];
                if(M.find(t) != M.end() && M[t]>k)
                    ans.insert({A[i], A[j], A[k], t});
            }
        }
    }
    vector<vector<int>> ans2 (ans.begin(), ans.end());
    return ans2;
}
