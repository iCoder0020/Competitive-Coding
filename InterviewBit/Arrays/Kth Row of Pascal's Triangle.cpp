/*
ID: ishan-sang
PROG: Kth Row of Pascal's Triangle
LANG: C++                  
*/

vector<int> Solution::getRow(int A) 
{
    vector<int>ans;
    int C = A;
    for(int n = 0; n<=A; n++)
    {
        if(n == 0 || n == A)
            ans.push_back(1);
        else if(n<=A/2)
        {
            ans.push_back(C);
            C = (C*(A-n))/(n+1);
        }
        else
            ans.push_back(ans[A-n]);
    }
    return ans;
}
