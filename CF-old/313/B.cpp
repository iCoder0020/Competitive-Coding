#include <bits/stdc++.h>

using namespace std;

#define int long long

string lexismall(string A)
{
	int a = A.length();
	if(a&1)
		return A;
	string A1 = lexismall(A.substr(0, a/2));
	string A2 = lexismall(A.substr(a/2, a/2));
	if(A1<A2)
		return A1+A2;
	return A2+A1;
}

int32_t main()
{
	string A,B;
	cin>>A>>B;
	string X = lexismall(A);
	string Y = lexismall(B);
	if(X == Y)
		cout<<"YES";
	else
		cout<<"NO";
	cout<<endl;
	return 0;
}
