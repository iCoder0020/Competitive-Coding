/*
ID: icoder_0020
PROG: Breakup App
LANG: C++                  
*/

#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;

#define MAX_LENGTH 1000

int toi(string S)
{
	int num = 0;
	for(int i = 0; i<S.length(); i++)
	{
		num = 10*num + (int)(S[i]) - 48;
	}
	return num;
}

int main()
{
	int N;
	cin>>N;
	int weight[31] = {0};
	N++;
	while(N--)
	{
		char S[MAX_LENGTH];
		string temp = "";
		scanf("%[^\n]", S);
		getchar();
		for(int i = 0; S[i]!='\0'; i++)
		{
			while(S[i]!='\0' && (int)(S[i])>=48 && (int)(S[i])<=57)
			{
				temp += S[i];
				i++;
			}
			int day = toi(temp);
			if(day >=1 && day<=30)
			{
				if(S[0] == 'G')
				{
					weight[day] += 2;
				}
				else
				{
					weight[day]++;
				}
			} 
			temp = "";
		}
	}
	int w_19 = weight[19];
	int w_20 = weight[20];
	sort(weight, weight+31);
	if(weight[29] == weight[30])
	{
		cout<<"No Date"<<endl;
	}
	else
	{
		if(weight[30] > w_19 && weight[30] > w_20)
		{
			cout<<"No Date"<<endl;
		}
		else
		{
			cout<<"Date"<<endl;
		}
	}
	return 0;
}
