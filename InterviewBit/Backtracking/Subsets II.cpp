/*
ID: ishan-sang
PROG: Subsets II
LANG: C++                  
*/

void recurse(vector<int> &A, vector<bool> &include, set<vector<int>> &ans, int i , int N)
{
    if(i == N)
    {
        vector<int>temp;
        for(int n = 0; n<N; n++)
            if(include[n])
                temp.push_back(A[n]);
        ans.insert(temp);
        return;
    }
    include[i] = false;
    recurse(A, include, ans, i+1, N);
    include[i] = true;
    recurse(A, include, ans, i+1, N);
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) 
{
    int N = A.size();
    vector<bool> include(N);
    set<vector<int>> ans;
    sort(A.begin(), A.end());
    recurse(A, include, ans, 0, N);
    vector<vector<int>> ans2;
    for(auto it: ans)
        ans2.push_back(it);
    return ans2;
}
