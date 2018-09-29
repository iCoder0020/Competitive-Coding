/*
ID: ishan_sang
PROG: CHEFPDIG
LANG: C++
*/

#include <iostream>

using namespace std;

int T;
int i,go_ahead;
int num_state[10];
string s;

void reset()
{
	for(int i=0;i<10;i++)
	{
		num_state[i]=0;
	}
	go_ahead=1;
}

void mark_num()
{
	for(int i=0;s[i]!='\0';i++)
	{
		num_state[int(s[i])-48]++;
	}
}

void print_possible_letters()
{
	if(num_state[6]&&num_state[5])
	{
		cout<<'A';
	}
	if(num_state[6]>=2)
	{
		cout<<'B';
	}
	if(num_state[6]&&num_state[7])
	{
		cout<<'C';
	}
	if(num_state[6]&&num_state[8])
	{
		cout<<'D';
	}
	if(num_state[6]&&num_state[9])
	{
		cout<<'E';
	}
	if(num_state[7]&&num_state[0])
	{
		cout<<'F';
	}
	if(num_state[7]&&num_state[1])
	{
		cout<<'G';
	}
	if(num_state[7]&&num_state[2])
	{
		cout<<'H';
	}
	if(num_state[7]&&num_state[3])
	{
		cout<<'I';
	}
	if(num_state[7]&&num_state[4])
	{
		cout<<'J';
	}
	if(num_state[7]&&num_state[5])
	{
		cout<<'K';
	}
	if(num_state[7]&&num_state[6])
	{
		cout<<'L';
	}
	if(num_state[7]>=2)
	{
		cout<<'M';
	}
	if(num_state[7]&&num_state[8])
	{
		cout<<'N';
	}
	if(num_state[7]&&num_state[9])
	{
		cout<<'O';
	}
	if(num_state[8]&&num_state[0])
	{
		cout<<'P';
	}
	if(num_state[8]&&num_state[1])
	{
		cout<<'Q';
	}
	if(num_state[8]&&num_state[2])
	{
		cout<<'R';
	}
	if(num_state[8]&&num_state[3])
	{
		cout<<'S';
	}
	if(num_state[8]&&num_state[4])
	{
		cout<<'T';
	}
	if(num_state[8]&&num_state[5])
	{
		cout<<'U';
	}
	if(num_state[8]&&num_state[6])
	{
		cout<<'V';
	}
	if(num_state[8]&&num_state[7])
	{
		cout<<'W';
	}
	if(num_state[8]>=2)
	{
		cout<<'X';
	}
	if(num_state[8]&&num_state[9])
	{
		cout<<'Y';
	}
	if(num_state[9]&&num_state[0])
	{
		cout<<'Z';
	}
	cout<<"\n";
}

void run()
{
	cin>>T;
	for(i=0;i<T;i++)
	{
		reset();
		cin>>s;
		mark_num();
		print_possible_letters();	
	}
}

int main()
{
	run();
	return 0;
}
