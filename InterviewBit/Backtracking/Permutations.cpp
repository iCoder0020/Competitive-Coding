/*
ID: ishan-sang
PROG: Permutations
LANG: C++                  
*/

void f(set<vector<int>> &S, vector<int>&A, vector<int> &curr, set<int> &used, int i, int N)
{
    if(i == N)
    {
        S.insert(curr);
        return;
    }
    for(auto it: A)
    {
        if(used.find(it) == used.end())
        {
            used.insert(it);
            curr.push_back(it);
            f(S, A, curr, used, i+1, N);
            used.erase(it);
            curr.pop_back();
        }
    }
}
vector<vector<int>> Solution::permute(vector<int> &A) 
{
    int N = A.size();
    vector<vector<int>> ans;
    set<int> used;
    vector<int> curr;
    set<vector<int>> S;
    f(S, A, curr, used, 0, N);
    for(auto it: S)
        ans.push_back(it);
    return ans;
}
