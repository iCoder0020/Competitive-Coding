/*
ID: ishan-sang
PROG: Subset
LANG: C++                  
*/

void recurse(vector<int> &A, vector<bool> &include, vector<vector<int>> &ans, int i , int N)
{
    if(i == N)
    {
        vector<int>temp;
        for(int n = 0; n<N; n++)
            if(include[n])
                temp.push_back(A[n]);
        ans.push_back(temp);
        return;
    }
    include[i] = false;
    recurse(A, include, ans, i+1, N);
    include[i] = true;
    recurse(A, include, ans, i+1, N);
}
vector<vector<int> > Solution::subsets(vector<int> &A) 
{
    int N = A.size();
    vector<bool> include(N);
    vector<vector<int>> ans;
    sort(A.begin(), A.end());
    recurse(A, include, ans, 0, N);
    sort(ans.begin(), ans.end());
    return ans;
}
