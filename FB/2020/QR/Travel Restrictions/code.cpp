#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin>>TC;
    for(int tc = 0; tc<TC; tc++)
    {
        int N;
        cin>>N;
        char A[2][N];
        for(int n = 0; n<2; n++)
            for(int j = 0; j<N; j++)
                cin>>A[n][j];
        vector<vector<char>>v(N,vector<char>(N,'N'));
        for(int i = 0; i<N; i++)
        {
            v[i][i] = 'Y';
            if(A[1][i] == 'N')
                continue;
            for(int j = i+1; j<N; j++)
            {
                if(A[0][j] == 'Y' && A[1][j-1] == 'Y')
                    v[i][j] = 'Y';
                else
                    break;
            }
            for(int j = i-1; j>=0; j--)
            {
                if(A[0][j] == 'Y' && A[1][j+1] == 'Y')
                    v[i][j] = 'Y';
                else
                    break;
            }
        }
        cout<<"Case #"<<tc+1<<": "<<endl;
        for(auto it: v)
        {
            for(auto jt:it)
                cout<<jt;
            cout<<endl;
        }
    }
    return 0;
}