/*
ID: ishan_sang
PROG: TWOARR
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5; 
int n; 
int tree[2*N];

void build() 
{ 
  	for(int i = n - 1; i > 0; --i) 
  	{
  		tree[i] = tree[i<<1] + tree[i<<1|1];
  	}
}

void modify(int p, int value) 
{  
  	for(tree[p += n] = value; p > 1; p >>= 1) 
  	{
  		tree[p>>1] = tree[p] + tree[p^1];
  	}
}

int query(int l, int r) 
{  
  	int res = 0;
  	for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
  	{
    	if(l&1)
    	{
			res += tree[l++];
		}
    	if(r&1)
    	{
    		res += tree[--r];
    	}
  	}
  	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int Q;
	cin>>n>>Q;
	int choice;
	int A[n];
	for(int i = 0; i<n; i++)
	{
		cin>>A[n];
	}
	for(int i = n; i<2*n; i++)
	{
		tree[i] = A[i-n];
	}
	int B[n];
	for(int i = 0; i<n; i++)
	{
		cin>>B[n];
	}
	build();
	while(Q--)
	{
		cin>>choice;
		if(choice == 1)
		{
			int Z,Y;
			cin>>Z>>Y;
			B[Z-1] = Y;
		}
		else if(choice == 2)
		{
			int L,R,X;
			cin>>L>>R>>X;
			modify()
		}
		else if(choice == 3)
		{
			int L,R;
			cin>>L>>R;
		}
	}
	return 0;
}