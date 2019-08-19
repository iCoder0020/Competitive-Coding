/*
ID: ishan-sang
PROG: N max pair combinations
LANG: C++                  
*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B) 
{
    int N = A.size();
    vector<int> ans;
    priority_queue<pair<int,pair<int,int>>>PQ;
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    for(int i = 0; i<N; i++)
        PQ.push({A[i]+B[0], {i,0}});
    while(ans.size() < N)
    {
        int sum = PQ.top().first;
        int i = PQ.top().second.first;
        int j = PQ.top().second.second;
        PQ.pop();
        ans.push_back(sum);
        if(j+1>=N)
            continue;
        PQ.push({A[i]+B[j+1], {i,j+1}});
    }
    return ans;
}
