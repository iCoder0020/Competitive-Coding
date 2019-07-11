/*
ID: ishan-sang
PROG: Largest Number
LANG: C++                  
*/

bool comp(const string &A, const string &B)
{
    return A+B>B+A;
}
string Solution::largestNumber(const vector<int> &A) 
{
    vector<string> B;
    string ans = "";
    int N = A.size();
    for(int i = 0; i<N; i++)
    {
        if(A[i]!=0)
            break;
        if(i == N-1)
            return "0";
    }
    for(int i = 0; i<N; i++)
        B.push_back(to_string(A[i]));
    sort(B.begin(), B.end(), comp);
    for(auto it: B)
        ans += it;
    return ans;
}