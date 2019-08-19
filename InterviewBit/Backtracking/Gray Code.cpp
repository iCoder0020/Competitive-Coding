/*
ID: ishan-sang
PROG: Gray Code
LANG: C++                  
*/

void f(vector<string> &L, int i, int N)
{
    if(i == N)
        return;
    // for(auto it: L)
    //     cout<<it<<" ";
    // cout<<endl;
    vector<string> temp = L;
    reverse(temp.begin(), temp.end());
    for(int n = 0; n<L.size(); n++)
    {
        L[n] = "0" + L[n];
        temp[n] = "1" + temp[n];
    }
    L.insert(L.end(), temp.begin(), temp.end());
    f(L, i+1, N);
}
vector<int> Solution::grayCode(int A) 
{
    vector<int> pow2(A, 1);
    vector<string> L = {"0", "1"};
    vector<int> ans;
    if(A == 0)
        return ans;
    for(int a = 0; a<A; a++)
    {
        if(a != 0)
            pow2[a] = 2*pow2[a-1];
    }
    f(L, 1, A);
    for(auto it: L)
    {
        int num = 0;
        for(int a = 0; a<A; a++)
        {
            if(it[a] == '1')
                num += pow2[A-a-1];
        }
        ans.push_back(num);
    }
    return ans;
}
