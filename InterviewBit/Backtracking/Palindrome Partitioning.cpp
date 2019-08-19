/*
ID: ishan-sang
PROG: Palindrome Partitioning
LANG: C++                  
*/

bool check_palindrome(string A, int N)
{
    for(int n = 0; n<N/2; n++)
        if(A[n] != A[N-n-1])
            return false;
    return true;
}

void f(vector<vector<string>> &ans, vector<string> &curr, string A, int i, int N)
{
    if(i>=N)
        ans.push_back(curr);
    for(int n = 1; n<=N; n++)
    {
        for(int j = i; j+n-1<N; n++)
        {
            string temp = A.substr(j, n);
            if(check_palindrome(temp, n))
            {
                curr.push_back(temp);
                f(ans, curr, A, j+n, N);
                curr.pop_back();
            }
        }
    }
}

vector<vector<string>> Solution::partition(string A) 
{
    vector<vector<string>> ans;
    vector<string> curr;
    int N = A.length();
    f(ans, curr, A, 0, N);
    sort(ans.begin(), ans.end());
    return ans;
}
