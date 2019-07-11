/*
ID: ishan-sang
PROG: Max Non Negative SubArray
LANG: C++                  
*/

vector<int> Solution::maxset(vector<int> &A) {
    long long int sum, i = 0;
    vector<int> ans;
    long long int max_sum = 0;
    int N = A.size();
    int max_i = N, max_j = 0;
    
    for(int n = 0; n<N; n++)
    {
        while(n<N && A[n]>=0)
        {
            sum += A[n];
            n++;
        }
        if(sum >= max_sum)
        {
            
            if(sum > max_sum || max_j - max_i < n-1-i)
            {
                max_i = i;
                max_j = n-1;
            }
            max_sum = sum;
        }
        i = n+1;
        sum = 0;
    }
    // cout<<max_i<<" "<<max_j<<endl;
    if(max_i != -1)
        for(int n = max_i; n<=max_j; n++)
            ans.push_back(A[n]);
    return ans;
}
