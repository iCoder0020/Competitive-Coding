/*
ID: ishan-sang
PROG: Smallest sequence with given Primes
LANG: C++                  
*/

void bfs(unordered_map<int,int> &M, vector<int> &primes,  priority_queue<int, vector<int>, greater<int>>&PQ, vector<int> &ans, int D)
{
    PQ.push(1);
    while(ans.size() < D+1)
    {
        int top = PQ.top();
        PQ.pop();
        ans.push_back(top);
        for(auto it: primes)
        {
            if(M.find(it*top) == M.end())
            {
                PQ.push(it*top);
                M[it*top] = 1;
            }
        }
    }
}
vector<int> Solution::solve(int A, int B, int C, int D) 
{
    vector<int> primes = {A,B,C};
    vector<int>ans;
    priority_queue<int, vector<int>, greater<int>>PQ;
    unordered_map<int,int> M;
    sort(primes.begin(), primes.end());
    bfs(M, primes, PQ, ans, D);
    ans.erase(ans.begin());
    return ans;
}
