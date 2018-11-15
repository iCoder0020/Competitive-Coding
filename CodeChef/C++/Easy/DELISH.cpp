/*
ID: ishan_sang
PROG: DELISH
LANG: C++                  
*/
 
#include <bits/stdc++.h>

using namespace std;

long long int max(long long int a, long long int b)
{
    return (a>b)?a:b;
}

long long int min(long long int a, long long int b)
{
    return (a<b)?a:b;
}

int main()
{
	int T, N;
    cin>>T;
    for(int t = 0; t<T; t++)
    {
        cin>>N;
        int D[N];
        bool all_pos = true;
        bool all_neg = true;
        for(int n = 0; n<N; n++)
        {
            cin>>D[n];

        }

        long long int dp_max[N];
        long long int dp_min[N];

        long long int dp_max_index[N][2];
        long long int dp_min_index[N][2];


        for(int n = 0; n<N; n++)
        {
            for(int m = 0; m<2; m++)
            {
                dp_min_index[n][m] = 0;
                dp_max_index[n][m] = 0;
            }
        }

        for(int n = 0; n<N; n++)
        {
            if(n == 0)
            {
                dp_min[0] = D[0];
                dp_max[0] = D[0];
            }
            else
            {
                if(dp_max[n-1] + D[n]>D[n])
                {
                    dp_max_index[n][0] = dp_max_index[n-1][0];
                    dp_max[n] = dp_max[n-1] + D[n];
                }
                else
                {
                    dp_max_index[n][0] = n;
                    dp_max[n] = D[n];
                }
                dp_max_index[n][1] = n;

                if(dp_min[n-1] + D[n]<D[n])
                {
                    dp_min_index[n][0] = dp_min_index[n-1][0];
                    dp_min[n] = dp_min[n-1] + D[n];
                }
                else
                {
                    dp_min_index[n][0] = n;
                    dp_min[n] = D[n];
                }
                dp_min_index[n][1] = n;
            }
        }

        long long int max_dp_max = -1*INT_MAX;
        long long int min_dp_min = INT_MAX;

        int i,j,k,l;

        for(int n = 0; n<N; n++)
        {
            if(max_dp_max < dp_max[n])
            {
                max_dp_max = dp_max[n];
                i = dp_max_index[n][0];
                j = dp_max_index[n][1];
            }
            if(min_dp_min > dp_min[n])
            {
                min_dp_min = dp_min[n];
                k = dp_min_index[n][0];
                l = dp_min_index[n][1];
            }
        }
        if(k>j || i>l)
        {
            cout<<abs(max_dp_max - min_dp_min)<<endl;
        }
        else
        {
            long long int sum[4] = {0};

            if(i == 0)
            {
                sum[0] = D[0];
            }
            else
            {
                for(int n = i-1; n>=0; n--)
                {
                    sum[0] = min(sum[0]+D[n], D[n]);
                }
            }

            if(j == N-1)
            {
                sum[1] = D[N-1];
            }
            else
            {
                for(int n = j+1; n<N; n++)
                {
                    sum[1] = min(sum[1]+D[n], D[n]);
                }
            }

            if(k == 0)
            {
                sum[2] = D[0];
            }
            else
            {
                for(int n = k-1; n>=0; n--)
                {
                    sum[2] = max(sum[2]+D[n], D[n]);
                }
            }

            if(l == N-1)
            {
                sum[3] = D[N-1];
            }
            else
            {
                for(int n = l+1; n<N; n++)
                {
                    sum[3] = max(sum[3]+D[n], D[n]);
                }
            }

            long long int ans, ans1, ans2;
            ans1 = max(abs(-sum[0]), abs(-sum[1]));
            ans2 = max(abs(sum[2]-), abs(sum[3]-));
            ans=max(ans1,ans2);
            cout<<ans<<endl;
        }
    }
	return 0;
} 