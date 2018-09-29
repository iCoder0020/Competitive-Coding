/*
ID: icoder_0020
PROG: Ashu and Prime Factors
LANG: C++                  
*/

#include <iostream>
using namespace std;

#define num 1000000

int main()
{
    int n;
    cin>>n;
    int B[num-1];
	int A[num-1];
	for(int i = 0; i<num-1; i++)
	{
		A[i] = i+2;
		B[i] = 0;
	}
	for(int i = 2; i<=1000; i++)
	{
		for(int j = 2; i*j<=num; j++)
		{
			if(A[i*j-2] == i*j)
			{
				A[i*j-2] = i;
			}
		}
	}
	
    for (int i=0;i<n;i++)
    {
        int prime,ans=0;
        cin>>prime;
        if(prime > num/2)
        {
        	B[prime-2] = 1;
        }
        if(B[prime-2] == 0)
        {
        	for (long j=prime-2;j<=num-2;j+=prime)
	        {
	            if(A[j] == prime)
	            	ans++;
	        }
	        B[prime-2] = ans;
        }
      	else
      	{
      		ans = B[prime-2];
      	}
        cout<<ans<<endl;
    }
}