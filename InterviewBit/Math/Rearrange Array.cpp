/*
ID: ishan-sang
PROG: Rearrange Array
LANG: C++                  
*/

void Solution::arrange(vector<int> &A) 
{
    int N = A.size();
    pair<int,int>save;
    int n = 0;
    int idx, tmp, temp;
    vector<bool> vis(N, false);
    while(n<N)
    {
        if(A[n] == A[A[n]])
            vis[n] = true;
        if(!vis[n])
        {
            idx = n;
            save = {idx, A[idx]};
            do
            {
               vis[idx] = true;
                tmp = A[A[idx]];
                temp = A[idx];
                A[idx] = tmp;
                idx = temp;
            }
            while(tmp != save.first);
            A[idx] = save.second;
            vis[idx] = true;
        }
        n++;
    }
}
