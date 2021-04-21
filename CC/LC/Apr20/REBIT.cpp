#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 998244353

void AND(vector<int>&A, vector<int>&B, vector<int>&C)
{
	C.resize(5, 0);
	C[0] = (A[0]*B[0])%MOD + (A[0]*B[1])%MOD + (A[0]*B[2])%MOD + (A[0]*B[3])%MOD + (A[1]*B[0])%MOD + (A[2]*B[0])%MOD + (A[2]*B[3])%MOD + (A[3]*B[0])%MOD + (A[3]*B[2])%MOD;
	C[1] = (A[1]*B[1])%MOD;
	C[2] = (A[1]*B[2])%MOD + (A[2]*B[1])%MOD + (A[2]*B[2])%MOD;
	C[3] = (A[1]*B[3])%MOD + (A[3]*B[1])%MOD + (A[3]*B[3])%MOD;
	// C[4] = max(A[4], B[4])+1;
	C[4] = A[4]+B[4];
	for(int i = 0; i<4; i++)
		C[i] = C[i]%MOD;
}

void OR(vector<int>&A, vector<int>&B, vector<int>&C)
{
	C.resize(5, 0);
	C[0] = (A[0]*B[0])%MOD;
	C[1] = (A[0]*B[1])%MOD + (A[1]*B[0])%MOD + (A[1]*B[1])%MOD + (A[1]*B[2])%MOD + (A[1]*B[3])%MOD + (A[2]*B[1])%MOD + (A[2]*B[3])%MOD + (A[3]*B[1])%MOD + (A[3]*B[2])%MOD;
	C[2] = (A[0]*B[2])%MOD + (A[2]*B[0])%MOD + (A[2]*B[2])%MOD;
	C[3] = (A[0]*B[3])%MOD + (A[3]*B[0])%MOD + (A[3]*B[3])%MOD;
	// C[4] = max(A[4], B[4])+1;
	C[4] = A[4]+B[4];
	for(int i = 0; i<4; i++)
		C[i] = C[i]%MOD;
}

void XOR(vector<int>&A, vector<int>&B, vector<int>&C)
{
	C.resize(5, 0);
	C[0] = (A[0]*B[0])%MOD + (A[1]*B[1])%MOD + (A[2]*B[2])%MOD + (A[3]*B[3])%MOD;
	C[1] = (A[0]*B[1])%MOD + (A[1]*B[0])%MOD + (A[2]*B[3])%MOD + (A[3]*B[2])%MOD;
	C[2] = (A[0]*B[2])%MOD + (A[1]*B[3])%MOD + (A[2]*B[0])%MOD + (A[3]*B[1])%MOD;
	C[3] = (A[0]*B[3])%MOD + (A[1]*B[2])%MOD + (A[2]*B[1])%MOD + (A[3]*B[0])%MOD;
	// C[4] = max(A[4], B[4])+1;
	C[4] = A[4]+B[4];
	for(int i = 0; i<4; i++)
		C[i] = C[i]%MOD;
}

int modpower(int A, int B, int C)
{
	if(A == 0  || B == 1)
		return A;
	if(A == 1 || B == 0)
		return 1;
	int D = modpower(A,B/2,C);
	if(B&1)
		return (((A*D)%C)*D)%C;
	return (D*D)%C;
}

int modinverse(int A, int B)
{
	return modpower(A, B-2, B);
}

void trial()
{
	vector<int>a,b,c,d,e;
	a = {1,1,1,1,1};
	b = {1,9,3,3,2};
	OR(a,b,c);
	// XOR(a,b,c);
	for(auto it: c)
		cout<<it<<" ";
	cout<<endl;
	// int x = 3;
	// int y = 12;
	// cout<<(x*modinverse(y,MOD))%MOD<<endl;
}

int32_t main()
{
	int T;
	cin>>T;
	// T =  0;
	// trial();
	while(T--)
	{
		string L;
		cin>>L;
		stack<vector<int>>val;
		stack<char>symbol;
		for(auto it: L)
		{
			if(it == '(')
				continue;
			else if(it == ')')
			{
				vector<int> b = val.top();
				val.pop();
				vector<int> a = val.top();
				val.pop();
				char s = symbol.top();
				symbol.pop();
				vector<int> c;
				switch(s)
				{
					case '&':
						AND(a,b,c);
						break;
					case '|':
						OR(a,b,c);
						break;
					case '^':
						XOR(a,b,c);
						break;
					default:
						cout<<"INVALID"<<endl;
				}
				val.push(c);
				// for(auto it: val.top())
				// 	cout<<it<<" ";
				// cout<<endl;
			}
			else if(it == '#')
				val.push({1,1,1,1,1});
			else
				symbol.push(it);
		}
		vector<int> v = val.top();
		int num[4] = {v[0], v[1], v[2], v[3]};
		int d = modpower(4,v[4],MOD);
		int den[4] = {d,d,d,d};
		for(int i = 0; i<4; i++)
		{
			// cout<<num[i]<<"/"<<den[i]<<endl;
			cout<<(num[i]*modinverse(den[i],MOD))%MOD<<" ";
		}
		cout<<endl;
	}
	return 0;
}