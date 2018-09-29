#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T,N;
    long long int sum;
    int start,end;
    int ans, temp;
    int flag;
    long long int d;
    cin>>T;
    for(int t = 0; t<T; t++)
    {
        temp = 0;
        flag = 0;
        cin>>N>>d;
        ans = 2*N;
        vector <long int> A(N);
        sum = 0;
        for(int n = 0; n<N; n++)
        {
            int k = 0;
            cin>>A[n];
            if(d <= 0 && A[n] >= 0)
            {
                cout<<"1\n";
                flag = 1;
                break;
            }
            sum += A[n];
            if(sum >= d)
            {
                ans = min(ans, n-temp+1);
                while(sum >= d)
                {
                    sum -= A[temp+k];
                    k++;
                    ans--;
                }
                ans++;
                temp = n+1;
                sum = 0;
            }
        }
        if(ans <= N && !flag)
        {
            cout<<ans<<"\n";
        }
        if(ans > N && !flag)
        {
            cout<<"-1\n";
        }
    }
    return 0;
}