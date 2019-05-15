/*
ID: iCoder0020
PROG: Gourmet Cat
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int max_poss(int A, int B, int C)
{
	int temp_A, temp_B, temp_C;
	temp_A = ((A-1)/3)*7;
	temp_B = ((B-1)/2)*7;
	temp_C = ((C-1)/2)*7;

	if(A%3 == 0)
		temp_A+=7;
	else if(A%3 == 1)
		temp_A+=3;
	else
		temp_A+=6;


	if(B%2 == 0)
		temp_B+=8;
	else
		temp_B+=5;

	if(C%2 == 0)
		temp_C+=9;
	else
		temp_C+=4;

		// cout<<temp_A<<" "<<temp_B<<" "<<temp_C<<endl;

	return min(temp_A, min(temp_B, temp_C));
}

int32_t main()
{
	int A,B,C;
	int ans = INT_MAX;
	int max_ans = 0;
	int days[7] = {0};
	cin>>A>>B>>C;
	for(int n = 0; n<7; n++)
	{
		switch(n)
		{
			case 0:
			days[n] = max_poss(A, B, C);
			break;

			case 1:
			days[n] = max_poss(A+1, B, C);
			break;

			case 2:
			days[n] = max_poss(A+1, B+1, C);
			break;

			case 3:
			days[n] = max_poss(A+1, B+1, C+1);
			break;

			case 4:
			days[n] = max_poss(A+2, B+1, C+1);
			break;

			case 5:
			days[n] = max_poss(A+2, B+1, C+2);
			break;

			case 6:
			days[n] = max_poss(A+2, B+2, C+2);
			break;
		}
		days[n] -= n;
		// cout<<n<<" "<<days[n]<<endl;
		max_ans = max(max_ans, days[n]);
	}
	cout<<max_ans<<endl;
	return 0;
}