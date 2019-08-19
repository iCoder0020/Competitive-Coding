/*
ID: ishan-sang
PROG: Highest Product
LANG: C++                  
*/

int Solution::maxp3(vector<int> &A) 
{
    vector<int> pos;
    vector<int> neg;
    bool zero = false;
    
    if(A.size() < 3)
        return 0;
    if(A.size() == 3)
        return A[0]*A[1]*A[2];
    for(auto it: A)
    {
        if(it == 0)
            zero = true;
        else if(it<0)
            neg.push_back(it);
        else
            pos.push_back(it);
    }
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end(), greater<int>());
    if(pos.size() == 0)
    {
        if(zero)
            return 0;
        else
            return neg[0]*neg[1]*neg[2];
    }
    int ans1 = 0, ans2 = 0;
    if(pos.size()>=3)
        ans1 = pos[0]*pos[1]*pos[2];
    if(neg.size()>=2)
        ans2 = pos[0]*neg[neg.size()-1]*neg[neg.size()-2];
    return max(ans1, ans2);
    
}
