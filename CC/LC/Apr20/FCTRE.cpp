#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono; 

#define int long long
#define MOD 1000000007
#define MAX 1000005

//for prime factorisation
vector<bool>primes;
vector<int>spf;
vector<int>spf1;
vector<int>spf2;

//for input
int N;
vector<vector<int>>g;
vector<int>A;

//for tree traversal
vector<bool>vis;

//for RMQ using segment trees
vector<int>seg_tree;
int sz;

//for finding LCA
vector<int>levels;
vector<int>dfslabels;
vector<int>first_occurence;

//for storing answers for queries (1,x)
vector<map<int,int>>root_answers;

//for answer
map<int,int>factors;

int power(int a, int b)
{
	if(b == 0)
		return 1;
	if(b == 1)
		return a;
	int c = power(a,b/2);
	if(b&1)
		return a*c*c;
	return c*c;
}

int divnum(int a, int b)
{
	int lo = 1, hi = 20, mid;
	while(lo<hi)
	{
		mid = lo + (hi-lo+1)/2;
		if(b%(power(a,mid)) == 0)
			lo = mid;
		else
			hi = mid-1;
	}
	return lo;
}

void inc_factors(int x)
{
	while(x != 1)
	{
		factors[spf[x]]+=spf1[x];
		x/=spf2[x];
	}
}

void dec_factors(int x)
{
	while(x != 1)
	{
		factors[spf[x]]-=spf1[x];
		x/=spf2[x];
	}
}

int path(int u, int v)
{
	vis[u] = true;
	inc_factors(A[u]);
	root_answers[u] = factors;
	if(u == v)
		return 1;
	for(auto it: g[u])
	{
		if(vis[it])
			continue;
		int x = path(it,v);
		if(x != -1)
			return 1;
	}
	dec_factors(A[u]);
	return -1;
}

void precalculate1()
{
	primes.clear();
	primes.resize(MAX, true);

	spf.clear();
	spf.resize(MAX, -1);

	primes[0] = primes[1] = false;
	for(int i = 2; i<MAX; i++)
	{
		if(primes[i])
		{
			for(int j = 2; i*j<MAX; j++)
			{
				if(spf[i*j] == -1)
					spf[i*j] = i;
				primes[i*j] = false;
			}
		}
	}
	for(int i = 1; i<MAX; i++)
	{
		if(spf[i] == -1)
			spf[i] = i;
	}

	spf1.clear();
	spf1.resize(MAX, -1);

	for(int i = 1; i<MAX; i++)
		spf1[i] = divnum(spf[i],i);

	spf2.clear();
	spf2.resize(MAX, -1);

	for(int i = 1; i<MAX; i++)
		spf2[i] = power(spf[i], spf1[i]);
}

void print(vector<int>&x)
{
	for(auto it: x)
		cout<<it<<" ";
	cout<<endl;
}

void dfs(int u, int lvl)
{
	vis[u] = true;
	dfslabels.push_back(u);
	levels.push_back(lvl);
	for(auto it: g[u])
	{
		if(!vis[it])
		{
			dfs(it, lvl+1);
			dfslabels.push_back(u);
			levels.push_back(lvl);
		}
	}
}

void build_segtree(int l, int r, int x)
{
	if(l == r)
	{
		seg_tree[x] = l;
		return;
	}
	else
	{
		int m = (l+r)>>1;
		build_segtree(l, m, 2*x+1);
		build_segtree(m+1, r, 2*x+2);

		if(levels[seg_tree[2*x+1]]<levels[seg_tree[2*x+2]])
			seg_tree[x] = seg_tree[2*x+1];
		else
			seg_tree[x] = seg_tree[2*x+2];
	}
}

void precalculate2()
{
	// auto start = high_resolution_clock::now(); 
	
	vis.clear();
	vis.resize(N+1, false);

	dfslabels.clear();	
	levels.clear();

	first_occurence.clear();
	first_occurence.resize(N+1,-1);

	dfs(1,1);

	for(int n = 0; n<dfslabels.size(); n++)
		if(first_occurence[dfslabels[n]] == -1)
			first_occurence[dfslabels[n]] = n;

	int last_visited_idx = 0;
	int last_visited;
	for(auto it: first_occurence)
		if(it > last_visited_idx)
			last_visited_idx = it;

	last_visited = dfslabels[last_visited_idx];

	// auto stop = high_resolution_clock::now(); 
	// auto duration = duration_cast<milliseconds>(stop - start); 
 //    cout << "Time taken by dfs and misc: "<< duration.count() << " milliseconds" << endl; 

    // start = high_resolution_clock::now(); 
	sz = last_visited_idx+1;
	seg_tree.clear();
	seg_tree.resize(4*sz, 0);

	build_segtree(0, sz-1, 0);
	// stop = high_resolution_clock::now(); 
	// duration = duration_cast<milliseconds>(stop - start); 
 //    cout << "Time taken by segment tree: "<< duration.count() << " milliseconds" << endl; 


    // start = high_resolution_clock::now(); 
	vis.clear();
	vis.resize(N+1, false);

	root_answers.clear();
	root_answers.resize(N+1);

	factors.clear();

	path(1, last_visited);

	// stop = high_resolution_clock::now(); 
	// duration = duration_cast<milliseconds>(stop - start); 
 //    cout << "Time taken by precalculating answers: "<< duration.count() << " milliseconds" << endl; 

}

int query(int l, int r, int a, int b, int x)
{
	if(l > r || a>r || b<l)
		return -1;

	if(a<=l && b>=r)
		return seg_tree[x];

	int m = (l+r)>>1;
	int u = query(l,m,a,b,2*x+1);
	int v = query(m+1,r,a,b,2*x+2);

	if(u!=-1 && v!=-1)
	{
		if(levels[u]<levels[v])
			return u;
		return v;
	}
	if(u!=-1)
		return u;
	return v;
}

int lca(int u, int v)
{
	int a = first_occurence[u], b = first_occurence[v];
	if(a>b)
	{
		a += b;
		b = a-b;
		a -= b;
	}
	return dfslabels[query(0, sz-1, a, b, 0)];
}

void get_answer(int u, int v)
{
	int l = lca(u,v);
	for(auto it: root_answers[u])
		factors[it.first] += it.second;
	for(auto it: root_answers[v])
		factors[it.first] += it.second;
	inc_factors(A[l]);
	for(auto it: root_answers[l])
		factors[it.first] -= 2*it.second;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // auto begin = high_resolution_clock::now(); 
	int T,Q;
	cin>>T;
	// auto start = high_resolution_clock::now(); 
	precalculate1();
	// auto stop = high_resolution_clock::now(); 
	// auto duration = duration_cast<milliseconds>(stop - start); 
 //    cout << "Time taken by precalculate1: "<< duration.count() << " milliseconds" << endl; 
	while(T--)
	{
		// start = high_resolution_clock::now(); 
		cin>>N;

		g.clear();
		g.resize(N+1);

		A.clear();
		A.resize(N+1);

		for(int n = 0; n<N-1; n++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int n = 1; n<=N; n++)
			cin>>A[n];
		// stop = high_resolution_clock::now(); 
		// duration = duration_cast<milliseconds>(stop - start); 
	 //    cout << "Time taken by input: "<< duration.count() << " milliseconds" << endl; 


		// start = high_resolution_clock::now(); 
		precalculate2();
		// stop = high_resolution_clock::now(); 
		// duration = duration_cast<milliseconds>(stop - start); 
	    // cout << "Time taken by precalculate2: "<< duration.count() << " milliseconds" << endl; 

	    // start = high_resolution_clock::now(); 
		cin>>Q;
		while(Q--)
		{
			int u,v;
			cin>>u>>v;
			factors.clear();
			get_answer(u,v);
			int ans = 1;
			for(auto it: factors)
				ans = (ans * (it.second+1))%MOD;
			cout<<ans<<"\n";
		}
		// stop = high_resolution_clock::now(); 
		// duration = duration_cast<milliseconds>(stop - start); 
	 //    cout << "Time taken by querying: "<< duration.count() << " milliseconds" << endl; 
	}
	// auto end = high_resolution_clock::now(); 
	// auto total = duration_cast<seconds>(end - begin); 
 //    cout << "Time taken by program: "<< total.count() << " seconds" << endl; 
	return 0;
}