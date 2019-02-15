/*
ID: icoder_0020
PROG: SUBSUMS
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main() 
{
    li N,low,high;
    cin>>N>>low>>high;
    
    li count = 0;
    
    if(low*high <= 0)
    {
        count++;
    }
    
    vector <int> A;
    vector <int> B;
    int temp;
    for(int n = 0; n<N; n++)
    {
        cin>>temp;
        if(n <= N/2)
        {
            A.push_back(temp);
        }
        else
        {
            B.push_back(temp);
        }
    }
    int a = A.size();
    int b = B.size();
    
    vector <int> sumA;
    vector <int> sumB;
    
    set <int> answers;
    
    li sum;
    
    for(int i = 1; i<(1<<a); i++)
    {
        sum = 0;
        for(int j = 0; j<a; j++)
        {
            if(i&(1<<j))
            {
                sum += A[j];
            }
        }
        sumA.push_back(sum);
        if(sum >= low && sum <= high)
        {
            count++;
        }
    }
    
    for(int i = 1; i<(1<<b); i++)
    {
        sum = 0;
        for(int j = 0; j<b; j++)
        {
            if(i&(1<<j))
            {
                sum += B[j];
            }
        }
        sumB.push_back(sum);
        if(sum >= low && sum <= high)
        {
            count++;
        }
    }
    
    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());
    
    for(int i = 0; i<sumA.size(); i++)
    {
        li m1 = low - sumA[i];
        li m2 = high - sumA[i];
        auto it1 = lower_bound(sumB.begin(), sumB.end(), m1);
        auto it2 = upper_bound(sumB.begin(), sumB.end(), m2);
        count += it2-it1;
    }
    
    cout<<count<<endl;
    
    return 0;
}