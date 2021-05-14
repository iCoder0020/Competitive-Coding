#include <bits/stdc++.h>

using namespace std;

#define int long long

map<int,int>parent;
map<int,int>sz;
map<int,char>ans;

void make_set(int v)
{
	parent[v] = v;
	sz[v] = 1;
}

int find_set(int v)
{
	if(v == parent[v])
		return v;
	return find_set(parent[v]);
}

void union_set(int a, int b)
{
	a = parent[a];
	b = parent[b];
	if(a!=b)
	{
		parent[b] = a;
		sz[a] += sz[b];
	}
}

int32_t main()
{
	string S;
	cin>>S;
	int N = S.length();
	vector<bool>primes(N+1,true);
	primes[0] = primes[1] = false;
	for(int i = 1; i<=N; i++)
		make_set(i);
	for(int i = 2; i<=N; i++)
	{
		if(!primes[i])
			continue;
		for(int j = 2; i*j<=N; j++)
		{
			if(find_set(i*j) == (i*j))
				union_set(i,i*j);
			if(find_set(i*j) != i)
				union_set(parent[i*j], i);
			// cout<<i*j<<" "<<parent[i*j]<<" "<<sz[parent[i*j]]<<endl;
			primes[i*j] = false;
		}
	}
	vector<int>char_freq(26, 0);
	for(auto it: S)
		char_freq[it-'a']++;
	// sort(reqd.begin(), reqd.end(), greater<int>());
	bool poss = true;
	for(int n = 0; n<=N; n++)
	{
		if(!primes[n])
			continue;
		if(find_set(n)!=n)
			continue;
		int maxm = 0, maxm_index = 0;
		for(int n = 0; n<26; n++)
		{
			if(maxm<char_freq[n])
			{
				maxm = char_freq[n];
				maxm_index = n;
			}
		}
		// cout<<n<<" "<<sz[n]<<endl;
		if(sz[n]>maxm)
		{
			poss = false;
			break;
		}
		char_freq[maxm_index] -= sz[n];
		ans[n] = maxm_index+'a';
		// cout<<n<<" "<<ans[n]<<endl;
	}
	if(!poss)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	char x;
	for(int n = 0; n<26; n++)
		if(char_freq[n] == 1)
			x = n+'a';
	vector<char>out(N+1, x);
	for(int n = 2; n<=N; n++)
	{
		out[n] = ans[find_set(n)];
	}
	for(int i = 1; i<=N; i++)
		cout<<out[i];
	cout<<endl;
	return 0;
}
