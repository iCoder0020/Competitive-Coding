//https://codeforces.com/contest/356/problem/A

#include <bits/stdc++.h>

using namespace std;

// #define int long long
#define p segtree[i]
#define lc segtree[2*i]
#define rc segtree[2*i+1]

struct node
{
	int l;
	int r;
	bool done;
	int push_down;
};

int N;
int TS, TLS;
vector<node>segtree;

void build(int i)
{
	if(i>=TLS)
		return;
	build(i*2);
	build(i*2+1);
	p = {lc.l, rc.r, false, -1};
	p.done = lc.done && rc.done;
}

void push(int i, int x)
{
	if(p.done)
		return;
	if(i >= TLS || p.push_down == -1)
	{
		if(i>=TLS && i-TLS != x-1)
			p.done = true;
		p.push_down = x;
		return;
	}
	push(2*i, p.push_down);
	push(2*i+1, p.push_down);
	p.push_down = x;
	p.done = lc.done && rc.done;
}

void update(int i, int left, int right, int x)
{
	if(p.l>right || p.r<left || p.done)
		return;
	if(p.push_down != -1)
		push(i, p.push_down);
	if(p.l == left && p.r == right)
	{
		push(i, x);
		return;
	}
	int mid = (p.l+p.r-1)/2;
	update(2*i, left, min(mid,right), x);
	update(2*i+1, max(left,mid+1), right, x);
	
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>N;
	TS = 2*pow(2,ceil(log2(N)));
	TLS = TS/2;
	segtree.resize(TS);
	for(int n = TLS; n<TS; n++)
	{
		segtree[n] = {n-TLS,n-TLS,false,-1};
		if(n-TLS>=N)
			segtree[n].done = true;
	}
	build(1);
	int M;
	cin>>M;
	while(M--)
	{
		int x,y,v;
		cin>>x>>y>>v;
		update(1,x-1,y-1,v);
	}
	for(int i = 1; i<TLS; i++)
		push(i, segtree[i].push_down);
	for(int i = TLS; i<TLS+N; i++)
	{
		if(!segtree[i].done)
			segtree[i].push_down = 0;
		cout<<segtree[i].push_down<<" ";
	}
	cout<<endl;
	return 0;
}