/*
ID: iCoder0020
PROG: Devu and his Brother
LANG: C++                  
*/

#include <bits/stdc++.h>

#define in_arr(low, high, arr) for(int i = low; i<high; i++) cin>>arr[i]
#define int long long int

using namespace std;

int f(int arrA[], int arrB[], int A, int B, int K)
{
	int count = 0;
	for(int a = 0; a<A; a++)
	{
		if(arrA[a] < K)
		{
			count+= K-arrA[a];
		}
	}
	for(int b = 0; b<B; b++)
	{
		if(arrB[b] > K)
		{
			count+= arrB[b]-K;
		}
	}
	return count;
}

int32_t main()
{
	int A,B;
	cin>>A>>B;
	int arrA[A], arrB[B];
	in_arr(0, A, arrA);
	in_arr(0, B, arrB);
	int low = 0;
	int high = 1e9;
	int mid1, mid2;
	int ans = 1e16;
	while(1)
	{
		mid1 = low + (high-low)/3;
		mid2 = high - (high-low)/3;
		// cout<<low<<" "<<mid1<<" "<<mid2<<" "<<high<<endl;
		if(high-low <= 2)
		{
			ans = min(ans, f(arrA, arrB, A, B, low));
			ans = min(ans, f(arrA, arrB, A, B, (low+high)/2));
			ans = min(ans, f(arrA, arrB, A, B, high));
			break;
		}
		else if(f(arrA, arrB, A, B, mid1) < f(arrA, arrB, A, B, mid2))
		{
			high = mid2;
			ans = min(ans, f(arrA, arrB, A, B, mid1));
			ans = min(ans, f(arrA, arrB, A, B, mid2));
		}
		else
		{
			low = mid1;
			ans = min(ans, f(arrA, arrB, A, B, mid1));
			ans = min(ans, f(arrA, arrB, A, B, mid2));
		}
	}
	cout<<ans<<endl;
	return 0;
}