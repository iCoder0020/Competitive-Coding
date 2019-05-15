/*
ID: iCoder0020
PROG: Two Teams
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

struct member
{
	int pos;
	int skill;
	int team;
	member *l;
	member *r;

	member(int p, int s)
	{
		pos = p;
		skill = s;
		team = -1;
		l = NULL;
		r = NULL;
	}
};

bool comp(member *A, member *B)
{
	return A->skill > B->skill;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N,K,k;
	cin>>N>>K;
	int temp;
	member* A[N];
	set <member*> visited;
	map<member*, bool> vis;
	for(int n = 0; n<N; n++)
	{
		cin>>temp;
		A[n] = new member(n, temp);
		vis[A[n]] = false;
	}
	for(int n = 0; n<N; n++)
	{
		if(n > 0)
			A[n]->l = A[n-1];
		if(n < N-1)
			A[n]->r = A[n+1];
	}
	sort(A, A+N, comp);
	int idx = 0;
	int t = 1;
	while(visited.size()!=N)
	{
		member *top, *temp;
		do
		{
			top = A[idx];
			idx++;
		}while(vis[top]);

		vis[top] = true;
		visited.insert(top);
		top->team = t;

		temp = top;

		k = K;
		while(temp->l && k)
		{
			temp = temp->l;
			if(vis[temp] == false)
			{
				temp->team = t;
				vis[temp] = true;
				visited.insert(temp);
				k--;
			}
			temp->r->l = temp->l;
		}

		temp = top;

		k = K;
		while(temp->r && k)
		{
			temp = temp->r;
			if(vis[temp] == false)
			{
				temp->team = t;
				vis[temp] = true;
				visited.insert(temp);
				k--;
			}
			temp->l->r = temp->r;
		}
		t = 3-t;
	}
	int B[N];
	for(int n = 0; n<N; n++)
		B[A[n]->pos] = A[n]->team;
	for(int n = 0; n<N; n++)
		cout<<B[n];
	cout<<endl;
	return 0;
}