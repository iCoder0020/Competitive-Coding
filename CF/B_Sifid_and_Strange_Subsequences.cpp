#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int TC;
    cin>>TC;
    while(TC--)
    {
        int N;
        cin>>N;
        vector<int>A(N);
        for(int n = 0; n<N; n++)
            cin>>A[n];
        sort(A.begin(), A.end());
        // for(int x: A)
        //     cout<<x<<" ";
        // cout<<endl;
        multiset<int>mset;
        for(int n = 0; n<N-1; n++)
            mset.insert(A[n+1]-A[n]);
        // for(int x: mset)
        //     cout<<x<<" ";
        // cout<<endl;
        for(int n = N-1; n>=1; n--)
        {
            // cout<<n<<" "<<*mset.begin()<<" "<<A[n]<<endl;
            if(*mset.begin() >= A[n])
                break;
            mset.erase(mset.lower_bound(A[n]-A[n-1]));
        }
        cout<<mset.size()+1<<endl;
    }
    return 0;
}