/*
ID: iCoder0020
PROG: Mini-Max Sum
LANG: C++                  
*/

#include <iostream>

using namespace std;

void sort(long a[5])
{
    for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(a[i]>a[j])
            {
                a[i]+=a[j];
                a[j]=a[i]-a[j];
                a[i]-=a[j];
            }
        }
    }
}

int main() {
    long a[5],sum=0,m1=0,m2=0;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a);
    cout<<sum-a[4]<<" "<<sum-a[0]<<"\n";
    return 0;
}
