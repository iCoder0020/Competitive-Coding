/*
ID: ishan-sang
PROG: Combination Sum
LANG: C++                  
*/

void f(vector<vector<int>> &ans, vector<int> &include, vector<int> &A, int i, int N, int curr_sum, int target)
{
    if(curr_sum == target)
    {
        vector<int> temp;
        for(int n = 0; n<N; n++)
            for(int i = 0; i<include[n]; i++)
                temp.push_back(A[n]);
        ans.push_back(temp);
        return;
    }
    if(curr_sum > target)
        return;
    for(int j = i; j<N; j++)
    {
        include[j]++;
        f(ans, include, A, j, N, curr_sum + A[j], target);
        include[j]--;
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) 
{
    unordered_set<int>S;
    for(auto it: A)
        S.insert(it);
    A.clear();
    A.assign(S.begin(), S.end());
    sort(A.begin(), A.end());
    
    int N = A.size();
    vector<vector<int>>ans;
    vector<int>include(N, 0);
    
    f(ans, include, A, 0, N, 0, B);
    sort(ans.begin(), ans.end());
    return ans;
}
