/*
ID: ishan-sang
PROG: Min Stack
LANG: C++                  
*/

stack<pair<int,int>>S;
int minm;
MinStack::MinStack() {
    while(!S.empty())
        S.pop();
    minm = INT_MAX;
}

void MinStack::push(int x) {
    if(x < minm)
        minm = x;
    S.push({x, minm});
}

void MinStack::pop() {
    if(!S.empty())
        S.pop();
    if(!S.empty())
        minm = S.top().second;
    else
        minm = INT_MAX;
}

int MinStack::top() {
    if(S.empty())
        return -1;
    return S.top().first;
    
}

int MinStack::getMin() {
    if(S.empty())
        return -1;
    return minm;
}

