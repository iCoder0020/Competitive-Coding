/*
ID: ishan-sang
PROG: Magician and Chocolates
LANG: C++                  
*/

#define MOD 1000000007
int Solution::nchoc(int A, vector<int> &B) 
{
    int N = B.size();
    priority_queue<int> PQ;
    for(auto it: B)
        PQ.push(it);
    int cnt = 0;
    long long int sum = 0;
    while(cnt<A)
    {
        int c = PQ.top();
        PQ.pop();
        PQ.push(c/2);
        sum = (sum+c)%MOD;
        cnt++;
    }
    return sum;
}
