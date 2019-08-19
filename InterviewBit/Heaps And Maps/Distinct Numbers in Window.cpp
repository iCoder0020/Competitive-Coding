/*
ID: ishan-sang
PROG: Distinct Numbers in Window
LANG: C++                  
*/

vector<int> Solution::dNums(vector<int> &A, int B) 
{
    int N = A.size();
    vector<int> ans;
    if(B>N)
        return ans;
    int i = 0;
    unordered_map<int,int> M;
    for(int n = 0; n<N; n++)
    {
        M[A[n]]++;
        if(n-i+1 == B)
        {
            ans.push_back(M.size());
            M[A[i]]--;
            if(M[A[i]] == 0)
                M.erase(A[i]);
            i++;
        }
    }
    return ans;
}
