/*
ID: ishan-sang
PROG: 3 Sum
LANG: C++                  
*/

int Solution::threeSumClosest(vector<int> &A, int B) 
{
    int N = A.size();
    sort(A.begin(), A.end());
    int minm = INT_MAX;
    int ans;
    for(int i = 0; i<N-2; i++)
    {
        for(int j = i+1; j<N-1; j++)
        {
            int r = B-A[i]-A[j];
            int idx = lower_bound(A.begin()+j+1, A.end(), r) - A.begin();
            if(idx<N)
            {
                // cout<<A[i]<<" "<<A[j]<<" "<<A[idx]<<endl;
                if(abs(r-A[idx]) < minm)
                {
                    minm = abs(r-A[idx]);
                    ans = A[i]+A[j]+A[idx];
                }
            }
            if(idx-1>=0 && idx-1!=j)
            {
                // cout<<A[i]<<" "<<A[j]<<" "<<A[idx-1]<<endl;
                if(abs(r-A[idx-1]) < minm)
                {
                    minm = abs(r-A[idx-1]);
                    ans = A[i]+A[j]+A[idx-1];
                }
            }
        }
    }
    return ans;
}


