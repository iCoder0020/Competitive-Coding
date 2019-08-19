/*
ID: ishan-sang
PROG: Combination Sum II
LANG: C++                  
*/

void f(set<vector<int>> &ans, vector<bool> &include, vector<int> &A, int i, int N, int curr_sum, int target)
{
    if(curr_sum == target)
    {
        vector<int> temp;
        for(int n = 0; n<N; n++)
            if(include[n])
                temp.push_back(A[n]);
        ans.insert(temp);
        return;
    }
    if(curr_sum > target || i>=N)
        return;
    include[i] = true;
    f(ans, include, A, i+1, N, curr_sum + A[i], target);
    include[i] = false;
    f(ans, include, A, i+1, N, curr_sum, target);
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) 
{
    sort(A.begin(), A.end());
    
    int N = A.size();
    set<vector<int>>ans;
    vector<bool>include(N);
    
    f(ans, include, A, 0, N, 0, B);
    vector<vector<int>> ans2;
    for(auto it: ans)
        ans2.push_back(it);
    return ans2;
}
