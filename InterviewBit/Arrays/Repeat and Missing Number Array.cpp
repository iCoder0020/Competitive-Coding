/*
ID: ishan-sang
PROG: Repeat and Missing Number Array
LANG: C++                  
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    long long N = A.size();
    long long s = (N*(N+1))/2;
    long long sq = ((N)*(N+1)*(2*N+1))/6;
    long long sum = 0;
    long long sumq = 0;
    for(auto it: A)
        sum += (long long)(it);
    for(auto it: A)
        sumq += (long long)(it)*(long long)(it);
    long long k1 = s - sum;
    long long k2 = sq - sumq;
    long long k3 = k2/k1;
    long long C,D;
    D = (k1+k3)/2;
    C = D-k1;
    vector<int> ans = {C,D};
    return ans;
}
