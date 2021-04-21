#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pos(i,t) (60*i+(V[i]*(t)))

int r(int a, int b)
{
	return a+rand()%(b-a+1);
}

int32_t main()
{
	srand(time(NULL));
	int TC = r(10,20);
	cout<<TC<<endl;
	while(TC--)
	{
		int N = r(3,5);
		cout<<N<<endl;
		for(int n = 0; n<N; n++)
			cout<<r(0,5)<<" ";
		cout<<endl;
	}
	return 0;
}