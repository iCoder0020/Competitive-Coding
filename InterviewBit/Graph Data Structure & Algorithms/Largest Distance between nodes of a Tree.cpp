/*
ID: ishan-sang
PROG: Largest Distance between nodes of a Tree
LANG: C++                  
*/

vector<int> longest_path(int root, vector<vector<int>>&adj_list)
{
    vector<int>p, lp, prev;
    p.push_back(root);
    lp = p;
    prev = p;
    for(auto it: adj_list[root])
    {
        vector<int>temp = longest_path(it,adj_list);
        p.insert(p.end(), temp.begin(), temp.end());
        if(p.size()>lp.size())
            lp = p;
        p = prev;
    }
    // for(auto it: lp)
    //     cout<<it<<" ";
    // cout<<endl;
    return lp;
}
int Solution::solve(vector<int> &A) 
{
    int N = A.size();
    vector<vector<int>>adj_list(N);
    int root;
    string temp = "";
    for(int n = 0; n<N; n++)
    {
        if(A[n]!=-1)
            adj_list[A[n]].push_back(n);
        else
            root = n;
    }
    vector<int> lp = longest_path(root, adj_list);
    int lp_len = lp.size();
    int max_ans = lp_len;
    for(int n = 0; n<lp_len-1; n++)
    {
        int a = lp_len - n;
        for(auto it: adj_list[lp[n]])
        {
            if(it == lp[n+1])
                continue;
            int b = longest_path(it, adj_list).size();
            max_ans = max(max_ans, a+b);
        }
    }
    return max_ans-1;
}
