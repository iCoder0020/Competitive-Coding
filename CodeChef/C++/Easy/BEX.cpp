/*
ID: ishan_sang
PROG: BEX
LANG: C++                  
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
struct book
{
    int exercises_left;
    string name;
    book *below;    
};
 
book *top = new book;
 
void stack_push(int N, string str)
{
    book *temp = new book;
    temp->exercises_left = N;
    temp->name = str;
    temp->below = top;
    top = temp;
}
 
void stack_pop()
{
    book *temp = new book;
    book *temp2 = new book;
    temp = top;
    int min = temp->exercises_left;
    string S;
    while(temp->exercises_left != -2)
    {
        if(temp->exercises_left<min)
        {
            min = temp->exercises_left;
        }
        temp = temp->below;
    }
    temp = top;
    int count = 0;
    while(temp->exercises_left != min)
    {
        temp = temp->below;
        count++;
    }
    cout<<count<<" "<<temp->name<<"\n";
    temp = top;
    if(temp->exercises_left == min)
    {
        top = temp->below;
        delete temp;
    }
    else
    {
        while(temp->below->exercises_left != min)
        {   
            temp = temp->below;
        }
        temp2 = temp->below;
        temp->below = temp->below->below;
        delete temp2;
    }
}
 
int main()
{
    int N;
    int num;
    string s;
    cin>>N;
    top->exercises_left = -2;
    top->name = "NONE";
    top->below = NULL;
    for(int n = 0; n<N; n++)
    {
        cin>>num;
        if(num != -1)
        {
            cin>>s;
            stack_push(num, s);
        }
        else
        {
            stack_pop();
        }
    }
    return 0;
} 