/*
ID: ishan-sang
PROG: Counting Triangles
LANG: C++                  
*/

#define MOD 1000000007
int Solution::nTriang(vector<int> &A) 
{
    int N = A.size();
    sort(A.begin(), A.end());
    long long int ans = 0;
    for(int i = 0; i<N-2; i++)
    {
        for(int j = i+1; j<N-1; j++)
        {
            int k = lower_bound(A.begin()+j+1, A.end(), A[i]+A[j]) - A.begin();
            ans = (ans + (k-j-1))%MOD;
            // cout<<i<<" "<<j<<" "<<k<<" "<<ans<<endl;
        }
    }
    return ans;
}

