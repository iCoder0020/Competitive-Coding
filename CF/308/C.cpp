#include <bits/stdc++.h>

using namespace std;

#define int long long

bool rec(int W, int M)
{
	if(M == 1 || W <= 3)
		return true;
	if(M%W == 0)
		return rec(W, M/W);
	if((M-1)%W == 0)
		return rec(W, (M-1)/W);
	if((M+1)%W == 0)
		return rec(W, (M+1)/W);
	return false;
}

int32_t main()
{
	int W,M;
	cin>>W>>M;
	if(rec(W,M))
		cout<<"YES";
	else
		cout<<"NO";
	cout<<endl;
	return 0;
}
