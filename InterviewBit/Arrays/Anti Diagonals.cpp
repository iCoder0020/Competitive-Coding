/*
ID: ishan-sang
PROG: Anti Diagonals
LANG: C++                  
*/

vector<int> create(vector<vector<int>> &A, int i, int j)
{
    int N = A.size();
    vector<int>v;
    for(;i>=0 && j>=0 && i<N && j<N; i++,j--)
        v.push_back(A[i][j]);
    return v;
}
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) 
{
    int N = A.size();
    vector<vector<int>> v;
    for(int j = 0; j<N; j++)
        v.push_back(create(A, 0, j));
    for(int i = 1; i<N; i++)
        v.push_back(create(A, i, N-1));
    return v;
}