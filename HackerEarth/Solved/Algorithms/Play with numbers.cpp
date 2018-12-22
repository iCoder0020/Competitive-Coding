/*
ID: icoder_0020
PROG: Play with numbers
LANG: C++                  
*/

#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n,x;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    cin>>x;
    for (int j=0;j<x;j++)
    { 
    	int key,a;
    	int low=0,high=n-1;
    	cin>>key;
    	int mid;
 		while (low<=high)
        {
            mid=(low+high)/2;
            if (arr[mid]>key)
                high=mid-1;
            else if (arr[mid]<key)
              	low=mid+1;
            else
            {
              a=mid;
              break;
          	}
        }
        cout<<a+1<<endl;
    }
    return 0;
}