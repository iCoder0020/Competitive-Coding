#include <bits/stdc++.h>

using namespace std;

#define int long long

map<int,int>p2;
vector<int>seg;

void build(int i, int op, int end)
{
	if(i >= end)
		return;
	build(2*i, op^1, end);
	build(2*i+1, op^1, end);
	int l = seg[2*i];
	int r = seg[2*i+1];
	if(op == 0)
		seg[i] = l^r;
	else
		seg[i] = l|r;
}

void update(int i, int op)
{
	if(i == 0)
		return;
	int l = seg[2*i];
	int r = seg[2*i+1];
	if(op == 0)
		seg[i] = l^r;
	else
		seg[i] = l|r;
	update(i/2, op^1);
}

int32_t main()
{
	int N,M;
	cin>>N>>M;
	p2[0] = 1;
	for(int n = 1; n<=N+1; n++)
		p2[n] = 2*p2[n-1];
	seg.resize(p2[N+1], -1);
	for(int n = p2[N]; n<p2[N+1]; n++)
		cin>>seg[n];
	build(1, N&1, p2[N]);
	while(M--)
	{
		int i,x;
		cin>>i>>x;
		seg[i+p2[N]-1] = x;
		update((i+p2[N]-1)/2, 1);
		cout<<seg[1]<<endl;
	}
	return 0;
}